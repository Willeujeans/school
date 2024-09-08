#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "Primes.h"

int random_in_range(int lower_bound, int upper_bound)
{
    return 0;
}

bool is_prime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;

    if (num % 2 == 0 || num % 3 == 0) return false;

    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }

    return true;
}

int get_prime_count(int *array, int arraySize)
{
    return 0;
}

float get_running_ratio()
{
    return 0.0;
}