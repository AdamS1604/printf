#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>
# include <stdarg.h>
// #include <io.h>  // win
# include <unistd.h> // wsl


typedef struct t_spec
{
	char flag;      // '-' '0'
	int space;      // ' '
	int width;      // number or -1 (*)
	int accuracy;   // number or -1 (*)
	char type;      // char ex: d i u x X
} t_spec;

int		ft_get_nbr_len(int nbr, int base);
int		ft_putchar(char c);
void	ft_putnbr(int n);
int		ft_putnbr_di(va_list ap);
char    *ft_strchr(const char *s, int c);

#endif