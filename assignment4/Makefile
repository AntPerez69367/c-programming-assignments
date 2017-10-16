#----------------------------------------------------------
# Makefile for Assignment 4: Stud Poker                   |
# Written by: Anthony Perez                               |
#----------------------------------------------------------

# Set Compiler to use gcc
#----------------------------------------------------------
CC = gcc

# Files to be compiled, deck.h must be present in main dir.
# ---------------------------------------------------------
FILES = studpokermain.c deck.c

# Executable file output name
# ---------------------------------------------------------
OUT_EXE = cards

# Build program
# ---------------------------------------------------------
build: $(FILES)
		$(CC) -g -o $(OUT_EXE) $(FILES)

# Clean old files
# ---------------------------------------------------------
clean:
		rm -f *.o core

# Clean and Build
# ---------------------------------------------------------
rebuild: clean build

#End of MakeFile ------------------------------------------
