#include "../ft_printf/includes/ft_printf.h"
# include <stdio.h>

void	ft_test(char *str)
{
	int i = 0;
	int j = 0;

	// standart
	printf("OUT: ");
	j = printf(str, 345, 12);
	printf(" | RETURN: %d", j);
	printf("\n");

	// my
	ft_printf("OUT: ");
	i = ft_printf(str, 345, 12);
	printf(" | RETURN: %d", i);
	printf("\n");
}

int		main(void)
{
	ft_test("%d %10d");
    return (0);
}