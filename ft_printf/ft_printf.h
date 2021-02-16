#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h> // memory
# include <stdarg.h>
# include <unistd.h> // wsl
// #include <io.h>   // win

typedef struct t_spec
{
	char flag;      // '-' '0'
	int space;      //  1   0
	int width;      // num or  0
	int accuracy;   // num or -1
	char type;      // '_' or d i u c s p x X
} t_spec;

// utils.c
size_t	ft_strlen(const char *str);
int		ft_zero_len(const char *format);
int		ft_print_char_times(int i, char c);
void	ft_init_spec(t_spec **spec);
int		ft_get_nbr_len(int nbr, int base);
int		ft_putchar(char c);
int		ft_putstr(char const *s);
int		ft_putstr_len(int len, char *s);
void	ft_putnbr(int n);
char    *ft_strchr(const char *s, int c);
int		ft_atoi(const char *str1);
// ...
char		*ft_itoa(int n);
char		*ft_strjoin(char const *s1, char const *s2);

// ft_printf.c
int		ft_handler_ap(va_list ap, const char **format);
int		ft_print_all(va_list ap, const char *format);
int		ft_printf(const char *format, ...);

// parser.c
int		ft_flags_parser(const char **format, t_spec **spec);
int		ft_width_parser(va_list ap, const char **format, t_spec **spec);
int		ft_accuracy_parser(va_list ap, const char **format, t_spec **spec);
int		ft_parser(va_list ap, const char *format, t_spec *spec);

// handler.c
int		ft_handler(va_list ap, t_spec spec);
int		ft_handler_c(va_list ap, t_spec spec);
int		ft_handler_s(va_list ap, t_spec spec);
int		ft_handler_d(va_list ap, t_spec spec);
int		ft_format_out(const char **format, t_spec spec);

#endif