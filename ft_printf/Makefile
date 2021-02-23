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

# DIRECTORIES
OBJ_DIR 		= obj
SRC_DIR 		= src
INCLUDESDIR 	= includes
LIBFT_DIR 		= libft
HANDLERS_DIR	= handlers

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
NAME			= libftprintf.a
LIBFT			= libft.a

# SOURCES
SRCS	=	$(SRC_DIR)/ft_printf.c 						\
			$(SRC_DIR)/parser.c							\
			$(SRC_DIR)/utils.c							\
			$(SRC_DIR)/$(HANDLERS_DIR)/ft_handler_c.c	\
			$(SRC_DIR)/$(HANDLERS_DIR)/ft_handler_s.c	\
			$(SRC_DIR)/$(HANDLERS_DIR)/ft_handler_u.c	\
			$(SRC_DIR)/$(HANDLERS_DIR)/ft_handler_d.c	\
			$(SRC_DIR)/$(HANDLERS_DIR)/ft_handler_p.c	\
			$(SRC_DIR)/$(HANDLERS_DIR)/ft_handler_x.c	

# OBJECTS
OBJS	=	$(OBJ_DIR)/ft_printf.o  					\
			$(OBJ_DIR)/parser.o     					\
			$(OBJ_DIR)/utils.o							\
			$(OBJ_DIR)/$(HANDLERS_DIR)/ft_handler_c.o  	\
			$(OBJ_DIR)/$(HANDLERS_DIR)/ft_handler_s.o  	\
			$(OBJ_DIR)/$(HANDLERS_DIR)/ft_handler_u.o  	\
			$(OBJ_DIR)/$(HANDLERS_DIR)/ft_handler_d.o  	\
			$(OBJ_DIR)/$(HANDLERS_DIR)/ft_handler_p.o  	\
			$(OBJ_DIR)/$(HANDLERS_DIR)/ft_handler_x.o  	

# COLORS
GREEN	= \e[32m
YELLOW	= \e[33m
RED		= \e[31m
PURPLE	= \e[35m
NC		= \e[39m

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/$(HANDLERS_DIR)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -I $(INCLUDESDIR) -c $< -o $@
	@printf "$(PURPLE)compiling$(NC): %-28s ->  %-28s\n" $< $@

$(NAME): $(OBJ_DIR) $(OBJS)
	@make -s -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/$(LIBFT) $(NAME)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(YELLOW)ft_printf:$(RESET) $(GREEN)$(NAME) was created.$(NC)"
		
clean:
	@rm -frd $(OBJ_DIR)
	@make -s -C $(LIBFT_DIR) clean
	@echo "$(YELLOW)ft_printf:$(RESET) $(RED)/obj folder was deleted.$(NC)"

fclean:	clean
	@rm -rf $(NAME)
	@echo "$(YELLOW)ft_printf:$(RESET) $(RED)$(NAME) was deleted.$(NC)"
	@make -s -C $(LIBFT_DIR) fclean

re:	fclean all