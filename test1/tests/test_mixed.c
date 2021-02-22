/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mixed.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolaforg <rolaforg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 16:11:12 by rolaforg          #+#    #+#             */
/*   Updated: 2020/04/06 16:31:44 by rolaforg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"

void    test_mix_spaces(t_res *res)
{
    char *test0 = "[%s, %s, %s]";
    char *test1 = "'%s, %s, %s'";
    char *str0 = NULL;
    char *str1 = "Im a str";
    char *str2 = "Test";

    testing("Mixed strings with mixed spaces");
    test(res, printf(test0, str0, str1, str2), ft_printf(test1, str0, str1, str2));
    test0 = "[%0s, %0s, %0s]";
    test1 = "'%0s, %0s, %0s'";
    test(res, printf(test0, str0, str1, str2), ft_printf(test1, str0, str1, str2));
    test0 = "[%1s, %1s, %1s]";
    test1 = "'%1s, %1s, %1s'";
    test(res, printf(test0, str0, str1, str2), ft_printf(test1, str0, str1, str2));
    test0 = "[%2s, %2s, %2s]";
    test1 = "'%2s, %2s, %2s'";
    test(res, printf(test0, str0, str1, str2), ft_printf(test1, str0, str1, str2));
    test0 = "[%3s, %3s, %3s]";
    test1 = "'%3s, %3s, %3s'";
    test(res, printf(test0, str0, str1, str2), ft_printf(test1, str0, str1, str2));
    test0 = "[%4s, %4s, %4s]";
    test1 = "'%4s, %4s, %4s'";
    test(res, printf(test0, str0, str1, str2), ft_printf(test1, str0, str1, str2));
    test0 = "[%5s, %5s, %5s]";
    test1 = "'%5s, %5s, %5s'";
    test(res, printf(test0, str0, str1, str2), ft_printf(test1, str0, str1, str2));
    test0 = "[%6s, %6s, %6s]";
    test1 = "'%6s, %6s, %6s'";
    test(res, printf(test0, str0, str1, str2), ft_printf(test1, str0, str1, str2));
    test0 = "[%7s, %7s, %7s]";
    test1 = "'%7s, %7s, %7s'";
    test(res, printf(test0, str0, str1, str2), ft_printf(test1, str0, str1, str2));
    test0 = "[%8s, %8s, %8s]";
    test1 = "'%8s, %8s, %8s'";
    test(res, printf(test0, str0, str1, str2), ft_printf(test1, str0, str1, str2));
    test0 = "[%9s, %9s, %9s]";
    test1 = "'%9s, %9s, %9s'";
    test(res, printf(test0, str0, str1, str2), ft_printf(test1, str0, str1, str2));
    test0 = "[%10s, %10s, %10s]";
    test1 = "'%10s, %10s, %10s'";
    test(res, printf(test0, str0, str1, str2), ft_printf(test1, str0, str1, str2));
    test0 = "[%11s, %11s, %11s]";
    test1 = "'%11s, %11s, %11s'";
    test(res, printf(test0, str0, str1, str2), ft_printf(test1, str0, str1, str2));
    test0 = "[%12s, %12s, %12s]";
    test1 = "'%12s, %12s, %12s'";
    test(res, printf(test0, str0, str1, str2), ft_printf(test1, str0, str1, str2));
    test0 = "[%0s, %6s, %12s]";
    test1 = "'%0s, %6s, %12s'";
    test(res, printf(test0, str0, str1, str2), ft_printf(test1, str0, str1, str2));
    test0 = "[%1s, %5s, %11s]";
    test1 = "'%1s, %5s, %11s'";
    test(res, printf(test0, str0, str1, str2), ft_printf(test1, str0, str1, str2));
    test0 = "[%2s, %4s, %10s]";
    test1 = "'%2s, %4s, %10s'";
    test(res, printf(test0, str0, str1, str2), ft_printf(test1, str0, str1, str2));
    test0 = "[%3s, %3s, %9s]";
    test1 = "'%3s, %3s, %9s'";
    test(res, printf(test0, str0, str1, str2), ft_printf(test1, str0, str1, str2));
    test0 = "[%4s, %2s, %8s]";
    test1 = "'%4s, %2s, %8s'";
    test(res, printf(test0, str0, str1, str2), ft_printf(test1, str0, str1, str2));
    test0 = "[%5s, %1s, %7s]";
    test1 = "'%5s, %1s, %7s'";
    test(res, printf(test0, str0, str1, str2), ft_printf(test1, str0, str1, str2));
    test0 = "[%6s, %0s, %6s]";
    test1 = "'%6s, %0s, %6s'";
    test(res, printf(test0, str0, str1, str2), ft_printf(test1, str0, str1, str2));
    test0 = "[%7s, %1s, %5s]";
    test1 = "'%7s, %1s, %5s'";
    test(res, printf(test0, str0, str1, str2), ft_printf(test1, str0, str1, str2));
    test0 = "[%8s, %2s, %4s]";
    test1 = "'%8s, %2s, %4s'";
    test(res, printf(test0, str0, str1, str2), ft_printf(test1, str0, str1, str2));
    test0 = "[%9s, %3s, %4s]";
    test1 = "'%9s, %3s, %4s'";
    test(res, printf(test0, str0, str1, str2), ft_printf(test1, str0, str1, str2));
    test0 = "[%10s, %4s, %3s]";
    test1 = "'%10s, %4s, %3s'";
    test(res, printf(test0, str0, str1, str2), ft_printf(test1, str0, str1, str2));
    test0 = "[%11s, %5s, %2s]";
    test1 = "'%11s, %5s, %2s'";
    test(res, printf(test0, str0, str1, str2), ft_printf(test1, str0, str1, str2));
    test0 = "[%12s, %6s, %1s]";
    test1 = "'%12s, %6s, %1s'";
    test(res, printf(test0, str0, str1, str2), ft_printf(test1, str0, str1, str2));
}