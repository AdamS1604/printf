/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronn <marvin@42.f>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 21:55:14 by abronn            #+#    #+#             */
/*   Updated: 2020/11/26 21:55:14 by abronn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_split_array_creator(char const *s, char c)
{
	int	i;
	int	n;
	char**res;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			n++;
		i++;
	}
	res = (char **)malloc(sizeof(char *) * (n + 1));
	if (!res)
		return (0);
	res[n] = NULL;
	return (res);
}

static int	ft_split_len(char const *s, char c)
{
	int len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		s++;
		len++;
	}
	return (len);
}

static char	**ft_split_clear(char **res, int n)
{
	int i;

	i = 0;
	while (i < n)
		free(res[i++]);
	free(res);
	return (0);
}

char		**ft_split(char const *s, char c)
{
	char**res;
	int	len;
	int	n;

	if (!s)
		return (0);
	len = 0;
	n = 0;
	if (!(res = ft_split_array_creator(s, c)))
		return (0);
	while (*s)
	{
		while (*s == c)
			s++;
		len = ft_split_len(s, c);
		s = s + len;
		if (len != 0)
		{
			if (!(res[n] = (char *)malloc(sizeof(char) * (len + 1))))
				return (ft_split_clear(res, n));
			ft_strlcpy(res[n++], s - len, len + 1);
		}
		len = 0;
	}
	return (res);
}
