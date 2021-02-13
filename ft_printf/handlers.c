#include "ft_printf.h"

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
	if (spec.accuracy < str_len)
		str_len = spec.accuracy;
	if (spec.flag == '-')
		ft_putstr_len(str_len, str);
	if (spec.width != 0)
		ft_print_char_times(spec.width - str_len, ' ');
	if (spec.flag != '-')
		ft_putstr_len(str_len, str);
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
