/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronn <marvin@42.f>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 21:45:58 by abronn            #+#    #+#             */
/*   Updated: 2020/11/26 21:47:07 by abronn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	size_t	d_len;
	char	*ptr;

	i = 0;
	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (s_len - start < len)
		d_len = s_len - start;
	else
		d_len = len;
	ptr = (char *)malloc(d_len + 1);
	if (!ptr)
		return (0);
	while (d_len--)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
