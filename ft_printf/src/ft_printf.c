/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 01:10:36 by abronn            #+#    #+#             */
/*   Updated: 2021/02/23 13:49:18 by abronn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			ft_handlers_hub(va_list ap, t_spec spec)
{
	if (spec.type == 'c')
		return (ft_handler_c(va_arg(ap, int), spec));
	if (spec.type == 's')
		return (ft_handler_s(va_arg(ap, char*), spec));
	if (spec.type == 'u')
		return (ft_handler_u(va_arg(ap, unsigned int), spec));
	if (spec.type == 'p')
		return (ft_handler_p(va_arg(ap, unsigned long long), spec));
	if ((spec.type == 'x') || (spec.type == 'X'))
		return (ft_handler_x(va_arg(ap, unsigned int), spec));
	if ((spec.type == 'd') || (spec.type == 'i'))
		return (ft_handler_d(va_arg(ap, int), spec));
	return (0);
}

static int			ft_main_hub(va_list ap, const char **format)
{
	int		parse;
	t_spec	spec;

	parse = ft_parser(ap, ++(*format), &spec);
	if (parse > 0)
	{
		(*format) += parse;
		return (ft_spec_out(format, spec));
	}
	(*format) += parse * -1;
	return (ft_handlers_hub(ap, spec));
}

static int			ft_print_all(va_list ap, const char *format)
{
	int len;
	int tmp;

	len = 0;
	while (*format)
		if ((*format == '%'))
			if ((tmp = ft_main_hub(ap, &format)) == -1)
				return (-1);
			else
				len += tmp;
		else
			len += ft_putchar_fd(*(format++), 1);
	return (len);
}

int					ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;

	if (!format)
		return (-1);
	va_start(ap, format);
	len = ft_print_all(ap, format);
	va_end(ap);
	return (len);
}
