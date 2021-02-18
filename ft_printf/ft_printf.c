#include "ft_printf.h"

int		ft_handler_ap(va_list ap, const char **format)
{
	int len;
	int parse;
	t_spec spec;

	parse = ft_parser(ap, ++(*format), &spec);

	// invalid flag and nothing more to output
	if (parse == 0)
		return (-1);
	// output invalid foramt
	else if (parse > 0)
		len = ft_format_out(format, spec);
	// output ap
	else if ((parse *= -1) > 0)
		// TODO should return -1 if malloc error
		len = ft_handler_hub(ap, spec); 
	
    // ? fix there
	// if (parse < 0)
	// 	parse *= -1;
	// else if (parse > 0)
	// 	return (len);
	(*format) += parse;
	// mallocs defence
	return ((len < 0) ? -1 : len);
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
