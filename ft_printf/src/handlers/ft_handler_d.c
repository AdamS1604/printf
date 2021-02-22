/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:54:48 by abronn            #+#    #+#             */
/*   Updated: 2021/02/22 17:23:16 by abronn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_handler_d(int nbr, t_spec spec)
{
	int		minus;
	char	*str;

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
	if (!(str = ft_str_add_accuracy(spec, str)))
		return (-1);
	return (ft_num_str_out(spec, &str, minus));
}
