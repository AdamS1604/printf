/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronn <marvin@42.f>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 21:40:20 by abronn            #+#    #+#             */
/*   Updated: 2020/11/26 21:40:23 by abronn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	int		n;
	char	*str;

	str = (char *)haystack;
	if (ft_strlen(needle) == 0)
		return (str);
	if (len == 0)
		return (0);
	while (*str && len)
	{
		i = 0;
		n = len;
		while (n && needle[i] && str[i] == needle[i])
		{
			i++;
			n--;
		}
		if (needle[i] == '\0')
			return (str);
		str++;
		len--;
	}
	return (0);
}
