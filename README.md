# c-programming-assignments
A few small projects done in C for COP4338

This is a record of a few C programs I made in COP4338: Advanced Programming. Example outputs of the programs from the command line are listed in the output.txt file within each folder. This is a description of each directory. 

Assignment 1: This program creates a temperature chart based on user input.
Assignment 2: This program approximates the square root of a number using the Babylonian method.
Assignment 3: This program creates a deck of cards, shuffles and deals them.
Assignment 4: Revised version of Assignment, using structs and pointers.
Assignment 5: Two programs Convert and Process. Process will process a list of dates and filter the results which match the format of MM/DD/YYYY. Process will convert the date from MM/DD/YYYY to DAY MONTH YEAR. Ex: 10/01/1995 -> 01 OCT 1995. The output of process can be piped into convert. ex: ./process dates.dat | ./convert >> output.txt. 

Final Assignment: This project receives command line input of unique numbers between 1-9. The child processes will attach to a shared memory and will manipulate the shared memory before detaching and killing themselves. ex: ./forker.out 5 6 7 3 2 1

