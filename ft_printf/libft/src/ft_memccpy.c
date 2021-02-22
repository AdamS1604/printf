/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 17:53:39 by abronn            #+#    #+#             */
/*   Updated: 2020/11/26 17:53:46 by abronn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *source, int c, size_t n)
{
	unsigned char	chr;
	unsigned char	*src;
	unsigned char	*dst;

	chr = (unsigned char)c;
	src = (unsigned char *)source;
	dst = (unsigned char *)dest;
	while (n--)
	{
		*(dst++) = *(src++);
		if (*(src - 1) == chr)
			return (dst);
	}
	return (0);
}
