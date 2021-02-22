/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolaforg <rolaforg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 13:02:45 by rolaforg          #+#    #+#             */
/*   Updated: 2020/04/06 16:03:36 by rolaforg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"

void    test_u(t_res *res)
{
	int		nb0 = (int)NULL;
	int		nb1 = 42;
	int		nbMin = -2147483648; 
	int		nbMau = 2147483647;
	char *test0 = "%s";
	char *test1 = "%s";
	int wild = 3;

    testing("%u");
	test0 = "[%u]";
	test1 = "'%u'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMau), ft_printf(test1, nbMau));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMau), ft_printf(test1, nbMau));
	testing("%(3>6)u");
	test0 = "[%3u]";
	test1 = "'%3u'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMau), ft_printf(test1, nbMau));
	test0 = "[%4u]";
	test1 = "'%4u'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMau), ft_printf(test1, nbMau));
	test0 = "[%5u]";
	test1 = "'%5u'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMau), ft_printf(test1, nbMau));
	test0 = "[%6u]";
	test1 = "'%6u'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMau), ft_printf(test1, nbMau));
	testing("%0(3>6)u");
	test0 = "[%03u]";
	test1 = "'%03u'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMau), ft_printf(test1, nbMau));
	test0 = "[%04u]";
	test1 = "'%04u'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMau), ft_printf(test1, nbMau));
	test0 = "[%05u]";
	test1 = "'%05u'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMau), ft_printf(test1, nbMau));
	test0 = "[%06u]";
	test1 = "'%06u'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMau), ft_printf(test1, nbMau));
	testing("%.(3>6)u");
	test0 = "[%.3u]";
	test1 = "'%.3u'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMau), ft_printf(test1, nbMau));
	test0 = "[%.4u]";
	test1 = "'%.4u'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMau), ft_printf(test1, nbMau));
	test0 = "[%.5u]";
	test1 = "'%.5u'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMau), ft_printf(test1, nbMau));
	test0 = "[%.6u]";
	test1 = "'%.6u'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMau), ft_printf(test1, nbMau));
	testing("%-(3>6)u");
	test0 = "[%-3u]";
	test1 = "'%-3u'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMau), ft_printf(test1, nbMau));
	test0 = "[%-4u]";
	test1 = "'%-4u'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMau), ft_printf(test1, nbMau));
	test0 = "[%-5u]";
	test1 = "'%-5u'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMau), ft_printf(test1, nbMau));
	test0 = "[%-6u]";
	test1 = "'%-6u'";
	test(res, printf(test0, nb0), ft_printf(test1, nb0));
	test(res, printf(test0, nb1), ft_printf(test1, nb1));
	test(res, printf(test0, nbMin), ft_printf(test1, nbMin));
	test(res, printf(test0, nbMau), ft_printf(test1, nbMau));
	testing("%*u (3>6)");
	test0 = "[%*u]";
	test1 = "'%*u'";
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