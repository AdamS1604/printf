/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolaforg <rolaforg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 16:11:12 by rolaforg          #+#    #+#             */
/*   Updated: 2020/04/06 16:31:34 by rolaforg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"

void    test_mix(t_res *res)
{
    char *test0 = "[%0s, %0s, %0s]";
    char *test1 = "'%0s, %0s, %0s'";
    char *str0 = NULL;
    char *str1 = "Im a str";
    char *str2 = "Test";

    testing("Mixed String");
    test(res, printf(test0, str0, str1, str2), ft_printf(test1, str0, str1, str2));
    test0 = "[%01s, %01s, %01s]";
    test1 = "'%01s, %01s, %01s'";
    test(res, printf(test0, str0, str1, str2), ft_printf(test1, str0, str1, str2));
    test0 = "[%02s, %02s, %02s]";
    test1 = "'%02s, %02s, %02s'";
    test(res, printf(test0, str0, str1, str2), ft_printf(test1, str0, str1, str2));
    test0 = "[%03s, %03s, %03s]";
    test1 = "'%03s, %03s, %03s'";
    test(res, printf(test0, str0, str1, str2), ft_printf(test1, str0, str1, str2));
    test0 = "[%04s, %04s, %04s]";
    test1 = "'%04s, %04s, %04s'";
    test(res, printf(test0, str0, str1, str2), ft_printf(test1, str0, str1, str2));
    test0 = "[%05s, %05s, %05s]";
    test1 = "'%05s, %05s, %05s'";
    test(res, printf(test0, str0, str1, str2), ft_printf(test1, str0, str1, str2));
    test0 = "[%06s, %06s, %06s]";
    test1 = "'%06s, %06s, %06s'";
    test(res, printf(test0, str0, str1, str2), ft_printf(test1, str0, str1, str2));
    test0 = "[%07s, %07s, %07s]";
    test1 = "'%07s, %07s, %07s'";
    test(res, printf(test0, str0, str1, str2), ft_printf(test1, str0, str1, str2));
    test0 = "[%08s, %08s, %08s]";
    test1 = "'%08s, %08s, %08s'";
    test(res, printf(test0, str0, str1, str2), ft_printf(test1, str0, str1, str2));
    test0 = "[%09s, %09s, %09s]";
    test1 = "'%09s, %09s, %09s'";
    test(res, printf(test0, str0, str1, str2), ft_printf(test1, str0, str1, str2));
    test0 = "[%010s, %010s, %010s]";
    test1 = "'%010s, %010s, %010s'";
    test(res, printf(test0, str0, str1, str2), ft_printf(test1, str0, str1, str2));
    test0 = "[%011s, %011s, %011s]";
    test1 = "'%011s, %011s, %011s'";
    test(res, printf(test0, str0, str1, str2), ft_printf(test1, str0, str1, str2));
    test0 = "[%012s, %012s, %012s]";
    test1 = "'%012s, %012s, %012s'";
    test(res, printf(test0, str0, str1, str2), ft_printf(test1, str0, str1, str2));
}