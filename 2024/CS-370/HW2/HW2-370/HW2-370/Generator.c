#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 2
#define INITIAL_CAPACITY 10


int checkArguments(int argc, char *argv[]) {
    if (argc != 2) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}


char **getLinesFromFile(const char *filename, int *lineCount) {
    printf("%s", filename);
    printf("\n");
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    char **lines = malloc(INITIAL_CAPACITY * sizeof(char *));
    if (lines == NULL) {
        perror("Error allocating memory");
        fclose(file);
        return NULL;
    }

    size_t capacity = INITIAL_CAPACITY;
    *lineCount = 0; // Initialize the line count

    char line[MAX_LINE_LENGTH]; // Buffer for each line
    while (fgets(line, sizeof(line), file) != NULL) {
        // Resize the array if necessary
        if (*lineCount >= capacity) {
            capacity *= 2;
            lines = realloc(lines, capacity * sizeof(char *));
            if (lines == NULL) {
                perror("Error reallocating memory");
                fclose(file);
                return NULL;
            }
        }

        // Allocate memory for the new line and copy it
        lines[*lineCount] = malloc(strlen(line) + 1);
        if (lines[*lineCount] == NULL) {
            perror("Error allocating memory for line");
            fclose(file);
            return NULL;
        }
        strcpy(lines[*lineCount], line);
        (*lineCount)++;
    }

    fclose(file);
    return lines; // Return the array of lines
}


int main(int argc, char *argv[]) {
    if (checkArguments(argc, argv) == EXIT_FAILURE) {
        return EXIT_FAILURE;
    }
    
    int lineCount;
    char **lines = getLinesFromFile(argv[1], &lineCount);

    if (lines != NULL) {
        for (int i = 0; i < lineCount; i++) {
            printf("%s", lines[i]);
            free(lines[i]); // Must free each line after use
        }
        free(lines); // must free the array of pointers
    }

    return EXIT_SUCCESS;
}
