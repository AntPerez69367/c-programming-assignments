CC = gcc
FILES = main.c validate.c deck.c deck.h
OUT_EXE = cards

build: $(FILES)
		$(CC) -o $(OUT_EXE) $(FILES)

clean:
		rm -f *.o core

rebuild: clean build
