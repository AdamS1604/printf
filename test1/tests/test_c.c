/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolaforg <rolaforg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 13:02:45 by rolaforg          #+#    #+#             */
/*   Updated: 2020/04/06 16:02:42 by rolaforg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"

void    test_c(t_res *res)
{
    char *test0 = "[%s]";
	char *test1 = "'%s'";
	int wild = 3;
    char	c0 = (char)NULL;
	char	c1 = 'a';
	char	cMin = 0;
	char	cMax = 127;
	char	cEx = 255;

    testing("%c");
	test0 = "[%c]";
	test1 = "'%c'";
	test(res, printf(test0, c0), ft_printf(test1, c0));
	test(res, printf(test0, c1), ft_printf(test1, c1));
	testing("%(3>6)c");
	test0 = "[%3c]";
	test1 = "'%3c'";
	test(res, printf(test0, c0), ft_printf(test1, c0));
	test(res, printf(test0, c1), ft_printf(test1, c1));
	test0 = "[%4c]";
	test1 = "'%4c'";
	test(res, printf(test0, c0), ft_printf(test1, c0));
	test(res, printf(test0, c1), ft_printf(test1, c1));
	test0 = "[%5c]";
	test1 = "'%5c'";
	test(res, printf(test0, c0), ft_printf(test1, c0));
	test(res, printf(test0, c1), ft_printf(test1, c1));
	test0 = "[%6c]";
	test1 = "'%6c'";
	test(res, printf(test0, c0), ft_printf(test1, c0));
	test(res, printf(test0, c1), ft_printf(test1, c1));
	testing("%0(3>6)c");
	test0 = "[%03c]";
	test1 = "'%03c'";
	test(res, printf(test0, c0), ft_printf(test1, c0));
	test(res, printf(test0, c1), ft_printf(test1, c1));
	test0 = "[%04c]";
	test1 = "'%04c'";
	test(res, printf(test0, c0), ft_printf(test1, c0));
	test(res, printf(test0, c1), ft_printf(test1, c1));
	test0 = "[%05c]";
	test1 = "'%05c'";
	test(res, printf(test0, c0), ft_printf(test1, c0));
	test(res, printf(test0, c1), ft_printf(test1, c1));
	test0 = "[%06c]";
	test1 = "'%06c'";
	test(res, printf(test0, c0), ft_printf(test1, c0));
	test(res, printf(test0, c1), ft_printf(test1, c1));
	testing("%.(3>6)c");
	test0 = "[%.3c]";
	test1 = "'%.3c'";
	test(res, printf(test0, c0), ft_printf(test1, c0));
	test(res, printf(test0, c1), ft_printf(test1, c1));
	test0 = "[%.4c]";
	test1 = "'%.4c'";
	test(res, printf(test0, c0), ft_printf(test1, c0));
	test(res, printf(test0, c1), ft_printf(test1, c1));
	test0 = "[%.5c]";
	test1 = "'%.5c'";
	test(res, printf(test0, c0), ft_printf(test1, c0));
	test(res, printf(test0, c1), ft_printf(test1, c1));
	test0 = "[%.6c]";
	test1 = "'%.6c'";
	test(res, printf(test0, c0), ft_printf(test1, c0));
	test(res, printf(test0, c1), ft_printf(test1, c1));
	testing("%-(3>6)c");
	test0 = "[%-3c]";
	test1 = "'%-3c'";
	test(res, printf(test0, c0), ft_printf(test1, c0));
	test(res, printf(test0, c1), ft_printf(test1, c1));
	test0 = "[%-4c]";
	test1 = "'%-4c'";
	test(res, printf(test0, c0), ft_printf(test1, c0));
	test(res, printf(test0, c1), ft_printf(test1, c1));
	test0 = "[%-5c]";
	test1 = "'%-5c'";
	test(res, printf(test0, c0), ft_printf(test1, c0));
	test(res, printf(test0, c1), ft_printf(test1, c1));
	test0 = "[%-6c]";
	test1 = "'%-6c'";
	test(res, printf(test0, c0), ft_printf(test1, c0));
	test(res, printf(test0, c1), ft_printf(test1, c1));
	testing("%*c (3>6)");
	test0 = "[%*c]";
	test1 = "'%*c'";
	wild = 3;
	test(res, printf(test0, wild, c0), ft_printf(test1, wild, c0));
	test(res, printf(test0, wild, c1), ft_printf(test1, wild, c1));
	wild = 4;
	test(res, printf(test0, wild, c0), ft_printf(test1, wild, c0));
	test(res, printf(test0, wild, c1), ft_printf(test1, wild, c1));
	wild = 5;
	test(res, printf(test0, wild, c0), ft_printf(test1, wild, c0));
	test(res, printf(test0, wild, c1), ft_printf(test1, wild, c1));
	wild = 6;
	test(res, printf(test0, wild, c0), ft_printf(test1, wild, c0));
	test(res, printf(test0, wild, c1), ft_printf(test1, wild, c1));

}