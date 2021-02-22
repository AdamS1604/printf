/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 17:17:04 by abronn            #+#    #+#             */
/*   Updated: 2020/11/26 17:17:09 by abronn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str1)
{
	int				flag;
	unsigned char	*str;
	int				i;

	str = (unsigned char *)str1;
	i = 0;
	flag = 0;
	while (((*str == 32) || (*str == '\f') || (*str == '\n'))
	|| ((*str == '\t') || (*str == '\v') || (*str == '\r')))
	{
		str++;
	}
	if (*str == 45)
	{
		flag = 1;
		str++;
	}
	else if (*str == 43)
		str++;
	while ((*str >= 48) && (*str <= 57))
	{
		i = i * 10 + (*str - 48);
		str++;
	}
	return (flag == 0 ? i : -i);
}
