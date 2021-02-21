/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronn <marvin@42.f>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 21:27:33 by abronn            #+#    #+#             */
/*   Updated: 2020/11/26 21:28:17 by abronn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t n)
{
	unsigned char *dest;
	unsigned char *src;

	dest = (unsigned char *)destination;
	src = (unsigned char *)source;
	if (!dest && !src)
		return (0);
	while (n--)
		*(dest++) = *(src++);
	return (destination);
}
