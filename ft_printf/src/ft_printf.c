/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 01:10:36 by abronn            #+#    #+#             */
/*   Updated: 2021/02/22 12:01:03 by abronn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_handlers_hub(va_list ap, t_spec spec)
{
	if (spec.type == 'c')
		return (ft_handler_c(ap, spec));
	if (spec.type == 's')
		return (ft_handler_s(ap, spec));
	if (spec.type == 'u')
		return (ft_handler_u(ap, spec));
	if (spec.type == 'p')
		return (ft_handler_p(ap, spec));
	if ((spec.type == 'x') || (spec.type == 'X'))
		return (ft_handler_x(ap, spec));
	if ((spec.type == 'd') || (spec.type == 'i'))
		return (ft_handler_d(ap, spec));
	if (spec.type == '%')
		return (ft_putchar_fd('%', 1));
	return (0);
}

int		ft_main_hub(va_list ap, const char **format)
{
	int		parse;
	t_spec	spec;

	if ((parse = ft_parser(ap, ++(*format), &spec)) == 0)
		return (-1);
	else if (parse > 0)
		return (ft_spec_out(format, spec));
	(*format) += parse * -1;
	return (ft_handlers_hub(ap, spec));
}

int		ft_print_all(va_list ap, const char *format)
{
	int len;
	int tmp;

	len = 0;
	while (*format)
		if ((*format == '%'))
			if ((*(format + 1) == '\0') ||
			((tmp = ft_main_hub(ap, &format)) == -1))
				return (-1);
			else
				len += tmp;
		else
			len += ft_putchar_fd(*(format++), 1);
	return (len);
}

int		ft_printf(const char *format, ...)
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
