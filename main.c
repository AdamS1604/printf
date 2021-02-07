#include <stdio.h>
#include <stdarg.h>
// #include <io.h>
#include <unistd.h>


typedef struct t_flags
{
	int test;
} t_flags;

int		ft_get_nbr_len(int nbr, int base)
{
	int len;
	int flag;

	len = 0;
	flag = 0;
	if (nbr < 0)
		flag++;
	while (nbr)
	{
		len++;
		nbr /= base;
	}
	if (flag)
		len++;
	return (len);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		if (n <= -10)
			ft_putnbr(n / -10);
		ft_putchar(-(n % 10) + '0');
	}
	else if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putchar((n % 10) + '0');
	}
	else
		ft_putchar(n + '0');
}

int ft_putnbr_di(va_list ap)
{
	int nbr;

	nbr = va_arg(ap, int);
	ft_putnbr(nbr);
	return (ft_get_nbr_len(nbr, 10));
}

int		ft_print_all(va_list ap, char *format)
{
	int len;

	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if ((*format == 'd') || (*format == 'i'))
				len += ft_putnbr_di(ap);

			format++;
		}
		else
			len += ft_putchar(*(format++));
	}
	return (len);
}

int		ft_printf(char *format, ...)
{
    va_list ap;
	int len;

	va_start(ap, format);
	len = ft_print_all(ap, format);
	va_end(ap);
	return (len);
}

int		main()
{
	int i = 0;
	int j = 0;
	char test_str[] = "test %d number";

	// printf("FT_PRINTF: ");
    i = ft_printf(test_str, 123);
    // printf(" | RETURN: %d", i);
	printf("\n");

	// printf("PRINTF   : ");
	j = printf(test_str, 123);
	printf("\n");
    // printf(" | RETURN: %d", j);
    return (0);
}
