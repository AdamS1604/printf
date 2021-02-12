#include "../ft_printf/ft_printf.h"

void	ft_test(char *str)
{
	int i = 0;
	int j = 0;

	// printf("\n");

	// my
	ft_printf("OUT: ");
	i = ft_printf(str, 12);
	printf(" | RETURN: %d", i);
	printf("\n");

	// standart
	printf("OUT: ");
	j = printf(str, 12);
	printf(" | RETURN: %d", j);
	printf("\n");

	// printf("\n");
}

int		main(void)
{
	// ft_test("% 010.d");
	// ft_test("% 010.2d");
	ft_test("% 10d");

    return (0);
}
