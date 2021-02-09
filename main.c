#include "main.h"

void	ft_init_spec(t_spec **spec)
{
	(*spec)->flag = 'x';     // x -none '0'/'-'/' '
	(*spec)->space = 0;      
	(*spec)->width = 0;
	(*spec)->accuracy = 0;
	(*spec)->type = '0';     // char ex: d i u x X
}

void ft_flags_parser(const char **format, t_spec **spec)
{
	while ((ft_strchr("-0 ", **format)))
	{
		if ((**format == '-') && ((*spec)->flag != '-'))
			(*spec)->flag = **format;
		else if ((**format == '0') && ((*spec)->flag != '-'))
			(*spec)->flag = **format;
		else if ((**format == ' ') && ((*spec)->space != 1))
			(*spec)->space = 1;
		(*format)++;
	}

}

void	ft_parser(const char **format, t_spec *spec)
{
	(*format)++;         // skip %
	ft_init_spec(&spec); // initialize spec

	ft_flags_parser(format, &spec);

	if (ft_strchr("diucspxX%", **format))
		spec->type = **format;
}

int		ft_handler_ap(va_list ap, const char **format)
{
	int len;
	t_spec spec;

	ft_parser(format, &spec);
	if ((spec.type == 'd') || (spec.type == 'i'))
		len += ft_putnbr_di(ap);
	else if (spec.type == 1)
		len += ft_putchar('%');

	if (**format != '\0')
		(*format)++;
	return (len);
}

int		ft_print_all(va_list ap, const char *format)
{
	int len;
	int tmp;

	len = 0;
	while (*format)
		if ((*format == '%'))
			//??? error handling how to do it here?
			if ((tmp = ft_handler_ap(ap, &format)) == -1)
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

int		main(void)
{
	int i = 0;
	int j = 0;
	char test_str[] = "test %d number";

	// my
    i = ft_printf(test_str, 1);
    printf(" | RETURN: %d", i);
	printf("\n");

	// standart
	j = printf(test_str, 1);
    printf(" | RETURN: %d", j);
	printf("\n");
    return (0);
}