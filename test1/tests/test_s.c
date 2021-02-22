/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolaforg <rolaforg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 12:57:50 by rolaforg          #+#    #+#             */
/*   Updated: 2020/04/06 19:23:09 by rolaforg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"

void test_s(t_res *res)
{
    char	*str0 = (char *)NULL;
	char	*str1 = "Test";
    char *test0 = "[%s]";
	char *test1 = "'%s'";
	int wild = 3;

    testing("%s");
	test(res, printf("[Test]"), ft_printf("'Test'"));
	test(res, printf(test0, str0), ft_printf(test1, str0));
	test(res, printf(test0, str1), ft_printf(test1, str1));
	testing("%(3>6)s");
	test0 = "[%3s]";
	test1 = "'%3s'";
	test(res, printf(test0, str0), ft_printf(test1, str0));
	test(res, printf(test0, str1), ft_printf(test1, str1));
	test0 = "[%4s]";
	test1 = "'%4s'";
	test(res, printf(test0, str0), ft_printf(test1, str0));
	test(res, printf(test0, str1), ft_printf(test1, str1));
	test0 = "[%5s]";
	test1 = "'%5s'";
	test(res, printf(test0, str0), ft_printf(test1, str0));
	test(res, printf(test0, str1), ft_printf(test1, str1));
	test0 = "[%6s]";
	test1 = "'%6s'";
	test(res, printf(test0, str0), ft_printf(test1, str0));
	test(res, printf(test0, str1), ft_printf(test1, str1));
	testing("%0(3>6)s");
	test0 = "[%03s]";
	test1 = "'%03s'";
	test(res, printf(test0, str0), ft_printf(test1, str0));
	test(res, printf(test0, str1), ft_printf(test1, str1));
	test0 = "[%04s]";
	test1 = "'%04s'";
	test(res, printf(test0, str0), ft_printf(test1, str0));
	test(res, printf(test0, str1), ft_printf(test1, str1));
	test0 = "[%05s]";
	test1 = "'%05s'";
	test(res, printf(test0, str0), ft_printf(test1, str0));
	test(res, printf(test0, str1), ft_printf(test1, str1));
	test0 = "[%06s]";
	test1 = "'%06s'";
	test(res, printf(test0, str0), ft_printf(test1, str0));
	test(res, printf(test0, str1), ft_printf(test1, str1));
	testing("%.(3>6)s");
	test0 = "[%.3s]";
	test1 = "'%.3s'";
	test(res, printf(test0, str0), ft_printf(test1, str0));
	test(res, printf(test0, str1), ft_printf(test1, str1));
	test0 = "[%.4s]";
	test1 = "'%.4s'";
	test(res, printf(test0, str0), ft_printf(test1, str0));
	test(res, printf(test0, str1), ft_printf(test1, str1));
	test0 = "[%.5s]";
	test1 = "'%.5s'";
	test(res, printf(test0, str0), ft_printf(test1, str0));
	test(res, printf(test0, str1), ft_printf(test1, str1));
	test0 = "[%.6s]";
	test1 = "'%.6s'";
	test(res, printf(test0, str0), ft_printf(test1, str0));
	test(res, printf(test0, str1), ft_printf(test1, str1));
	testing("%-(3>6)s");
	test0 = "[%-3s]";
	test1 = "'%-3s'";
	test(res, printf(test0, str0), ft_printf(test1, str0));
	test(res, printf(test0, str1), ft_printf(test1, str1));
	test0 = "[%-4s]";
	test1 = "'%-4s'";
	test(res, printf(test0, str0), ft_printf(test1, str0));
	test(res, printf(test0, str1), ft_printf(test1, str1));
	test0 = "[%-5s]";
	test1 = "'%-5s'";
	test(res, printf(test0, str0), ft_printf(test1, str0));
	test(res, printf(test0, str1), ft_printf(test1, str1));
	test0 = "[%-6s]";
	test1 = "'%-6s'";
	test(res, printf(test0, str0), ft_printf(test1, str0));
	test(res, printf(test0, str1), ft_printf(test1, str1));
	testing("%*s (3>6)");
	test0 = "[%*s]";
	test1 = "'%*s'";
	wild = 3;
	test(res, printf(test0, wild, str0), ft_printf(test1, wild, str0));
	test(res, printf(test0, wild, str1), ft_printf(test1, wild, str1));
	wild = 4;
	test(res, printf(test0, wild, str0), ft_printf(test1, wild, str0));
	test(res, printf(test0, wild, str1), ft_printf(test1, wild, str1));
	wild = 5;
	test(res, printf(test0, wild, str0), ft_printf(test1, wild, str0));
	test(res, printf(test0, wild, str1), ft_printf(test1, wild, str1));
	wild = 6;
	test(res, printf(test0, wild, str0), ft_printf(test1, wild, str0));
	test(res, printf(test0, wild, str1), ft_printf(test1, wild, str1));
}