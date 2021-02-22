/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolaforg <rolaforg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 13:02:45 by rolaforg          #+#    #+#             */
/*   Updated: 2020/04/17 19:53:00 by rolaforg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"

void    test_percent(t_res *res)
{
	testing("%nb%");
	test(res, printf("[%012%]"), ft_printf("(%012%)"));
	test(res, printf("[%12%]"), ft_printf("(%12%)"));
	test(res, printf("[%-12%]"), ft_printf("(%-12%)"));
	test(res, printf("[%0%]"), ft_printf("(%0%)"));
}