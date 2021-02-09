#include "main.h"

void	ft_init_spec(t_spec **spec)
{
	(*spec)->flag = 'x';     // x -none '0'/'-'/' '
	(*spec)->space = 0;      
	(*spec)->width = 0;
	(*spec)->accuracy = 0;
	(*spec)->type = '0';     // char ex: d i u x X
	(*spec)->valid = 0;
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
		(*format)++;
	}
	return (len);
}

int		ft_parser(const char *format, t_spec *spec)
{
	int len;
	format++;         // skip %
	ft_init_spec(&spec); // initialize spec

	len = ft_flags_parser(&format, &spec);
	// parse width
	// parse accuracy
	if (ft_strchr("diucspxX%", *format))
	{
		spec->type = *format;
		return (len + 1);
	}
	if ((*(format + 1)) == '\0')
		return (-1);
	else
		spec->valid = 1;
	return (len + 1); // + 1 cuz %
}

int		ft_handler(va_list ap, t_spec spec)
{
	int len;

	len = 0;
	if ((spec.type == 'd') || (spec.type == 'i'))
		len += ft_putnbr_di(ap);
	else if (spec.type == 1)
		len += ft_putchar('%');
	return (len);
}

int		ft_handler_ap(va_list ap, const char **format)
{
	int len;
	int parse;
	t_spec spec;

	len = 0;
	parse = ft_parser(*format, &spec);

	if (parse == -1)    // error
		return (-1);
	if (spec.valid == 1)
		len += ft_putchar('%') + parse - 1;
	else if (parse > 0)
		len += ft_handler(ap, spec);
	
	(*format) += parse + 1;
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
	char test_str[] = "test %z 123";

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