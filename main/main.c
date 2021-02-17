#include "../ft_printf/ft_printf.h"

void	ft_test(char *str, int n)
{
	int i = 0;
	int j = 0;

	// standart
	printf("OUT: ");
	j = printf(str, n);
	printf(" | RETURN: %d", j);
	printf("\n");

	// my
	ft_printf("OUT: ");
	i = ft_printf(str, n);
	printf(" | RETURN: %d", i);
	printf("\n");
}

int		main(void)
{
	// ft_test("% d", -200);        // good
	// ft_test("%d", -200);         // good
	// ft_test("% 10d", -200);      // good
	// ft_test("% 10.d", -200);     // good
	// ft_test("% 0.d", -200);
	// ft_test("%0 20.10d", -200);
	// ft_test("%010.5d", -10);
	// ft_test("%5d", -2562);


	// ft_test("%d", 5);
	// ft_test("%5d", 5);
	// ft_test("%05d", 5);
	// ft_test("%-5d", 5);
	// ft_test("% -5d", 5);
	// ft_test("% 05d", 5);

	// ft_test("%d", -5);
	// ft_test("%5d", -5);
	// ft_test("%05d", -5);
	// ft_test("%-5d", -5);
	// ft_test("% -5d", -5);
	// ft_test("% 05d", -5);

	// ! NULL
	// ! 0
	// ! %5i", -2562
	// ! %010.5i", -216 

    return (0);
}