/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lib2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 19:34:47 by abronn            #+#    #+#             */
/*   Updated: 2021/02/20 19:48:32 by abronn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (*(str++))
		i++;
	return (i);
}

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		if (n <= -10)
			ft_putnbr(n / -10);
		ft_putchar(-(n % 10) + '0');
	}
	else if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putchar((n % 10) + '0');
	}
	else
		ft_putchar(n + '0');
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
		if (*s++ == (char)c)
			return ((char *)s - 1);
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

int		ft_atoi(const char *str1)
{
	int				flag;
	unsigned char	*str;
	int				i;

	str = (unsigned char *)str1;
	i = 0;
	flag = 0;
	while (((*str == 32) || (*str == '\f') || (*str == '\n'))
	|| ((*str == '\t') || (*str == '\v') || (*str == '\r')))
	{
		str++;
	}
	if (*str == 45)
	{
		flag = 1;
		str++;
	}
	else if (*str == 43)
		str++;
	while ((*str >= 48) && (*str <= 57))
	{
		i = i * 10 + (*str - 48);
		str++;
	}
	return (flag == 0 ? i : -i);
}
