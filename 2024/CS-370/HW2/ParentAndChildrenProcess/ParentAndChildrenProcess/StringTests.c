#include <stdio.h>
//contains definitions for input and output functions.
//printf(): Used to print formatted output to the console.
//scanf(): Used to read formatted input from the console.
//fgets(): Reads a string from a file or standard input.
//fprintf(): Prints formatted output to a file.

#include <stdlib.h>
//contains functions for memory allocation, process control, conversions, and other utility functions.
//malloc(): Allocates a block of memory dynamically.
//free(): Deallocates previously allocated memory.
//exit(): Terminates the program.
//atoi(), atof(): Convert strings to integers or floats, respectively.

#include <string.h>
//contains functions for handling and manipulating C strings (arrays of characters).
//strlen(): Returns the length of a string.
//strcpy(): Copies one string to another.
//strcat(): Concatenates two strings.
//strcmp(): Compares two strings for equality.
//strncpy(), strncat(): Safe versions that limit the number of characters copied or concatenated.

int main(int argc, char *argv[]) {
    // Strings are stored as an array of characters
    char emptyMutableString[100]; // contains 99 characters and 1 null character '\0' to signal termination of the string
    char *immutableString = "Hello, World!";
    char mutableString[] = "Hello, World!";
    printf("%s",emptyMutableString);
    printf("%s",immutableString);
    printf("%s",mutableString);
    return 0;
}
