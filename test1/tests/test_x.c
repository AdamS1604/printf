/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolaforg <rolaforg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 13:02:45 by rolaforg          #+#    #+#             */
/*   Updated: 2020/04/06 16:03:49 by rolaforg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"

void    test_x(t_res *res)
{
	int		nb0 = (int)NULL;
	int		nb1 = 42;
	int		nbMin = -2147483648; 
	int		nbMax = 2147483647;
	char *test0 = "%s";
	char *test1 = "%s";
	int wild = 3;

    testing("%x");
	test0 = "[%x]";
	test1 = "'%x'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMax), ft_printf(test1, nbMax));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMax), ft_printf(test1, nbMax));
	testing("%(3>6)x");
	test0 = "[%3x]";
	test1 = "'%3x'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMax), ft_printf(test1, nbMax));
	test0 = "[%4x]";
	test1 = "'%4x'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMax), ft_printf(test1, nbMax));
	test0 = "[%5x]";
	test1 = "'%5x'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMax), ft_printf(test1, nbMax));
	test0 = "[%6x]";
	test1 = "'%6x'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMax), ft_printf(test1, nbMax));
	testing("%0(3>6)x");
	test0 = "[%03x]";
	test1 = "'%03x'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMax), ft_printf(test1, nbMax));
	test0 = "[%04x]";
	test1 = "'%04x'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMax), ft_printf(test1, nbMax));
	test0 = "[%05x]";
	test1 = "'%05x'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMax), ft_printf(test1, nbMax));
	test0 = "[%06x]";
	test1 = "'%06x'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMax), ft_printf(test1, nbMax));
	testing("%.(3>6)x");
	test0 = "[%.3x]";
	test1 = "'%.3x'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMax), ft_printf(test1, nbMax));
	test0 = "[%.4x]";
	test1 = "'%.4x'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMax), ft_printf(test1, nbMax));
	test0 = "[%.5x]";
	test1 = "'%.5x'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMax), ft_printf(test1, nbMax));
	test0 = "[%.6x]";
	test1 = "'%.6x'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMax), ft_printf(test1, nbMax));
	testing("%-(3>6)x");
	test0 = "[%-3x]";
	test1 = "'%-3x'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMax), ft_printf(test1, nbMax));
	test0 = "[%-4x]";
	test1 = "'%-4x'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMax), ft_printf(test1, nbMax));
	test0 = "[%-5x]";
	test1 = "'%-5x'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMax), ft_printf(test1, nbMax));
	test0 = "[%-6x]";
	test1 = "'%-6x'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMax), ft_printf(test1, nbMax));
	testing("%*x (3>6)");
	test0 = "[%*x]";
	test1 = "'%*x'";
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