/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mix_options.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolaforg <rolaforg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 16:11:12 by rolaforg          #+#    #+#             */
/*   Updated: 2020/04/06 16:36:49 by rolaforg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"

void    test_mix_options(t_res *res)
{
    char *test0 = "[%0s, %0s, %0s]";
    char *test1 = "'%0s, %0s, %0s'";
    char *str0 = NULL;
    char *str1 = "Im a str";
    char *str2 = "Test";

    testing("Mixed strings with mixed options");
    test(res, printf(test0, str0, str1, str2), ft_printf(test1, str0, str1, str2));
    test0 = "[%01s, %-1s, %.1s]";
    test1 = "'%01s, %-1s, %.1s'";
    test(res, printf(test0, str0, str1, str2), ft_printf(test1, str0, str1, str2));
    test0 = "[%.2s, %02s, %-2s]";
    test1 = "'%.2s, %02s, %-2s'";
    test(res, printf(test0, str0, str1, str2), ft_printf(test1, str0, str1, str2));
    test0 = "[%-3s, %.3s, %03s]";
    test1 = "'%-3s, %.3s, %03s'";
    test(res, printf(test0, str0, str1, str2), ft_printf(test1, str0, str1, str2));
    test0 = "[%-4s, %04s, %.4s]";
    test1 = "'%-4s, %04s, %.4s'";
    test(res, printf(test0, str0, str1, str2), ft_printf(test1, str0, str1, str2));
    test0 = "[%.5s, %-5s, %05s]";
    test1 = "'%.5s, %-5s, %05s'";
    test(res, printf(test0, str0, str1, str2), ft_printf(test1, str0, str1, str2));
    test0 = "[%06s, %.6s, %-6s]";
    test1 = "'%06s, %.6s, %-6s'";
    test(res, printf(test0, str0, str1, str2), ft_printf(test1, str0, str1, str2));
    test0 = "[%07s, %-7s, %.7s]";
    test1 = "'%07s, %-7s, %.7s'";
    test(res, printf(test0, str0, str1, str2), ft_printf(test1, str0, str1, str2));
    test0 = "[%.8s, %08s, %-8s]";
    test1 = "'%.8s, %08s, %-8s'";
    test(res, printf(test0, str0, str1, str2), ft_printf(test1, str0, str1, str2));
    test0 = "[%-9s, %.9s, %09s]";
    test1 = "'%-9s, %.9s, %09s'";
    test(res, printf(test0, str0, str1, str2), ft_printf(test1, str0, str1, str2));
    test0 = "[%-10s, %010s, %.10s]";
    test1 = "'%-10s, %010s, %.104s'";
    test(res, printf(test0, str0, str1, str2), ft_printf(test1, str0, str1, str2));
    test0 = "[%.11s, %-11s, %011s]";
    test1 = "'%.11s, %-11s, %011s'";
    test(res, printf(test0, str0, str1, str2), ft_printf(test1, str0, str1, str2));
    test0 = "[%012s, %.12s, %-12s]";
    test1 = "'%012s, %.12s, %-12s'";
    test(res, printf(test0, str0, str1, str2), ft_printf(test1, str0, str1, str2));
}