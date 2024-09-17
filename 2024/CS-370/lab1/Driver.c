#include <stdio.h>
#include <stdlib.h>
#include "Primes.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("[Driver]: Seed was not provided");
        return 1;
    }

    int seed = atoi(argv[1]);
    srand(seed);
    printf("[Driver]: Seeding RNG with seed: %d\n", seed);

    float running_ratio = get_running_ratio();
    printf("[Driver]: AVG prime/composite ratio: %.6f\n", running_ratio);
    return 0;
}
