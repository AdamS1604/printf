/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 19:42:36 by abronn            #+#    #+#             */
/*   Updated: 2021/02/20 20:09:18 by abronn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef	struct	s_spec
{
	char		flag;
	int			space;
	int			width;
	int			accuracy;
	char		type;
}				t_spec;

size_t			ft_strlen(const char *str);
int				ft_zero_len(const char *format);
int				ft_print_char_times(int i, char c);
int				ft_get_nbr_len(int nbr, int base);
int				ft_putchar(char c);
int				ft_putstr_len(int len, char *s);
void			ft_putnbr(int n);
char			*ft_strchr(const char *s, int c);
int				ft_atoi(const char *str1);
char			*ft_strdup(const char *str);
char			*ft_strjoin(char const *s1, char const *s2);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t number, size_t size);
char			*ft_itoa_u(unsigned int n, int base, int flag);
char			*ft_itoa_ull(unsigned long long int n, int base);
char			*ft_str_add_accuracy(t_spec spec, char *nbr_str);
int				ft_parser(va_list ap, const char *format, t_spec *spec);
int				ft_handler_c(va_list ap, t_spec spec);
int				ft_handler_s(va_list ap, t_spec spec);
int				ft_handler_u(va_list ap, t_spec spec);
int				ft_spec_out(const char **format, t_spec spec);
int				ft_handler_p(va_list ap, t_spec spec);
int				ft_handler_x(va_list ap, t_spec spec);
int				ft_handler_d(va_list ap, t_spec spec);
int				ft_num_str_out(t_spec spec, char **str, int minus);

#endif
