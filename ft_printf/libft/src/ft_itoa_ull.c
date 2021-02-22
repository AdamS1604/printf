/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ull.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 22:39:36 by abronn            #+#    #+#             */
/*   Updated: 2021/02/21 22:39:36 by abronn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	init_size_ull(unsigned long long int n, int base)
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

char			*ft_itoa_ull(unsigned long long int n, int base)
{
	unsigned long long int		num;
	char						*str;
	size_t						size;
	char						*base_arr;

	size = init_size_ull(n, base);
	num = n;
	if (!(str = (char*)ft_calloc(size + 1, sizeof(char))))
		return (str);
	base_arr = "0123456789abcdef";
	while (size > 0)
	{
		*(str + --size) = *(base_arr + (num % base));
		num /= base;
	}
	return (str);
}
