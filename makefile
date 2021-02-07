# All in one

all: clean
	gcc main.c -o main

# Debug file

debug: clean
	gcc -g main.c -o main

# Step by step

preprocessor: cleanpreprocessor
	gcc -E main.c >main_preprocessor.c

compile: cleano
	gcc -c main.c -o main.o

build: cleanbuild
	gcc main.c -o main.exe


# ALL CLEANERS

clean:
	rm -f main

cleanpreprocessor:
	rm -f main_preprocessor.c

cleano:
	rm -f main.o

cleanbuild:
	rm -f main.exe
