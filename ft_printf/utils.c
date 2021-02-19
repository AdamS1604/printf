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

int		ft_putstr_len(int len, char *s)
{
	size_t	i;
	int str_len;

	i = 0;

	// idea: if len == -1 then output full string (len = ft_strlen(s))
	str_len = ft_strlen(s);
	while ((len > i) && (str_len--))
		ft_putchar(s[i++]);
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

//

void	*ft_memcpy(void *destination, const void *source, size_t n)
{
	unsigned char *dest;
	unsigned char *src;

	dest = (unsigned char *)destination;
	src = (unsigned char *)source;
	if (!dest && !src)
		return (0);
	while (n--)
		*(dest++) = *(src++);
	return (destination);
}

char	*ft_strdup(const char *str)
{
	char	*dest;
	char	*src;
	size_t	len;

	src = (char *)str;
	len = ft_strlen(src);
	dest = (char *)malloc(len + 1);
	if (dest == 0)
		return (0);
	return (ft_memcpy(dest, src, len + 1));
}

void	*ft_memmove(void *destination, const void *source, size_t n)
{
	unsigned char *dest;
	unsigned char *src;

	dest = (unsigned char *)destination;
	src = (unsigned char *)source;
	if (!dest && !src)
		return (destination);
	if (src < dest)
		while (n--)
			dest[n] = src[n];
	else
		while (n--)
			*(dest++) = *(src++);
	return (destination);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l1;
	size_t	l2;
	char	*ptr;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && s2)
		return (ft_strdup(s2));
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	ptr = malloc(l1 + l2 + 1);
	if (!ptr)
		return (0);
	ft_memmove(ptr, s1, l1);
	ft_memmove(ptr + l1, s2, l2);
	ptr[l1 + l2] = '\0';
	return (ptr);
}

//

char	*ft_strupcase(char *str)
{
	char *i;

	i = str;
	while (*str != '\0')
	{
		if ((*str >= 65) && (*str <= 90))
		{
			*str = *str + 32;
		}
		str++;
	}
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
		*(ptr++) = '\0';
}

void	*ft_calloc(size_t number, size_t size)
{
	void	*ptr;

	ptr = (void*)malloc(number * size);
	if (!ptr)
		return (0);
	ft_bzero(ptr, number * size);
	return (ptr);
}

// ! static ?
static size_t	init_size_u(unsigned int n, int base)
{
	size_t	size;

	size = 1;
	while (n / base)
	{
		n /= base;
		size++;
	}
	return (size);
}

char			*ft_itoa_u(unsigned int n, int base, int flag)
{
	unsigned int		num;
	char				*str;
	size_t				size;
	const char			*arr_base;

	size = init_size_u(n, base);
	num = n;
	if (!(str = (char*)ft_calloc(size + 1, 1)))
		return (0);
	if (flag == 1)
		arr_base = "0123456789ABCDEF";
	else
		arr_base = "0123456789abcdef";
	while (size > 0)
	{
		*(str + --size) = *(arr_base + (num % base));
		num /= base;
	}
	return (str);
}

// ! static ?
static size_t	init_size_ull(unsigned long long int n, int base)
{
	size_t	size;

	size = 1;
	while (n / base)
	{
		n /= base;
		size++;
	}
	return (size);
}

char			*ft_itoa_ull(unsigned long long int n, int base)
{
	unsigned long long int		num;
	char						*str;
	size_t						size;
	char						*base_arr;

	size = init_size_ull(n, base);
	num = n;
	if (!(str = (char*)ft_calloc(size + 1, sizeof(char))))
		return (str);
	base_arr = "0123456789abcdef";
	while (size > 0)
	{
		*(str + --size) = *(base_arr + (num % base));
		num /= base;
	}
	return (str);
}

// ! void ??? or returns smth
char	*ft_str_add_accuracy(va_list ap, t_spec spec, char *nbr_str)
{
	int nbr_len;
	char *new_str;
	char *tmp;
	int i;
	int k;

	nbr_len = ft_strlen(nbr_str);
	if (spec.accuracy > nbr_len)
	{
		// todo need errors in this ft in 2 places
		i = spec.accuracy - nbr_len;
		k = 0;
		if (!(new_str = (char *)ft_calloc(spec.accuracy + 1, sizeof(char))))
			return (0);
		while (i--)
			new_str[k++] = '0';
		tmp = nbr_str;
		nbr_str = ft_strjoin(new_str, nbr_str);
		free(tmp);
		free(new_str);
	}
	return (nbr_str);
}
