SRC = main.c main_utils.c

# All in one

all: clean
	gcc $(SRC) -o main


# Debug file

debug: clean
	gcc -g $(SRC) -o main

# ALL CLEANERS

clean:
	rm -f main