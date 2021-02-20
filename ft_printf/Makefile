# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abronn <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/20 20:00:28 by abronn            #+#    #+#              #
#    Updated: 2021/02/20 20:04:36 by abronn           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
NAME		= libftprintf.a
SRCS		= ft_printf.c handlers_1.c handlers_2.c parser.c utils_lib1.c utils_lib2.c utils_lib3.c utils_lib4.c utils_p.c
OBJS		= $(SRCS:.c=.o)

%.o:	%.c
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
			@ar rcs $(NAME) $(OBJS)
		
all:		$(NAME)

clean:
			@rm -rf $(OBJS)

fclean:		clean
			@rm -rf $(NAME)

re:			fclean all
