/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 19:42:36 by abronn            #+#    #+#             */
/*   Updated: 2021/02/22 17:23:50 by abronn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

typedef	struct	s_spec
{
	char		flag;
	int			space;
	int			width;
	int			accuracy;
	char		type;
}				t_spec;

int				ft_handler_c(char c, t_spec spec);
int				ft_handler_s(char *str, t_spec spec);
int				ft_handler_d(int nbr, t_spec spec);
int				ft_handler_u(unsigned int nbr, t_spec spec);
int				ft_handler_x(unsigned int nbr, t_spec spec);
int				ft_handler_p(unsigned long long nbr, t_spec spec);

int				ft_spec_out(const char **format, t_spec spec);

char			*ft_str_add_accuracy(t_spec spec, char *nbr_str);
int				ft_num_str_out(t_spec spec, char **str, int minus);

int				ft_parser(va_list ap, const char *format, t_spec *spec);

int				ft_printf(const char *format, ...);

#endif
