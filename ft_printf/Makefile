SRCS = *.c
OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a

all: clean $(NAME)

$(NAME): $(OBJS)
	ar -rcv $@ $^

$(OBJS):
	gcc -c $(SRCS)

clean:
	rm -f $(OBJS)