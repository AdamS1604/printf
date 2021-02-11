#include "main.h"

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
	// TODO: Optimise this code
	if (**format == '*')
	{
		(*spec)->width = va_arg(ap, int);
		len += 1;
	}
	else if ((num = ft_atoi(*format)) != 0) // Можно в width просто класть результат атои сразу
		(*spec)->width = num;
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
	// TODO: optimise code
	if (**format == '.')
		if (*(++(*format)) == '*')
		{
			(*spec)->accuracy = va_arg(ap, int);
			len += 2; // 2 тк еще надо пропустить .
			(*format)--;
		}
		else
		{
			num = ft_atoi(*format);
			(*spec)->accuracy = num;
			len += ft_get_nbr_len(num, 10) + ft_zero_len(*format) + 1; // + 1 тк еще надо пропустить .
			(*format)--;
		}
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
	if (ft_strchr("diucspxX%", *format))
		spec->type = *format;
	else if ((*(format + 1)) == '\0')
		return (0);
	return ((spec->type == '_') ? (len + 1) : ((len + 1) * -1));
}

void	ft_print_space(int i)
{
	while (i > 0)
	{
		ft_putchar(' ');
		i--;
	}
}

int		ft_handler_c(va_list ap, t_spec spec)
{
	if (spec.flag == '-')
		ft_putchar(va_arg(ap, int));
	if (spec.width != 0)
		ft_print_space(spec.width - 1);
	if (spec.flag != '-')
		ft_putchar(va_arg(ap, int));
	return ((spec.width != 0) ? spec.width : 1);
}

int		ft_handler(va_list ap, t_spec spec)
{
	if (spec.type == 'c') // TODO:
		return (ft_handler_c(ap, spec));
	if ((spec.type == 'd') || (spec.type == 'i'))
		return (ft_putnbr_di(ap));
	if (spec.type == '%')
		return (ft_putchar('%'));
	return (0);
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
		len += ft_putchar('%') + parse - 1;

	if (parse < 0)
		parse *= -1;
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
	i = ft_printf(str, 10,'a');
	printf(" | RETURN: %d", i);
	printf("\n");

	// standart
	j = printf(str, 10,'a');
	printf(" | RETURN: %d", j);
	printf("\n");

	printf("\n");
}

int		main(void)
{
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
	ft_test("%   -*c");

    return (0);
}