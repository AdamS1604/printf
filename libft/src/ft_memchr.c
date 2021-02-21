/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronn <marvin@42.f>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 21:24:04 by abronn            #+#    #+#             */
/*   Updated: 2020/11/26 21:25:15 by abronn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned char *arr2;
	unsigned char chr;

	chr = (unsigned char)c;
	arr2 = (unsigned char *)arr;
	while (n--)
	{
		if (*arr2 == chr)
			return (arr2);
		arr2++;
	}
	return (0);
}
