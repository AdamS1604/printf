/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 19:34:32 by abronn            #+#    #+#             */
/*   Updated: 2021/02/21 23:12:35 by abronn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_str_add_accuracy(t_spec spec, char *nbr_str)
{
	int		nbr_len;
	char	*new_str;
	char	*tmp;
	int		i;
	int		k;

	if (nbr_str == 0)
		return (0);
	nbr_len = ft_strlen(nbr_str);
	if (spec.accuracy > nbr_len)
	{
		i = spec.accuracy - nbr_len;
		k = 0;
		if (!(new_str = (char *)ft_calloc(spec.accuracy + 1, sizeof(char))))
			return (0);
		while (i--)
			new_str[k++] = '0';
		tmp = nbr_str;
		nbr_str = ft_strjoin(new_str, nbr_str);
		free(tmp);
		free(new_str);
	}
	return (nbr_str);
}
