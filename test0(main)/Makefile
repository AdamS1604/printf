
INC_DIR = ../ft_printf/includes
SRC_DIR	= ../ft_printf/src
HAN_DIR = ../ft_printf/src/handlers
LIB_DIR = ../ft_printf/libft/src

CC = gcc
DFLAGS = -g -Wall -Werror -Wextra
OUT = main

all: clean
	@$(CC) main.c ../ft_printf/libftprintf.a -o $(OUT)

debug: clean
	@$(CC) $(DFLAGS) -I $(INC_DIR) main.c $(SRC_DIR)/*.c $(LIB_DIR)/*.c $(HAN_DIR)/*.c -o $(OUT)

clean:
	@rm -f $(OUT)