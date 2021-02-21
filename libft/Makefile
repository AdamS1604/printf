# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abronn <marvin@42.f>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/13 20:57:18 by abronn            #+#    #+#              #
#    Updated: 2020/11/26 21:58:40 by abronn           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# DIRECTRIES
SRC_DIR = src
INC_DIR = ../includes
OBJ_DIR = obj

CC = gcc
FLAGS = -Wall -Werror -Wextra
NAME = libft.a

# SOURCES
SRC = 	$(SRC_DIR)/ft_split.c 		\
		$(SRC_DIR)/ft_strtrim.c 	\
		$(SRC_DIR)/ft_strmapi.c 	\
		$(SRC_DIR)/ft_itoa.c 		\
		$(SRC_DIR)/ft_putnbr_fd.c 	\
		$(SRC_DIR)/ft_putendl_fd.c 	\
		$(SRC_DIR)/ft_putstr_fd.c 	\
		$(SRC_DIR)/ft_putchar_fd.c 	\
		$(SRC_DIR)/ft_strjoin.c 	\
		$(SRC_DIR)/ft_strncmp.c 	\
		$(SRC_DIR)/ft_substr.c 		\
		$(SRC_DIR)/ft_strdup.c 		\
		$(SRC_DIR)/ft_calloc.c 		\
		$(SRC_DIR)/ft_strnstr.c 	\
		$(SRC_DIR)/ft_strrchr.c 	\
		$(SRC_DIR)/ft_strchr.c 		\
		$(SRC_DIR)/ft_strlcat.c 	\
		$(SRC_DIR)/ft_strlcpy.c 	\
		$(SRC_DIR)/ft_memcmp.c 		\
		$(SRC_DIR)/ft_memchr.c 		\
		$(SRC_DIR)/ft_memmove.c 	\
		$(SRC_DIR)/ft_memccpy.c 	\
		$(SRC_DIR)/ft_memcpy.c 		\
		$(SRC_DIR)/ft_bzero.c 		\
		$(SRC_DIR)/ft_atoi.c 		\
		$(SRC_DIR)/ft_isalnum.c 	\
		$(SRC_DIR)/ft_isalpha.c 	\
		$(SRC_DIR)/ft_isascii.c 	\
		$(SRC_DIR)/ft_isdigit.c 	\
		$(SRC_DIR)/ft_isprint.c 	\
		$(SRC_DIR)/ft_strlen.c 		\
		$(SRC_DIR)/ft_tolower.c 	\
		$(SRC_DIR)/ft_toupper.c 	\
		$(SRC_DIR)/ft_memset.c 		\
		$(SRC_DIR)/ft_itoa_u.c 		\
		$(SRC_DIR)/ft_itoa_ull.c 	\
		$(SRC_DIR)/ft_putstr_len.c 	\
		$(SRC_DIR)/ft_print_char_times.c 	\
		$(SRC_DIR)/ft_get_nbr_len.c \
		$(SRC_DIR)/ft_zero_len.c \

# OBJECTS
OBJ = 	$(OBJ_DIR)/ft_split.o 		\
		$(OBJ_DIR)/ft_strtrim.o 	\
		$(OBJ_DIR)/ft_strmapi.o 	\
		$(OBJ_DIR)/ft_itoa.o 		\
		$(OBJ_DIR)/ft_putnbr_fd.o 	\
		$(OBJ_DIR)/ft_putendl_fd.o 	\
		$(OBJ_DIR)/ft_putstr_fd.o 	\
		$(OBJ_DIR)/ft_putchar_fd.o 	\
		$(OBJ_DIR)/ft_strjoin.o 	\
		$(OBJ_DIR)/ft_strncmp.o 	\
		$(OBJ_DIR)/ft_substr.o 		\
		$(OBJ_DIR)/ft_strdup.o 		\
		$(OBJ_DIR)/ft_calloc.o 		\
		$(OBJ_DIR)/ft_strnstr.o 	\
		$(OBJ_DIR)/ft_strrchr.o 	\
		$(OBJ_DIR)/ft_strchr.o 		\
		$(OBJ_DIR)/ft_strlcat.o 	\
		$(OBJ_DIR)/ft_strlcpy.o 	\
		$(OBJ_DIR)/ft_memcmp.o 		\
		$(OBJ_DIR)/ft_memchr.o 		\
		$(OBJ_DIR)/ft_memmove.o 	\
		$(OBJ_DIR)/ft_memccpy.o 	\
		$(OBJ_DIR)/ft_memcpy.o 		\
		$(OBJ_DIR)/ft_bzero.o 		\
		$(OBJ_DIR)/ft_atoi.o 		\
		$(OBJ_DIR)/ft_isalnum.o 	\
		$(OBJ_DIR)/ft_isalpha.o 	\
		$(OBJ_DIR)/ft_isascii.o 	\
		$(OBJ_DIR)/ft_isdigit.o 	\
		$(OBJ_DIR)/ft_isprint.o 	\
		$(OBJ_DIR)/ft_strlen.o 		\
		$(OBJ_DIR)/ft_tolower.o 	\
		$(OBJ_DIR)/ft_toupper.o 	\
		$(OBJ_DIR)/ft_memset.o 		\
		$(OBJ_DIR)/ft_itoa_u.o 		\
		$(OBJ_DIR)/ft_itoa_ull.o 	\
		$(OBJ_DIR)/ft_putstr_len.o 	\
		$(OBJ_DIR)/ft_print_char_times.o 	\
		$(OBJ_DIR)/ft_get_nbr_len.o \
		$(OBJ_DIR)/ft_zero_len.o \

# COLORS
GREEN		= \033[0;32m
YELLOW		= \033[0;33m
RED			= \033[0;31m
RESET		= \033[0m

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) -c $(FLAGS) -I $(INC_DIR) $< -o $@

$(NAME): $(OBJ_DIR) $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "$(YELLOW)libft    :$(RESET) $(GREEN)$(NAME) was created.$(RESET)"

clean:
	@rm -frd $(OBJ_DIR)
	@echo "$(YELLOW)libft    :$(RESET) $(RED)/obj folder was deleted.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(YELLOW)libft    :$(RESET) $(RED)$(NAME) was deleted.$(RESET)"

re: fclean all
