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

// ! DEFEND LEAKS ALL

int		ft_minus(int *nbr)
{
	if (*nbr < 0)
	{
		*nbr *= -1;
		return (1);
	}
	return (0);
}

char	*ft_str_make(int i, int j, char **str)
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
	free(*str);
	return (new_str);
}

char	*ft_nbr_to_str(va_list ap, t_spec spec, int nbr)
{
	int nbr_len;		// length of number
	char *nbr_str;		// same number but positive and written to string
	char *tmp;

	nbr_str = ft_itoa(nbr);
	nbr_len = ft_strlen(nbr_str);
	if (spec.accuracy > nbr_len)
		nbr_str = ft_str_make(spec.accuracy - nbr_len, spec.accuracy, &nbr_str);
	return (nbr_str);
}

int		ft_handler_d(va_list ap, t_spec spec)
{
	int str_len;
	int nbr;
	int minus;
	char *str;

	nbr = va_arg(ap, int);
	minus = ft_minus(&nbr);
	str = ft_nbr_to_str(ap, spec, nbr);
	str_len = ft_strlen(str);

	// if ((spec.space == 1) || (minus == 1))
	// 	space = 1;
	
	// minus at begining
	if (minus == 1)
		str_len++;

	if (((minus == 1) && (spec.flag != '_')) || ((minus == 1) && (spec.width < str_len)))
		// str_len += ft_putchar('-');
		ft_putchar('-');
	// space
	if (((minus != 1) && (spec.width <= str_len) && (spec.space == 1)) ||
	((spec.space == 1) && (spec.flag != '_') && (minus != 1)))
		str_len += ft_putchar(' ');
	
	// main
	if (spec.width > str_len)
	{
 		if (spec.flag == '-')
			ft_putstr_len(str_len, str);
		if ((spec.flag == '0') && (spec.accuracy == -1))
			ft_print_char_times(spec.width - str_len, '0');
		else
			ft_print_char_times(spec.width - str_len, ' ');
		if ((minus == 1) && (spec.flag == '_'))
			str_len += ft_putchar('-'); // remove +=
		if (spec.flag != '-')
			ft_putstr_len(str_len, str);
	}
	else
	{
		// if (minus == 1) // ? do i need this
		// 	str_len += ft_putchar('-');
		ft_putstr_len(str_len, str);
	}

	free(str);
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
