/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolaforg <rolaforg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 13:02:45 by rolaforg          #+#    #+#             */
/*   Updated: 2020/04/06 16:03:12 by rolaforg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"

void    test_p(t_res *res)
{
	int		nb0 = (int)NULL;
	int		nb1 = 42;
	int		nbMin = -2147483648; 
	int		nbMap = 2147483647;
	char *test0 = "%s";
	char *test1 = "%s";
	int wild = 3;

    testing("%p");
	test0 = "[%p]";
	test1 = "'%p'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMap), ft_printf(test1, nbMap));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMap), ft_printf(test1, nbMap));
	testing("%(3>6)p");
	test0 = "[%3p]";
	test1 = "'%3p'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMap), ft_printf(test1, nbMap));
	test0 = "[%4p]";
	test1 = "'%4p'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMap), ft_printf(test1, nbMap));
	test0 = "[%5p]";
	test1 = "'%5p'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMap), ft_printf(test1, nbMap));
	test0 = "[%6p]";
	test1 = "'%6p'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMap), ft_printf(test1, nbMap));
	testing("%0(3>6)p");
	test0 = "[%03p]";
	test1 = "'%03p'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMap), ft_printf(test1, nbMap));
	test0 = "[%04p]";
	test1 = "'%04p'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMap), ft_printf(test1, nbMap));
	test0 = "[%05p]";
	test1 = "'%05p'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMap), ft_printf(test1, nbMap));
	test0 = "[%06p]";
	test1 = "'%06p'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMap), ft_printf(test1, nbMap));
	testing("%.(3>6)p");
	test0 = "[%.3p]";
	test1 = "'%.3p'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMap), ft_printf(test1, nbMap));
	test0 = "[%.4p]";
	test1 = "'%.4p'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMap), ft_printf(test1, nbMap));
	test0 = "[%.5p]";
	test1 = "'%.5p'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMap), ft_printf(test1, nbMap));
	test0 = "[%.6p]";
	test1 = "'%.6p'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMap), ft_printf(test1, nbMap));
	testing("%-(3>6)p");
	test0 = "[%-3p]";
	test1 = "'%-3p'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMap), ft_printf(test1, nbMap));
	test0 = "[%-4p]";
	test1 = "'%-4p'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMap), ft_printf(test1, nbMap));
	test0 = "[%-5p]";
	test1 = "'%-5p'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMap), ft_printf(test1, nbMap));
	test0 = "[%-6p]";
	test1 = "'%-6p'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMap), ft_printf(test1, nbMap));
	testing("%*p (3>6)");
	test0 = "[%*p]";
	test1 = "'%*p'";
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