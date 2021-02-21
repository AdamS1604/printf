/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:04:08 by abronn            #+#    #+#             */
/*   Updated: 2021/02/21 23:04:09 by abronn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putstr_len(int len, char *s)
{
	int		i;
	int		str_len;

	i = 0;
	str_len = ft_strlen(s);
	if (len == -1)
		len = str_len;
	while ((len > i) && (str_len--))
		ft_putchar_fd(s[i++], 1);
	return (i);
}
