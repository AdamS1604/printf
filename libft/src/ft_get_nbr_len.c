/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nbr_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:10:06 by abronn            #+#    #+#             */
/*   Updated: 2021/02/21 23:10:22 by abronn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_get_nbr_len(int nbr, int base)
{
	int len;
	int flag;

	len = 0;
	flag = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		flag++;
	while (nbr)
	{
		len++;
		nbr /= base;
	}
	if (flag)
		len++;
	return (len);
}
