/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolaforg <rolaforg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 13:02:45 by rolaforg          #+#    #+#             */
/*   Updated: 2020/04/06 16:03:06 by rolaforg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"

void    test_i(t_res *res)
{
	int		nb0 = (int)NULL;
	int		nb1 = 42;
	int		nbMin = -2147483648; 
	int		nbMax = 2147483647;
	char *test0 = "%s";
	char *test1 = "%s";
	int wild = 3;

    testing("%i");
	test0 = "[%i]";
	test1 = "'%i'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	testing("%(3>6)i");
	test0 = "[%3i]";
	test1 = "'%3i'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test0 = "[%4i]";
	test1 = "'%4i'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test0 = "[%5i]";
	test1 = "'%5i'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test0 = "[%6i]";
	test1 = "'%6i'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	testing("%0(3>6)i");
	test0 = "[%03i]";
	test1 = "'%03i'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test0 = "[%04i]";
	test1 = "'%04i'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test0 = "[%05i]";
	test1 = "'%05i'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test0 = "[%06i]";
	test1 = "'%06i'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	testing("%.(3>6)i");
	test0 = "[%.3i]";
	test1 = "'%.3i'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test0 = "[%.4i]";
	test1 = "'%.4i'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test0 = "[%.5i]";
	test1 = "'%.5i'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test0 = "[%.6i]";
	test1 = "'%.6i'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	testing("%-(3>6)i");
	test0 = "[%-3i]";
	test1 = "'%-3i'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test0 = "[%-4i]";
	test1 = "'%-4i'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test0 = "[%-5i]";
	test1 = "'%-5i'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test0 = "[%-6i]";
	test1 = "'%-6i'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	testing("%*i (3>6)");
	test0 = "[%*i]";
	test1 = "'%*i'";
	wild = 3;
	test(res, printf(test0, wild, nb0), ft_printf(test1, wild, nb0));
	test(res, printf(test0, wild, nb1), ft_printf(test1, wild, nb1));
	wild = 4;
	test(res, printf(test0, wild, nb0), ft_printf(test1, wild, nb0));
	test(res, printf(test0, wild, nb1), ft_printf(test1, wild, nb1));
	wild = 5;
	test(res, printf(test0, wild, nb0), ft_printf(test1, wild, nb0));
	test(res, printf(test0, wild, nb1), ft_printf(test1, wild, nb1));
	wild = 6;
	test(res, printf(test0, wild, nb0), ft_printf(test1, wild, nb0));
	test(res, printf(test0, wild, nb1), ft_printf(test1, wild, nb1));

}