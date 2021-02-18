#include "ft_printf.h"

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

// TODO defend all there handlers from malloc errors

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
	if (str == 0)
		if ((spec.accuracy >= 6) || (spec.accuracy == -1))
			str = "(null)";
		else
			str = "";
	str_len = ft_strlen(str);
	if ((spec.accuracy < str_len) && (spec.accuracy != -1))
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
	
	str = ft_str_add_accuracy(ap, spec, str);
	return (ft_handler_str(ap, spec, &str, 0));
}

int		ft_handler_p(va_list ap, t_spec spec)
{
	unsigned long long nbr;
	char *str;

	spec.accuracy = -1;
	nbr = va_arg(ap, unsigned long long);
	if (nbr == 0)
		str = ft_strdup("(nil)");
	else
		str = ft_itoa_p(nbr, 16);
	
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
	minus = ft_minus(&nbr);
	if ((nbr == 0) && (spec.accuracy != -1))
		str = ft_strdup("");
	else
		str = ft_itoa_u(nbr, 10 , 0);

	str = ft_str_add_accuracy(ap, spec, str);
	return (ft_handler_str(ap, spec, &str, minus));
}

// util

int		ft_minus(int *nbr)
{
	if (*nbr < 0)
	{
		*nbr *= -1;
		return (1);
	}
	return (0);
}

char	*ft_str_acc(int i, int j, char **str)
{
	int k;
	char *new_str;
	char *tmp;

	k = 0;
	new_str = malloc((sizeof(char) * j));
	while (i--)
		new_str[k++] = '0';
	tmp = new_str;
	new_str = ft_strjoin(new_str, *str);
	free(tmp);
	// ! Do i need this ? i have error #1 because of this
	// if (**str != '\0')
	// 	free(*str);
	return (new_str);
}

char	*ft_str_add_accuracy(va_list ap, t_spec spec, char *nbr_str)
{
	int nbr_len;		// length of number
	char *tmp;

	nbr_len = ft_strlen(nbr_str);
	if (spec.accuracy > nbr_len)
		nbr_str = ft_str_acc(spec.accuracy - nbr_len, spec.accuracy, &nbr_str);
	return (nbr_str);
}

// end util

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

// ! DEFEND LEAKS ALL (if no mem at heap also)

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
