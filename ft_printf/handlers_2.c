/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 19:14:48 by abronn            #+#    #+#             */
/*   Updated: 2021/02/20 20:07:45 by abronn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_handler_p(va_list ap, t_spec spec)
{
	unsigned long long	nbr;
	char				*str;
	char				*tmp;

	nbr = va_arg(ap, unsigned long long);
	if (nbr == 0)
		str = ft_strdup("(nil)");
	else
	{
		if (!(str = ft_str_add_accuracy(ap, spec, ft_itoa_ull(nbr, 16))))
			return (-1);
		tmp = str;
		str = ft_strjoin("0x", str);
		free(tmp);
	}
	if (!(str))
		return (-1);
	return (ft_num_str_out(spec, &str, 0));
}

int		ft_handler_x(va_list ap, t_spec spec)
{
	unsigned int	nbr;
	char			*str;

	nbr = va_arg(ap, unsigned int);
	if ((nbr == 0) && (spec.accuracy != -1))
		str = ft_strdup("");
	else
	{
		if (spec.type == 'x')
			str = ft_itoa_u(nbr, 16, 0);
		else if (spec.type == 'X')
			str = ft_itoa_u(nbr, 16, 1);
	}
	if (!(str))
		return (-1);
	if (!(str = ft_str_add_accuracy(ap, spec, str)))
		return (-1);
	else
		return (ft_num_str_out(spec, &str, 0));
}

int		ft_handler_d(va_list ap, t_spec spec)
{
	int		nbr;
	int		minus;
	char	*str;

	nbr = va_arg(ap, int);
	minus = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		minus = 1;
	}
	if ((nbr == 0) && (spec.accuracy > -1))
		str = ft_strdup("");
	else
		str = ft_itoa_u(nbr, 10, 0);
	if (!(str))
		return (-1);
	if (!(str = ft_str_add_accuracy(ap, spec, str)))
		return (-1);
	else
		return (ft_num_str_out(spec, &str, minus));
}

void	ft_util_width_out(t_spec spec, char *str, int str_len, int minus)
{
	if (spec.flag == '-')
		ft_putstr_len(str_len, str);
	if ((spec.flag == '0') && (spec.accuracy < 0))
		ft_print_char_times(spec.width - str_len, '0');
	else
		ft_print_char_times(spec.width - str_len, ' ');
	if ((minus == 1) && (spec.flag == '_'))
		ft_putchar('-');
	if (spec.flag != '-')
		ft_putstr_len(str_len, str);
}

int		ft_num_str_out(t_spec spec, char **str, int minus)
{
	int str_len;

	str_len = ft_strlen(*str) + minus;
	if ((spec.flag == '0') && (spec.accuracy > -1))
		spec.flag = '_';
	if (((minus == 1) && (spec.flag != '_')) ||
	((minus == 1) && (spec.width <= str_len)))
		ft_putchar('-');
	if (((minus != 1) && (spec.width <= str_len) && (spec.space == 1)) ||
	((spec.space == 1) && (spec.flag != '_') && (minus != 1)))
		str_len += ft_putchar(' ');
	if (spec.width > str_len)
		ft_util_width_out(spec, *str, str_len, minus);
	else
		ft_putstr_len(str_len, *str);
	free(*str);
	return ((str_len > spec.width) ? str_len : spec.width);
}
