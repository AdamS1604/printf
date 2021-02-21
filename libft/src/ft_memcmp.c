/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronn <marvin@42.f>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 21:25:29 by abronn            #+#    #+#             */
/*   Updated: 2020/11/26 21:27:12 by abronn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	unsigned char *arr_1;
	unsigned char *arr_2;

	arr_1 = (unsigned char *)arr1;
	arr_2 = (unsigned char *)arr2;
	if (!n)
		return (0);
	while (n--)
	{
		if (*arr_1 != *arr_2)
			return (*arr_1 - *arr_2);
		arr_1++;
		arr_2++;
	}
	return (0);
}
