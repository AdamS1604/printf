/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:54:58 by abronn            #+#    #+#             */
/*   Updated: 2021/02/22 00:11:25 by abronn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_handler_s(va_list ap, t_spec spec)
{
	char	*str;
	int		str_len;

	str = va_arg(ap, char*);
	if (str == 0)
	{
		if ((spec.accuracy >= 6) || (spec.accuracy <= -1))
			str = "(null)";
		else
			str = "";
	}
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
