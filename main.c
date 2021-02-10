#include "main.h"

void	ft_init_spec(t_spec **spec)
{
	(*spec)->flag = '_';     // x -none '0'/'-'/' '
	(*spec)->space = 0;      
	(*spec)->width = 0;
	(*spec)->accuracy = 0;
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

int		ft_parser(const char *format, t_spec *spec)
{
	int len;
	
	ft_init_spec(&spec);
	len = ft_flags_parser(&format, &spec);
	// parse width
	// parse accuracy
	if (ft_strchr("diucspxX%", *format))
		spec->type = *format;
	else if ((*(format + 1)) == '\0')
		return (0);
	return ((spec->type == '_') ? (len + 1) : ((len + 1) * -1));
}

int		ft_handler(va_list ap, t_spec spec)
{
	int len;

	len = 0;
	if ((spec.type == 'd') || (spec.type == 'i'))
		len += ft_putnbr_di(ap);
	else if (spec.type == '%')
		len += ft_putchar('%');
	return (len);
}

int		ft_handler_ap(va_list ap, const char **format)
{
	int len;
	int parse;
	t_spec spec;

	len = 0;
	parse = ft_parser(++(*format), &spec);

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

void ft_test(char *str)
{
	int i = 0;
	int j = 0;

	// my
	i = ft_printf(str, 556);
	printf(" | RETURN: %d", i);
	printf("\n");

	// standart
	j = printf(str, 556);
	printf(" | RETURN: %d", j);
	printf("\n");

	printf("\n");
}

int		main(void)
{
	ft_test("%");
	ft_test("%%");
	ft_test("%%%");
	ft_test("%d");
	ft_test("%z");
	ft_test("%z 123");
	ft_test("test %d");

    return (0);
}