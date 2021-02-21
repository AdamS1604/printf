/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 22:37:35 by abronn            #+#    #+#             */
/*   Updated: 2021/02/21 22:38:31 by abronn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	init_size_u(unsigned int n, int base)
{
	size_t	size;

	size = 1;
	while (n / base)
	{
		n /= base;
		size++;
	}
	return (size);
}

char			*ft_itoa_u(unsigned int n, int base, int flag)
{
	unsigned int		num;
	char				*str;
	size_t				size;
	const char			*arr_base;

	size = init_size_u(n, base);
	num = n;
	if (!(str = (char*)ft_calloc(size + 1, 1)))
		return (0);
	if (flag == 1)
		arr_base = "0123456789ABCDEF";
	else
		arr_base = "0123456789abcdef";
	while (size > 0)
	{
		*(str + --size) = *(arr_base + (num % base));
		num /= base;
	}
	return (str);
}
