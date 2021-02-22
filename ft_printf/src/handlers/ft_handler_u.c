/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:55:04 by abronn            #+#    #+#             */
/*   Updated: 2021/02/22 00:11:35 by abronn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	if (!(str = ft_str_add_accuracy(spec, str)))
		return (-1);
	return (ft_num_str_out(spec, &str, 0));
}
