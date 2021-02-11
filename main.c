#include "main.h"

size_t	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (*(str++))
		i++;
	return (i);
}

void	ft_init_spec(t_spec **spec)
{
	(*spec)->flag = '_';     // x -none '0'/'-'/' '
	(*spec)->space = 0;      
	(*spec)->width = 0;
	(*spec)->accuracy = -1;
	(*spec)->type = '_';     // char ex: d i u x X 
}

int		ft_flags_parser(const char **format, t_spec **spec)
{
	int len;
	len = 0;
	while ((ft_strchr("-0 ", **format)))
	{
		if ((**format == '-') && ((*spec)->flag != '-'))
			(*spec)->flag = **format;
		else if ((**format == '0') && ((*spec)->flag != '-'))
			(*spec)->flag = **format;
		else if ((**format == ' ') && ((*spec)->space != 1))
			(*spec)->space = 1;
		len++;
		(*format)++;
	}
	return (len);
}

int		ft_width_parser(va_list ap, const char **format, t_spec **spec)
{
	int len;
	int num;

	len = 0;
	num = 0;
	if (**format == '*')
		(*spec)->width = va_arg(ap, int);
	else if ((num = ft_atoi(*format)) != 0) // Можно в width просто класть результат атои сразу
		(*spec)->width = num;
	else
		return (0);
	if ((*spec)->width < 0)
	{
		(*spec)->flag = '-';
		(*spec)->width *= -1;
	}
	len += ft_get_nbr_len(num, 10);
	(*format) += len;
	return (len);
}

int		ft_zero_len(const char *format)
{
	int len;

	len = 0;
	while (*format == '0')
	{
		format++;
		len++;
	}
	return (len);
}

int		ft_accuracy_parser(va_list ap, const char **format, t_spec **spec)
{
	int len;
	int num;

	len = 0;
	if (**format == '.')
		if (*(++(*format)) == '*')
		{
			(*spec)->accuracy = va_arg(ap, int);
			len += 2; // 2 тк еще надо пропустить .
			(*format)--;
		}
		else
		{
			if ((num = ft_atoi(*format)) != 0)
				len++;
			(*spec)->accuracy = num;
			len += ft_get_nbr_len(num, 10) + ft_zero_len(*format); // + 1 тк еще надо пропустить .
			(*format)--;
		}
	// if ((*spec)->accuracy < 0)
	// {
	// 	(*spec)->flag = '-';
	// 	(*spec)->accuracy *= -1;
	// }
	(*format) += len;
	return(len);
}

int		ft_parser(va_list ap, const char *format, t_spec *spec)
{
	int len;
	
	ft_init_spec(&spec);
	len = ft_flags_parser(&format, &spec);
	len += ft_width_parser(ap, &format, &spec);
	len += ft_accuracy_parser(ap, &format, &spec);
	if (*format == '\0')
		return (0);
	if (ft_strchr("diucspxX%", *format))
		spec->type = *format;
	else if ((*(format + 1)) == '\0')
		return (0);
	return ((spec->type == '_') ? (len + 1) : ((len + 1) * -1));
}

