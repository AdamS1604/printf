# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abronn <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/20 20:00:28 by abronn            #+#    #+#              #
#    Updated: 2021/02/21 01:40:39 by abronn           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJDIR = obj
SRCDIR = src
INCLUDESDIR = includes

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
NAME		= libftprintf.a

SRCS		=	$(SRCDIR)/ft_printf.c \
				$(SRCDIR)/handlers_1.c \
				$(SRCDIR)/handlers_2.c \
				$(SRCDIR)/parser.c \
				$(SRCDIR)/utils_lib1.c \
				$(SRCDIR)/utils_lib2.c \
				$(SRCDIR)/utils_lib3.c \
				$(SRCDIR)/utils_lib4.c \
				$(SRCDIR)/utils_p.c

OBJS		=	$(OBJDIR)/ft_printf.o  \
				$(OBJDIR)/handlers_1.o \
				$(OBJDIR)/handlers_2.o \
				$(OBJDIR)/parser.o     \
				$(OBJDIR)/utils_lib1.o \
				$(OBJDIR)/utils_lib2.o \
				$(OBJDIR)/utils_lib3.o \
				$(OBJDIR)/utils_lib4.o \
				$(OBJDIR)/utils_p.o

$(OBJDIR)/%.o:	$(SRCDIR)/%.c
			$(CC) $(CFLAGS) -I $(INCLUDESDIR) -c $< -o $@

$(NAME):	$(OBJS)
			@ar rcs $(NAME) $(OBJS)
		
all:		$(NAME)

clean:
			@rm -rf $(OBJS)

fclean:		clean
			@rm -rf $(NAME)

re:			fclean all
