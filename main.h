#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>
# include <stdarg.h>
// #include <io.h>  // win
# include <unistd.h> // wsl

typedef struct t_flags
{
	char type;      // char ex: d i u x X
	int accuracy;   //number
	int width;      // number
	int percent;    // 1 | 0
	int minus;      // 1 | 0
	int space;      // 1 | 0
	int zero;       // 1 | 0
	int error;
} t_flags;

int		ft_get_nbr_len(int nbr, int base);
int		ft_putchar(char c);
void	ft_putnbr(int n);
int		ft_putnbr_di(va_list ap);

#endif