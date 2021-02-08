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

int		ft_putchar(char c)
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

int		ft_putnbr_di(va_list ap)
{
	int nbr;

	nbr = va_arg(ap, int);
	ft_putnbr(nbr);
	return (ft_get_nbr_len(nbr, 10));
}

int ft_parser(va_list ap, const char **format)
{
	int len;

	len = 0;
	(*format)++;
	if ((**format == 'd') || (**format == 'i'))
		len += ft_putnbr_di(ap);
	else if (**format == '%')
		len += ft_putchar('%');
	// или так - или выводить не по символьно а по строкам (может объединить это условие и условие выше?)
	else
		len += ft_putchar('%');
	//чтобы не зайти за строку если % последний символ
	if (**format != '\0')
		(*format)++;
	return (len);
}

int		ft_print_all(va_list ap, const char *format)
{
	t_flags flags;
	int len;

	len = 0;
	while (*format)
		if ((*format == '%')) // && следуюий символ не конец строки
			// if ((ft_parser(ap, &format)) < 0)
			// 	return (-1); ???
			len += ft_parser(ap, &format);
		else
			len += ft_putchar(*(format++));
	return (len);
}

int		ft_printf(const char *format, ...)
{
    va_list ap;
	int len;

	if (!format)
		return (-1);
	va_start(ap, format);
	//если ошибка с маллоком то len = -1 (сделать это)
	len = ft_print_all(ap, format);
	va_end(ap);
	return (len);
}

int		main()
{
	int i = 0;
	int j = 0;
	char test_str[] = "test %t7g4s test";

	// ft_printf
	// printf("FT_PRINTF: ");
    i = ft_printf(test_str, 123);
    // printf(" | RETURN: %d", i);
	printf("\n");

	// printf
	// printf("PRINTF   : ");
	j = printf(test_str, 123);
    // printf(" | RETURN: %d", j);
	printf("\n");
    return (0);
}
