/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 19:34:32 by abronn            #+#    #+#             */
/*   Updated: 2021/02/20 19:49:27 by abronn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_zero_len(const char *format)
{
	int len;

	len = 0;
	while (*format == '0')
	{
		format++;
		len++;
	}
	return (len);
}

int		ft_print_char_times(int i, char c)
{
	int len;

	len = i;
	while (i-- > 0)
		ft_putchar(c);
	return (len);
}

int		ft_get_nbr_len(int nbr, int base)
{
	int len;
	int flag;

	len = 0;
	flag = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		flag++;
	while (nbr)
	{
		len++;
		nbr /= base;
	}
	if (flag)
		len++;
	return (len);
}

int		ft_putstr_len(int len, char *s)
{
	size_t	i;
	int		str_len;

	i = 0;
	str_len = ft_strlen(s);
	while ((len > i) && (str_len--))
		ft_putchar(s[i++]);
	return (i);
}

char	*ft_str_add_accuracy(va_list ap, t_spec spec, char *nbr_str)
{
	int		nbr_len;
	char	*new_str;
	char	*tmp;
	int		i;
	int		k;

	if (nbr_str == 0)
		return (0);
	nbr_len = ft_strlen(nbr_str);
	if (spec.accuracy > nbr_len)
	{
		i = spec.accuracy - nbr_len;
		k = 0;
		if (!(new_str = (char *)ft_calloc(spec.accuracy + 1, sizeof(char))))
			return (0);
		while (i--)
			new_str[k++] = '0';
		tmp = nbr_str;
		nbr_str = ft_strjoin(new_str, nbr_str);
		free(tmp);
		free(new_str);
	}
	return (nbr_str);
}
