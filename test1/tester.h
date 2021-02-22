/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolaforg <rolaforg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 12:59:56 by rolaforg          #+#    #+#             */
/*   Updated: 2020/04/19 14:08:53 by rolaforg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <printf.h>

typedef struct s_res
{
 	unsigned int ok;
	unsigned int fail;
} t_res;

int		ft_printf(const char *str, ...);
void	header(void);
void	test(t_res *res, int one, int two);
void	testing(char *str);
void	test_s(t_res *res);
void	test_c(t_res *res);
void	test_i(t_res *res);
void	test_d(t_res *res);
void	test_x(t_res *res);
void	test_x_maj(t_res *res);
void	test_p(t_res *res);
void	test_u(t_res *res);
void	test_mix(t_res *res);
void	test_mix_spaces(t_res *res);
void	test_mix_options(t_res *res);
void    test_percent(t_res *res);