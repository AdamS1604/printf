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

OBJ_DIR 	= obj
SRC_DIR 	= src
INCLUDESDIR = includes
LIBFT_DIR 	= libft

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
NAME		= libftprintf.a
LIBFT		= libft.a

# optimise theese
SRCS		=	$(SRC_DIR)/ft_printf.c \
				$(SRC_DIR)/handlers_1.c \
				$(SRC_DIR)/handlers_2.c \
				$(SRC_DIR)/parser.c \
				$(SRC_DIR)/utils_p.c

OBJS		=	$(OBJ_DIR)/ft_printf.o  \
				$(OBJ_DIR)/handlers_1.o \
				$(OBJ_DIR)/handlers_2.o \
				$(OBJ_DIR)/parser.o     \
				$(OBJ_DIR)/utils_p.o

GREEN		= \033[0;32m

YELLOW		= \033[0;33m

RED			= \033[0;31m

RESET		= \033[0m

all				:	$(NAME)

$(OBJ_DIR):
				@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o	:	$(SRC_DIR)/%.c
				@$(CC) $(CFLAGS) -I $(INCLUDESDIR) -c $< -o $@

$(NAME)			:	$(OBJ_DIR) $(OBJS)
				@make -C $(LIBFT_DIR)
				@cp $(LIBFT_DIR)/$(LIBFT) $(NAME)
				@ar rcs $(NAME) $(OBJS)
				@echo "$(YELLOW)ft_printf:$(RESET) $(GREEN)$(NAME) was created.$(RESET)"
		
clean			:
				@make -C $(LIBFT_DIR) clean
				@rm -frd $(OBJ_DIR)
				@echo "$(YELLOW)ft_printf:$(RESET) $(RED)/obj folder was deleted.$(RESET)"

fclean			:	clean
				@make -C $(LIBFT_DIR) fclean
				@rm -rf $(NAME)
				@echo "$(YELLOW)ft_printf:$(RESET) $(RED)$(NAME) was deleted.$(RESET)"

re				:	fclean all