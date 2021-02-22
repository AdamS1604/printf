/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:54:53 by abronn            #+#    #+#             */
/*   Updated: 2021/02/22 00:14:38 by abronn           ###   ########.fr       */
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
		if (!(str = ft_str_add_accuracy(spec, ft_itoa_ull(nbr, 16))))
			return (-1);
		tmp = str;
		str = ft_strjoin("0x", str);
		free(tmp);
	}
	if (!(str))
		return (-1);
	return (ft_num_str_out(spec, &str, 0));
}
