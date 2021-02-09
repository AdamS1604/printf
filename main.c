#include "main.h"

void ft_init_flags(t_flags **flags)
{
	(*flags)->type = '0';     // char ex: d i u x X
	(*flags)->accuracy = 0;   //number
	(*flags)->width = 0;      // number
	(*flags)->percent = 0;    // 1 | 0
	(*flags)->minus = 0;      // 1 | 0
	(*flags)->space = 0;      // 1 | 0
	(*flags)->zero = 0;       // 1 | 0
}

void ft_parser(const char **format, t_flags *flags)
{
	(*format)++;
	ft_init_flags(&flags);
	if ((**format == 'd') || (**format == 'i'))
		flags->type = 'd';
	else if (**format == '%')
		flags->percent = 1;
}

int ft_handler_ap(va_list ap, const char **format)
{
	int len;
	t_flags flags;

	ft_parser(format, &flags);
	if (flags.type == 'd')
		len += ft_putnbr_di(ap);
	else if (flags.percent == 1)
		len += ft_putchar('%');

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
		if ((*format == '%'))
			len += ft_handler_ap(ap, &format);
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
	char test_str[] = "test %d test";

	// ft_printf
	// printf("FT_PRINTF: ");
    i = ft_printf(test_str, 3451);
    // printf(" | RETURN: %d", i);
	printf("\n");

	// printf
	// printf("PRINTF   : ");
	j = printf(test_str, 3451);
    // printf(" | RETURN: %d", j);
	printf("\n");
    return (0);
}