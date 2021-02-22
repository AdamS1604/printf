/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolaforg <rolaforg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 19:20:51 by rolaforg          #+#    #+#             */
/*   Updated: 2020/04/19 14:19:49 by rolaforg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

void header(void)
{
	printf("\033[1;36m");
	printf("------------------------------------------------------------------------\n");
	printf(" 	 	 _____  _____  _____ _   _ _______ ______\n");
	printf("		|  __ \\|  __ \\|_   _| \\ | |__   __|  ____|\n		| |__) | |__) | | | |  \\| |  | |  | |__   \n		|  ___/|  _  /  | | | . ` |  | |  |  __|  \n		| |    | | \\ \\ _| |_| |\\  |  | |  | |     \n		|_|    |_|  \\_\\_____|_| \\_|  |_|  |_| Tester (v1.8)    \n");
	printf("\033[4;33mBy rolaforg\033[0m\n");
	printf("\033[1;36m------------------------------------------------------------------------\033[0m\n\n");
	printf("\033[7;49mLégende:\033[0m\n");
	printf("ft_printf: '', printf: [] \n\n");
}

void test(t_res *res, int one, int two)
{
	int size = 0;
	int sepSize = 45;
	if (one == two)
	{
		size = sepSize - one - two;
		printf("%*s", size, "\033[0;32m [OK]\033[0m\n");
		res->ok += 1;
	}
	else
	{
		size = sepSize - one - two;
		printf(" \033[0;31m [FAIL]\033[0m expected: %d, returned: %d\n", one, two);
		res->fail += 1;
	}
}

void testing(char *str)
{
	printf("\n \033[4;95mTesting %s :\033[0m\n", str);
}