int		ft_putstr(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

int		ft_print_char_times(int i, char c)
{
	int len;

	len = i;
	while (i-- > 0)
		ft_putchar(c);
	return (len);
}

int		ft_handler_c(va_list ap, t_spec spec)
{
	if (spec.flag == '-')
		ft_putchar(va_arg(ap, int));
	if (spec.width != 0)
		ft_print_char_times(spec.width - 1, ' ');
	if (spec.flag != '-')
		ft_putchar(va_arg(ap, int));
	return ((spec.width != 0) ? spec.width : 1);
}

int		ft_handler_s(va_list ap, t_spec spec)
{
	char *str;
	int str_len;

	str = va_arg(ap, char*);
	str_len = ft_strlen(str);
	if (spec.flag == '-')
		ft_putstr(str);
	if (spec.width != 0)
		ft_print_char_times(spec.width - str_len, ' ');
	if (spec.flag != '-')
		ft_putstr(str);
	return ((str_len > spec.width) ? str_len : spec.width);
}

int		ft_handler_d(va_list ap, t_spec spec)
{
	int len;
	int nbr;
	int nbr_len;

	len = 0;
	nbr = va_arg(ap, int);
	nbr_len = ft_get_nbr_len(nbr, 10);
	if (spec.accuracy >= nbr_len)
	{
		spec.width = spec.accuracy;
		spec.flag = '0';
		spec.width++;
	}
	if ((spec.space == 1) && !(nbr < 0))
	{
		spec.width--;
		len += ft_putchar(' ');
	}
	if ((nbr < 0) && (spec.flag != '_'))
		nbr *= -ft_putchar('-');
	if (spec.width > nbr_len)
	{
		if (spec.flag == '-')
			ft_putnbr(nbr);
		if (spec.flag == '0')
			len += ft_print_char_times(spec.width - nbr_len, '0');
		else
			len += ft_print_char_times(spec.width - nbr_len, ' ');
		if (spec.flag != '-')
			ft_putnbr(nbr);
	}
	else
		ft_putnbr(nbr);
	len += nbr_len;
	return (len);
}

int		ft_handler(va_list ap, t_spec spec)
{
	if (spec.type == 'c') // done
		return (ft_handler_c(ap, spec));
	if (spec.type == 's') // done
		return (ft_handler_s(ap, spec));
	if ((spec.type == 'd') || (spec.type == 'i')) // in progress
		return (ft_handler_d(ap, spec));
	if (spec.type == '%')
		return (ft_putchar('%'));
	return (0);
}

int		ft_format_out(const char **format, t_spec spec)
{
	int len;

	len = ft_putchar('%');
	if (**format == ' ')
		len += ft_putchar(' ');
	while (**format == ' ')
		(*format)++;
	while (**format != '\0')
	{
		if (**format == '*')
		{
			ft_putnbr(spec.width);
			len += ft_get_nbr_len(spec.width, 10);
		}
		else if ((**format == '.') && (*(++(*format)) == '*'))
		{
			ft_putchar('.');
			ft_putnbr(spec.accuracy);
			len += ft_get_nbr_len(spec.accuracy, 10) + 1;
		}
		else
			len += ft_putchar(**format);
		(*format)++;
	}
	return (len);
}

int		ft_handler_ap(va_list ap, const char **format)
{
	int len;
	int parse;
	t_spec spec;

	len = 0;
	parse = ft_parser(ap, ++(*format), &spec);

	if (parse == 0)
		return (-1);
	else if (parse < 0)
		len += ft_handler(ap, spec);
	else if (parse > 0)
		len += ft_format_out(format, spec);

	if (parse < 0)
		parse *= -1;
	else if (parse > 0)
		return (len);
	(*format) += parse;
	return (len);
}

int		ft_print_all(va_list ap, const char *format)
{
	int len;
	int tmp;

	len = 0;
	while (*format)
		if ((*format == '%'))
			if ((*(format + 1) == '\0') || ((tmp = ft_handler_ap(ap, &format)) == -1))
				return (-1);
			else 
				len += tmp;
		else
			len += ft_putchar(*(format++));
	return (len);
}

int		ft_printf(const char *format, ...)
{
    va_list ap;
	int len;

	if (!format)
		return (-1);
	va_start(ap, format);
	len = ft_print_all(ap, format);
	va_end(ap);
	return (len);
}

void	ft_test(char *str)
{
	int i = 0;
	int j = 0;

	printf("\n");

	// my
	i = ft_printf(str, 2, 3);
	printf(" | RETURN: %d", i);
	printf("\n");

	// standart
	j = printf(str, 2, 3);
	printf(" | RETURN: %d", j);
	printf("\n");

	printf("\n");
}

int		main(void)
{
	// old tests
	// ft_test("%");
	// ft_test("%%");
	// ft_test("%%%");
	// ft_test("%d");
	// ft_test("%z");
	// ft_test("%z 123");
	// ft_test("test %d");
	// ft_test("% d 123");
	// ft_test("%       d 123");
	// ft_test("%  0-  12d");
	// ft_test("%.d");
	// ft_test("%.0d");
	// ft_test("%.2d");
	// ft_test("%.22d");
	// ft_test("%.0000012d");
	// ft_test("%.*d");

	// c - char tests
	// ft_test("%c");
	// ft_test("%     c");
	// ft_test("%    -0-0-0 0- c");
	// ft_test("%   10c");
	// ft_test("%   -10c");
	// ft_test("%*c");
	// ft_test("%10c");
	// ft_test("%-10c");

	// s - string tests
	// ft_test("%s");
	// ft_test("%10s");
	// ft_test("%1s");
	// ft_test("%-*s");
	// ft_test("%*s");

	// d - d an i tests
	// ft_test("%*d");
	// ft_test("% *d");
	// ft_test("% -0*d");
	// ft_test("% 1d");
	// ft_test("%      0  2d");
	// ft_test("%-4d");
	// ft_test("%d");

	// accuracy ft fixing
	// ft_test("%.d");
	// ft_test("%.0d");
	// ft_test("%.0000d");
	// ft_test("%.003d");
	// ft_test("%.3d");
	ft_test("%123");
	// ft_test("%.*d");

    return (0);
}
