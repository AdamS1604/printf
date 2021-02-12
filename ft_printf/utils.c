#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (*(str++))
		i++;
	return (i);
}

int		ft_zero_len(const char *format)
{
	int len;

	len = 0;
	while (*format == '0')
	{
		format++;
		len++;
	}
	return (len);
}

int		ft_print_char_times(int i, char c)
{
	int len;

	len = i;
	while (i-- > 0)
		ft_putchar(c);
	return (len);
}

void	ft_init_spec(t_spec **spec)
{
	(*spec)->flag = '_';     // x -none '0'/'-'/' '
	(*spec)->space = 0;      
	(*spec)->width = 0;
	(*spec)->accuracy = -1;
	(*spec)->type = '_';     // char ex: d i u x X 
}

int		ft_get_nbr_len(int nbr, int base)
{
	int len;
	int flag;

	len = 0;
	flag = 0;
	if (nbr == 0)
		return (1);
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

int		ft_putstr(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
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

char    *ft_strchr(const char *s, int c)
{
    while (*s)
        if(*s++ == (char)c)
            return ((char *)s - 1);
    if (c == '\0')
        return ((char *)s);
    return (NULL);
}

int		ft_atoi(const char *str1)
{
	int				flag;
	unsigned char	*str;
	int				i;

	str = (unsigned char *)str1;
	i = 0;
	flag = 0;
	while (((*str == 32) || (*str == '\f') || (*str == '\n'))
	|| ((*str == '\t') || (*str == '\v') || (*str == '\r')))
	{
		str++;
	}
	if (*str == 45)
	{
		flag = 1;
		str++;
	}
	else if (*str == 43)
		str++;
	while ((*str >= 48) && (*str <= 57))
	{
		i = i * 10 + (*str - 48);
		str++;
	}
	return (flag == 0 ? i : -i);
}
