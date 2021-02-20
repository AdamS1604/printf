#include "../ft_printf/ft_printf.h"
# include <stdio.h>

void	ft_test(char *str)
{
	int i = 0;
	int j = 0;
	int a  = 5;

	// standart
	printf("OUT: ");
	j = printf(str, 5);
	printf(" | RETURN: %d", j);
	printf("\n");

	// my
	ft_printf("OUT: ");
	i = ft_printf(str, 5);
	printf(" | RETURN: %d", i);
	printf("\n");
}

int		main(void)
{
	ft_test("% 0-10d");
    return (0);
}