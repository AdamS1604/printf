#include "../ft_printf/ft_printf.h"

void	ft_test(char *str)
{
	int i = 0;
	int j = 0;

	// printf("\n");

	// my
	ft_printf("OUT: ");
	i = ft_printf(str, "string");
	printf(" | RETURN: %d", i);
	printf("\n");

	// standart
	printf("OUT: ");
	j = printf(str, "string");
	printf(" | RETURN: %d", j);
	printf("\n");

	// printf("\n");
}

int		main(void)
{
	// ft_test("% 010.d");
	// ft_test("% 010.2d");
	// ft_test("% 10d");
	// ft_test("%10.s");
	ft_test("%.s");

	// сделать функцию которая выводить только n символов строки

	// if ((spec.accuracy < str_len) && (spec.accuracy != -1))
	// занулить все символы которые не нужно выводить
	// будет ли из- за этого лик?

    return (0);
}