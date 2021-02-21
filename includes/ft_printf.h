/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 19:42:36 by abronn            #+#    #+#             */
/*   Updated: 2021/02/21 23:12:06 by abronn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

typedef	struct	s_spec
{
	char		flag;
	int			space;
	int			width;
	int			accuracy;
	char		type;
}				t_spec;

char			*ft_str_add_accuracy(t_spec spec, char *nbr_str);
int				ft_handler_c(va_list ap, t_spec spec);
int				ft_handler_s(va_list ap, t_spec spec);
int				ft_handler_u(va_list ap, t_spec spec);
int				ft_spec_out(const char **format, t_spec spec);
int				ft_handler_p(va_list ap, t_spec spec);
int				ft_handler_x(va_list ap, t_spec spec);
int				ft_handler_d(va_list ap, t_spec spec);
int				ft_num_str_out(t_spec spec, char **str, int minus);

int				ft_parser(va_list ap, const char *format, t_spec *spec);
int				ft_printf(const char *format, ...);

#endif
