/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_x_maj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolaforg <rolaforg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 13:02:45 by rolaforg          #+#    #+#             */
/*   Updated: 2020/04/06 16:03:42 by rolaforg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"

void    test_x_maj(t_res *res)
{
	int		nb0 = (int)NULL;
	int		nb1 = 42;
	int		nbMin = -2147483648; 
	int		nbMaX = 2147483647;
	char *test0 = "%s";
	char *test1 = "%s";
	int wild = 3;

    testing("%X");
	test0 = "[%X]";
	test1 = "'%X'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMaX), ft_printf(test1, nbMaX));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMaX), ft_printf(test1, nbMaX));
	testing("%(3>6)X");
	test0 = "[%3X]";
	test1 = "'%3X'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMaX), ft_printf(test1, nbMaX));
	test0 = "[%4X]";
	test1 = "'%4X'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMaX), ft_printf(test1, nbMaX));
	test0 = "[%5X]";
	test1 = "'%5X'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMaX), ft_printf(test1, nbMaX));
	test0 = "[%6X]";
	test1 = "'%6X'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMaX), ft_printf(test1, nbMaX));
	testing("%0(3>6)X");
	test0 = "[%03X]";
	test1 = "'%03X'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMaX), ft_printf(test1, nbMaX));
	test0 = "[%04X]";
	test1 = "'%04X'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMaX), ft_printf(test1, nbMaX));
	test0 = "[%05X]";
	test1 = "'%05X'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMaX), ft_printf(test1, nbMaX));
	test0 = "[%06X]";
	test1 = "'%06X'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMaX), ft_printf(test1, nbMaX));
	testing("%.(3>6)X");
	test0 = "[%.3X]";
	test1 = "'%.3X'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMaX), ft_printf(test1, nbMaX));
	test0 = "[%.4X]";
	test1 = "'%.4X'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMaX), ft_printf(test1, nbMaX));
	test0 = "[%.5X]";
	test1 = "'%.5X'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMaX), ft_printf(test1, nbMaX));
	test0 = "[%.6X]";
	test1 = "'%.6X'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMaX), ft_printf(test1, nbMaX));
	testing("%-(3>6)X");
	test0 = "[%-3X]";
	test1 = "'%-3X'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMaX), ft_printf(test1, nbMaX));
	test0 = "[%-4X]";
	test1 = "'%-4X'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMaX), ft_printf(test1, nbMaX));
	test0 = "[%-5X]";
	test1 = "'%-5X'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMaX), ft_printf(test1, nbMaX));
	test0 = "[%-6X]";
	test1 = "'%-6X'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMaX), ft_printf(test1, nbMaX));
	testing("%*X (3>6)");
	test0 = "[%*X]";
	test1 = "'%*X'";
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