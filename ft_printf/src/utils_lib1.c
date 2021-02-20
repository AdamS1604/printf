/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lib.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 19:27:42 by abronn            #+#    #+#             */
/*   Updated: 2021/02/20 19:28:13 by abronn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

char	*ft_strdup(const char *str)
{
	char	*dest;
	char	*src;
	size_t	len;

	src = (char *)str;
	len = ft_strlen(src);
	dest = (char *)malloc(len + 1);
	if (dest == 0)
		return (0);
	return (ft_memcpy(dest, src, len + 1));
}

void	*ft_memmove(void *destination, const void *source, size_t n)
{
	unsigned char *dest;
	unsigned char *src;

	dest = (unsigned char *)destination;
	src = (unsigned char *)source;
	if (!dest && !src)
		return (destination);
	if (src < dest)
		while (n--)
			dest[n] = src[n];
	else
		while (n--)
			*(dest++) = *(src++);
	return (destination);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l1;
	size_t	l2;
	char	*ptr;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && s2)
		return (ft_strdup(s2));
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	ptr = malloc(l1 + l2 + 1);
	if (!ptr)
		return (0);
	ft_memmove(ptr, s1, l1);
	ft_memmove(ptr + l1, s2, l2);
	ptr[l1 + l2] = '\0';
	return (ptr);
}
