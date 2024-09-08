#include <stdio.h>
#include <stdlib.h>
#include "Primes.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <seed>\n", argv[0]);
        return 1;
    }

    int seed = atoi(argv[1]);
    srand(seed);
    printf("[Driver]: random with seed: %d\n", seed);

    float avg_ratio = get_running_ratio();
    printf("[Driver]: Average prime ratio: %.6f\n", avg_ratio);

    return 0;
}
