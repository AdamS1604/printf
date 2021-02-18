#include "../ft_printf/ft_printf.h"

void	ft_test(char *str)
{
	int i = 0;
	int j = 0;
	int a  = 5;

	// standart
	printf("OUT: ");
	j = printf(str, "hello", -64,",8");
	printf(" | RETURN: %d", j);
	printf("\n");

	// my
	ft_printf("OUT: ");
	i = ft_printf(str, "hello",-64,",8");
	printf(" | RETURN: %d", i);
	printf("\n");
}

int		main(void)
{
	// ft_test("%16.*s");
	ft_test("%.3s");

    return (0);
}