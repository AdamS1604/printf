#include "../ft_printf/includes/ft_printf.h"
# include <stdio.h>

void	ft_test(char *str)
{
	int i = 0;
	int j = 0;

	// standart
	printf("OUT: ");
	j = printf(str, 0);
	printf(" | RETURN: %d", j);
	printf("\n");

	// my
	ft_printf("OUT: ");
	i = ft_printf(str, 0);
	printf(" | RETURN: %d", i);
	printf("\n");
}

int		main(void)
{
	ft_test("%.p");
    return (0);
}