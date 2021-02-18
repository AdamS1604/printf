#include "../ft_printf/ft_printf.h"

void	ft_test(char *str)
{
	int i = 0;
	int j = 0;
	int a  = 5;

	// standart
	printf("OUT: ");
	j = printf(str, 64,",8");
	printf(" | RETURN: %d", j);
	printf("\n");

	// my
	ft_printf("OUT: ");
	i = ft_printf(str, 64,",8");
	printf(" | RETURN: %d", i);
	printf("\n");
}

int		main(void)
{
	// ft_test("%16.*s");
	ft_test("%.3u");
	ft_test("%10.123u");
	ft_test("%4.1u");
	ft_test("%.3u");

    return (0);
}