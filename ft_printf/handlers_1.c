/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 19:14:45 by abronn            #+#    #+#             */
/*   Updated: 2021/02/20 19:14:46 by abronn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	char	*str;
	int		str_len;

	str = va_arg(ap, char*);
	if (str == 0)
		if ((spec.accuracy >= 6) ||
		(spec.accuracy == -1) || (spec.accuracy < -1))
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
	unsigned int	nbr;
	char			*str;

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
		return (ft_num_str_out(ap, spec, &str, 0));
}

int		ft_util_dot_out(t_spec spec, const char **format)
{
	char	len;
	int		tmp;

	len = 0;
	if ((*((*format) + 1) == '*') || (*((*format) + 1) == '-'))
	{
		len += ft_putchar('.');
		if (*((*format) + 1) == '-')
			len += ft_putchar('0');
		ft_putnbr(spec.accuracy);
		tmp = ft_get_nbr_len(spec.accuracy, 10);
		len += tmp;
		(*format) += tmp;
	}
	else if (*((*format) + 1) == '\0')
		return (-1);
	else
		len += ft_putchar(**format);
	return (len);
}

int		ft_spec_out(const char **format, t_spec spec)
{
	int len;
	int tmp;

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
		else if (**format == '.')
			if ((tmp = ft_util_dot_out(spec, format)) == -1)
				return (-1);
			else
				len += tmp;
		else
			len += ft_putchar(**format);
		(*format)++;
	}
	return (len);
}
