#include "../ft_printf/ft_printf.h"

void	ft_test(char *str)
{
	int i = 0;
	int j = 0;

	// printf("\n");

	// my
	ft_printf("OUT: ");
	i = ft_printf(str, 'A');
	printf(" | RETURN: %d", i);
	printf("\n");

	// standart
	printf("OUT: ");
	j = printf(str, 'A');
	printf(" | RETURN: %d", j);
	printf("\n");

	// printf("\n");
}

int		main(void)
{
	ft_test("%1.c");

    return (0);
}