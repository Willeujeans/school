#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// This code will run along side the main process
// This allows us to execute a totally different program
// At the SAME TIME this program is running
// But then be able to return the results from that other program!!!!!!
int childProcess(int number){
    printf("Child Process is here!");
    
    char *numberArgument; // Pointer for dynamic allocation
    int length = snprintf(NULL, 0, "%d", number); // Get length of number as string
    numberArgument = (char *)malloc(length + 1); // Allocate memory (+1 for null terminator)
    
    // Execute the Fibonacci program
    int result = execl("./Fibonacci", "./Fibonacci", numberArgument, (char *)NULL);

    perror("execl failed");
    free(numberArgument); // Free allocated memory (though this line may not be reached)
    exit(1);
    return result;
}

int parentProcess(int number){
    printf("Parent Process is here!");
    return EXIT_SUCCESS;
}

int executeChild(char *programPath, int number){
    // Create a child process
    // both processes continue after the fork() was called
    pid_t pid = fork();
    // that means pid will equal two different things in the two different processes
    
    if (pid < 0) {
        // Fork returns -1 on failure
        perror("fork failed");
        exit(1);
    } else if (pid == 0) {
        return childProcess(number);
    } else {
        parentProcess(number);
    }
    return 0;
}

int stringLen(char *str){
    int length = 0;
    while (*str != '\0'){
        length++;
        str++;
    }
    return length;
}

int createChildrenProcessFromFile(char *fileName){
    // File will be opened as read
    FILE *file = fopen(fileName, "r");
    if (!file) {
        perror("Failed to open file");
        return EXIT_FAILURE;
    }

    // Line Buffer
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        // ASCII to number conversion
        int lineAsNumber = atoi(line);
        int len = stringLen(line);
        
        // Replacing newline with termination for correct output formatting
        char newLine = '\n';
        char terminator = '\0';
        if (len > 0 && line[len - 1] == newLine) {
            // Replace the newline character with null terminator character
            line[len - 1] = terminator;
        }
        
        printf("===========================================\n");
        printf("Generator Process: Processing line \"%s\"", line);
        printf("\n===========================================\n");
        printf("DEBUG: The number is: %d\n", lineAsNumber);
        
        // Execute Fibonacci
        int fibonacciResult = executeChild("./Fibonacci", lineAsNumber);
        printf("Child returned: %d\n", fibonacciResult);
        
        // Execute Perrin, passing the result of Fibonacci
//        executeChild("./Perrin", n);
        // Execute Composite, passing the result of Perrin
//        executeChild("./Composite", n);
    }

    fclose(file);
    return EXIT_SUCCESS;
}

int main(int argc, char *argv[]) {
    // input validation
    if (argc != 2) {
        return EXIT_FAILURE;
    }
    char *fileName = argv[1];
    return createChildrenProcessFromFile(fileName);
}
