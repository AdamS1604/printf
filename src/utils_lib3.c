/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lib3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 19:36:59 by abronn            #+#    #+#             */
/*   Updated: 2021/02/20 19:37:29 by abronn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
		*(ptr++) = '\0';
}

void	*ft_calloc(size_t number, size_t size)
{
	void	*ptr;

	ptr = (void*)malloc(number * size);
	if (!ptr)
		return (0);
	ft_bzero(ptr, number * size);
	return (ptr);
}
