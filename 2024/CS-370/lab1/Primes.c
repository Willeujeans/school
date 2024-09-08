#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Primes.h"

int random_in_range(int lower_bound, int upper_bound)
{
    return (rand() % (upper_bound - lower_bound)) + lower_bound;
}

bool is_prime(int num)
{
    if (num <= 1)
        return false;
    if (num <= 3)
        return true;
    if (num % 2 == 0 || num % 3 == 0)
        return false;
    for (int i = 5; i * i <= num; i += 6)
    {
        if (num % i == 0 || num % (i + 2) == 0)
            return false;
    }
    return true;
}

int get_prime_count(int *array, int arraySize)
{
    int prime_count = 0;
    for (int i = 0; i < arraySize; i++)
    {
        if (is_prime(array[i]))
        {
            prime_count++;
        }
    }
    return prime_count;
}

float get_running_ratio()
{
    int total_iterations = random_in_range(50, 100);
    int max_prime_count = 0;
    int max_count_iteration = 0;
    float sum_ratios = 0.0;

    for (int i = 1; i <= total_iterations; i++)
    {
        int array_size = random_in_range(150, 200);
        int *array = (int *)malloc(array_size * sizeof(int));

        if (array == NULL)
        {
            fprintf(stderr, "[Primes]: Memory allocation failed\n");
            return -1.0;
        }

        for (int j = 0; j < array_size; j++)
        {
            array[j] = random_in_range(50, 200);
        }

        int prime_count = get_prime_count(array, array_size);
        int composite_count = array_size - prime_count;
        float ratio;
        if (composite_count > 0)
        {
            ratio = (float)prime_count / composite_count;
        }
        else
        {
            ratio = 0;
        }
        sum_ratios += ratio;

        if (prime_count > max_prime_count)
        {
            max_prime_count = prime_count;
            max_count_iteration = i;
        }

        free(array);
    }

    printf("[Primes]: Number of iterations is: %d\n", total_iterations);
    printf("[Primes]: Iteration with MAX prime count: %d\n", max_count_iteration);

    if (total_iterations > 0)
    {
        return sum_ratios / total_iterations;
    }
    else
    {
        return 0.0;
    }
}
