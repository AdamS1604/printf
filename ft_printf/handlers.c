#include "ft_printf.h"

// handler controller
int		ft_handler_hub(va_list ap, t_spec spec)
{
	if (spec.type == 'c') 
		return (ft_handler_c(ap, spec)); //done
	if (spec.type == 's') 
		return (ft_handler_s(ap, spec)); //done
	if (spec.type == 'u')
		return (ft_handler_u(ap, spec));
	if (spec.type == 'p')
		return (ft_handler_p(ap, spec));
	if ((spec.type == 'x') || (spec.type == 'X'))
		return (ft_handler_xX(ap, spec));
	if ((spec.type == 'd') || (spec.type == 'i'))
		return (ft_handler_di(ap, spec));
	//! Threat this different? just identify this as invalid flag
	if (spec.type == '%')
		return (ft_putchar('%'));
	return (0);
}

// ALL HANDLERS

// GOOD
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

// GOOD
int		ft_handler_s(va_list ap, t_spec spec)
{
	char *str;
	int str_len;

	str = va_arg(ap, char*);
	if (str == 0)
		if ((spec.accuracy >= 6) || (spec.accuracy == -1))
			str = "(null)";
		else
			str = "";
	str_len = ft_strlen(str);
	if ((spec.accuracy < str_len) && (spec.accuracy > -1))
		str_len = spec.accuracy;
	if (spec.flag == '-')
		ft_putstr_len(str_len, str);
	if (spec.width != 0)
		ft_print_char_times(spec.width - str_len, ' ');
	if (spec.flag != '-')
		ft_putstr_len(str_len, str);
	return ((str_len > spec.width) ? str_len : spec.width);
}

int		ft_handler_u(va_list ap, t_spec spec)
{
	unsigned int nbr;
	char *str;

	nbr = va_arg(ap, unsigned int);
	if ((nbr == 0) && (spec.accuracy != -1))
		str = ft_strdup("");
	else
		str = ft_itoa_u(nbr, 10, 0);
	
	if (str == 0)
		return (-1);
	
	if (!(str = ft_str_add_accuracy(ap, spec, str)))
		return (-1);
	else
		return (ft_handler_str(ap, spec, &str, 0));
}

int		ft_handler_p(va_list ap, t_spec spec)
{
	unsigned long long nbr;
	char *str;
	char *tmp;

	nbr = va_arg(ap, unsigned long long);
	if (nbr == 0)
		str = ft_strdup("(nil)");
	else
	{
		str = ft_itoa_ull(nbr, 16);
		str = ft_str_add_accuracy(ap, spec, str);
		tmp = str;
		str = ft_strjoin("0x", str);
		free(tmp);
	}
	return(ft_handler_str(ap, spec, &str, 0));
}

int		ft_handler_xX(va_list ap, t_spec spec)
{
	unsigned int nbr;
	int minus;
	char *str;

	nbr = va_arg(ap, unsigned int);
	if ((nbr == 0) && (spec.accuracy != -1))
		str = ft_strdup("");
	else
		if (spec.type == 'x')
			str = ft_itoa_u(nbr, 16, 0);
		else if (spec.type == 'X')
			str = ft_itoa_u(nbr, 16, 1);

	str = ft_str_add_accuracy(ap, spec, str);
	return (ft_handler_str(ap, spec, &str, 0));
}

int		ft_handler_di(va_list ap, t_spec spec)
{
	int nbr;
	int minus;
	char *str;

	nbr = va_arg(ap, int);
	minus = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		minus = 1;
	}
	if ((nbr == 0) && (spec.accuracy != -1))
		str = ft_strdup("");
	else
		str = ft_itoa_u(nbr, 10 , 0);

	str = ft_str_add_accuracy(ap, spec, str);
	return (ft_handler_str(ap, spec, &str, minus));
}

// todo corp this ft

// diupxX str hanler
int		ft_handler_str(va_list ap, t_spec spec, char **str, int minus)
{
	int str_len;
	str_len = ft_strlen(*str) + minus;

	// 0 flag and accuracy
	if ((spec.flag == '0') && (spec.accuracy > -1))
		spec.flag = '_';

	// minus at begining
	if (((minus == 1) && (spec.flag != '_')) || ((minus == 1) && (spec.width <= str_len)))
		ft_putchar('-');
	
	// space
	if (((minus != 1) && (spec.width <= str_len) && (spec.space == 1)) ||
	((spec.space == 1) && (spec.flag != '_') && (minus != 1)))
		str_len += ft_putchar(' ');
	
	// main
	if (spec.width > str_len)
	{
 		if (spec.flag == '-')
			ft_putstr_len(str_len, *str);
		if ((spec.flag == '0') && (spec.accuracy < 0))
			ft_print_char_times(spec.width - str_len, '0');
		else
			ft_print_char_times(spec.width - str_len, ' ');
		// minus at the end
		if ((minus == 1) && (spec.flag == '_'))
			ft_putchar('-');
		if (spec.flag != '-')
			ft_putstr_len(str_len, *str);
	}
	else
		ft_putstr_len(str_len, *str);

	free(*str);
	return ((str_len > spec.width) ? str_len : spec.width);
}

//TODO BETTER FT FORMAT WRITE
//TODO CORP FT FORMAT WRITE
//TODO TEST FT FORMAT

// int		ft_format_out(const char **format, t_spec spec)
// {
// 	int len;
//
// 	len = ft_putchar('%');
// 	if (**format == ' ')
// 		len += ft_putchar(' ');
// 	while (**format == ' ')
// 		(*format)++;
// 	while (**format != '\0')
// 	{
// 		if (**format == '*')
// 		{
// 			ft_putnbr(spec.width);
// 			len += ft_get_nbr_len(spec.width, 10);
// 		}
// 		else if ((**format == '.') && (*(++(*format)) == '*'))
// 		{
// 			ft_putchar('.');
// 			ft_putnbr(spec.accuracy);
// 			len += ft_get_nbr_len(spec.accuracy, 10) + 1;
// 		}
// 		else
// 			len += ft_putchar(**format);
// 		(*format)++;
// 	}
// 	return (len);
// }

int		ft_format_out(const char **format, t_spec spec)
{
	int len;
	int tmp;

	// % out 
	len = ft_putchar('%');

	// len + 1 for space
	if (**format == ' ')
		len += ft_putchar(' ');
	
	// skip spaces
	while (**format == ' ')
		(*format)++;
	
	//body
	while (**format != '\0')
	{
		if (**format == '*')
		{
			ft_putnbr(spec.width);
			len += ft_get_nbr_len(spec.width, 10);
		}
		else if (**format == '.')
		{
			// if (**format + 1) == \0 then out -1 dand exit , else if = - then out 0 then - and number
			if ((*((*format) + 1) == '*') || (*((*format) + 1) == '-'))
			{
				len += ft_putchar('.');
				if (*((*format) + 1) == '-')
				{
					len += ft_putchar('0');
				}
				ft_putnbr(spec.accuracy);
				tmp = ft_get_nbr_len(spec.accuracy, 10);
				len += tmp;
				(*format) += tmp;
			}
			else if (*((*format) + 1) == '\0')
				return (-1);
			else
				len += ft_putchar(**format);
		}
		else
			len += ft_putchar(**format);
		(*format)++;
	}
	return (len);
	return (0);
}