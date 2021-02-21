/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronn <marvin@42.f>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 21:29:30 by abronn            #+#    #+#             */
/*   Updated: 2020/11/26 21:29:47 by abronn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *destination, int c, size_t n)
{
	unsigned char *dest;
	unsigned char chr;

	dest = (unsigned char *)destination;
	chr = (unsigned char)c;
	while (n--)
		*(dest++) = chr;
	return (destination);
}
