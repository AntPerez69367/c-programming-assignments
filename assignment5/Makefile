#----------------------------------------------------------
# Makefile for Assignment 5: Date Converter               |
# Written by: Anthony Perez                               |
#----------------------------------------------------------

# Set Compiler to use gcc
#----------------------------------------------------------
CC = gcc

# Files to be compiled, process.h and convert.h must be present in main dir.
# ---------------------------------------------------------
FILES1 = process.c process_funcs.c
FILES2 = convert.c convert_funcs.c

# Executable file output name
# ---------------------------------------------------------
OUT_EXE1 = process
OUT_EXE2 = convert

# Build program
# ---------------------------------------------------------
build: $(FILES1) $(FILES2)
		$(CC) -o $(OUT_EXE1) $(FILES1)
		$(CC) -o $(OUT_EXE2) $(FILES2)

# Clean old files
# ---------------------------------------------------------
clean:
		rm -f *.o core

# Clean and Build
# ---------------------------------------------------------
rebuild: clean build

#End of MakeFile ------------------------------------------
