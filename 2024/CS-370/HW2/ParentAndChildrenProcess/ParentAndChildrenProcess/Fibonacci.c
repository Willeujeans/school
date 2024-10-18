#include <stdio.h>
#include <stdlib.h>

int fib(int n){
    int a = 0, b = 1, c, i;
    if (n == 0)
        return a;
    for (i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main(int argc, char *argv[]){
    if (argc != 2){
        return EXIT_FAILURE;
    }
    int number = atoi(argv[1]);
    printf("Fibonacci: %d\n", number);
    return fib(number);
}
