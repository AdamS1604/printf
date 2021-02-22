/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolaforg <rolaforg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 12:03:12 by rolaforg          #+#    #+#             */
/*   Updated: 2020/04/19 14:15:59 by rolaforg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

long long	main(void)
{
	t_res	res;
	res.ok = 0;
	res.fail = 0;

	header();
	test_s(&res);
	test_c(&res);
	test_i(&res);
	test_d(&res);
	test_x(&res);
	test_x_maj(&res);
	test_p(&res);
	test_u(&res);
	test_mix(&res);
	test_mix_spaces(&res);
	test_mix_options(&res);
	test_percent(&res);
	printf("\n%u/%u test passed.\n", res.ok, res.fail + res.ok);
}