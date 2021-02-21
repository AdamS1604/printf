/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 19:34:32 by abronn            #+#    #+#             */
/*   Updated: 2021/02/22 00:37:49 by abronn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_util_width_out(t_spec spec, char *str, int str_len, int minus)
{
	if (spec.flag == '-')
		ft_putstr_len(str_len, str);
	if ((spec.flag == '0') && (spec.accuracy < 0))
		ft_print_char_times(spec.width - str_len, '0');
	else
		ft_print_char_times(spec.width - str_len, ' ');
	if ((minus == 1) && (spec.flag == '_'))
		ft_putchar_fd('-', 1);
	if (spec.flag != '-')
		ft_putstr_len(str_len, str);
}

int		ft_num_str_out(t_spec spec, char **str, int minus)
{
	int str_len;

	str_len = ft_strlen(*str) + minus;
	if ((spec.flag == '0') && (spec.accuracy > -1))
		spec.flag = '_';
	if (((minus == 1) && (spec.flag != '_')) ||
	((minus == 1) && (spec.width <= str_len)))
		ft_putchar_fd('-', 1);
	if (((minus != 1) && (spec.width <= str_len) && (spec.space == 1)) ||
	((spec.space == 1) && (spec.flag != '_') && (minus != 1)))
		str_len += ft_putchar_fd(' ', 1);
	if (spec.width > str_len)
		ft_util_width_out(spec, *str, str_len, minus);
	else
		ft_putstr_len(str_len, *str);
	free(*str);
	return ((str_len > spec.width) ? str_len : spec.width);
}

int		ft_util_dot_out(t_spec spec, const char **format)
{
	char	len;
	int		tmp;

	len = 0;
	if ((*((*format) + 1) == '*') || (*((*format) + 1) == '-'))
	{
		len += ft_putchar_fd('.', 1);
		if (*((*format) + 1) == '-')
			len += ft_putchar_fd('0', 1);
		ft_putnbr_fd(spec.accuracy, 1);
		tmp = ft_get_nbr_len(spec.accuracy, 10);
		len += tmp;
		(*format) += tmp;
	}
	else if (*((*format) + 1) == '\0')
		return (-1);
	else
		len += ft_putchar_fd(**format, 1);
	return (len);
}

int		ft_spec_out(const char **format, t_spec spec)
{
	int len;
	int tmp;

	len = ft_putchar_fd('%', 1);
	if (**format == ' ')
		len += ft_putchar_fd(' ', 1);
	while (**format == ' ')
		(*format)++;
	while (**format != '\0')
	{
		if (**format == '*')
		{
			ft_putnbr_fd(spec.width, 1);
			len += ft_get_nbr_len(spec.width, 10);
		}
		else if (**format == '.')
			if ((tmp = ft_util_dot_out(spec, format)) == -1)
				return (-1);
			else
				len += tmp;
		else
			len += ft_putchar_fd(**format, 1);
		(*format)++;
	}
	return (len);
}

char	*ft_str_add_accuracy(t_spec spec, char *nbr_str)
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
