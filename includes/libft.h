/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronn <marvin@42.f>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 14:27:09 by abronn            #+#    #+#             */
/*   Updated: 2020/11/26 21:58:30 by abronn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

int			ft_isalnum(int a);
int			ft_isalpha(int a);
int			ft_isascii(int a);
int			ft_isdigit(int a);
int			ft_isprint(int a);
char		*ft_strchr(char *str, char ch);
size_t		ft_strlen(const char *str);
char		*ft_strrchr(char *str, int a);
int			ft_tolower(int a);
int			ft_toupper(int a);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *destination, const void *source, size_t n);
void		*ft_memset(void *destination, int c, size_t n);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_atoi(const char *str);
void		*ft_memchr(const void *arr, int c, size_t n);
int			ft_memcmp(const void *arr1, const void *arr2, size_t n);
void		*ft_memmove(void *destination, const void *source, size_t n);
void		*ft_calloc(size_t number, size_t size);
void		*ft_memccpy(void *dest, const void *source, int c, size_t n);
char		*ft_strnstr(const char *big, const char *little, size_t len);
char		*ft_strdup(const char *str);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
int 		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char const *s, int fd);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);
size_t		ft_strlcat(char *dest, char const *src, size_t size);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_putendl_fd(char const *s, int fd);
void		ft_putnbr_fd(int n, int fd);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);

char		*ft_itoa_u(unsigned int n, int base, int flag);
char		*ft_itoa_ull(unsigned long long int n, int base);

int		    ft_putstr_len(int len, char *s);
int		    ft_print_char_times(int i, char c);
int		    ft_get_nbr_len(int nbr, int base);
int		    ft_zero_len(const char *format);

#endif
