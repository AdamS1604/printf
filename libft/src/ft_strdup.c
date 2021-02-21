/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronn <marvin@42.f>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 21:33:42 by abronn            #+#    #+#             */
/*   Updated: 2020/11/26 21:33:57 by abronn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
