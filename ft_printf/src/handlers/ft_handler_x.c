/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 00:10:45 by abronn            #+#    #+#             */
/*   Updated: 2021/02/22 17:21:32 by abronn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_handler_x(unsigned int nbr, t_spec spec)
{
	char			*str;

	str = 0;
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
	if (!(str = ft_str_add_accuracy(spec, str)))
		return (-1);
	return (ft_num_str_out(spec, &str, 0));
}
