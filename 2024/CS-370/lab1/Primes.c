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
    // basic edge cases, negatives cannot be primes
    if (num <= 1)
        return false;
    if (num <= 3)
        return true;
    // basic check, if the number is a factor of 3 or 2 then it cannot be prime
    if (num % 2 == 0 || num % 3 == 0)
        return false;
    // i starts at 5 because we are checking all cases before
    // for loop will stop when i^2 is larger than the number
    // for loop will step forwards by 6, 5 + 6 = 11 + 6 = 17 + 6 = 23
    for (int i = 5; i * i <= num; i += 6)
    {
        // not prime: number is a factor of the iteration (i)
        if (num % i == 0 || num % (i + 2) == 0)
            return false;
    }
    return true;
}

int get_prime_count(int *array, int arraySize)
{
    int prime_count = 0;
    for (int i = 0; i < arraySize; ++i)
    {
        if (is_prime(array[i]))
        {
            // using pre-increment operator because its less storage
            ++prime_count;
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

    for (int i = 1; i <= total_iterations; ++i)
    {
        int array_size = random_in_range(150, 200);
        // casting to a int pointer
        // we will allocate memory equal to the size of the array * byte size of int
        int *array = (int *)malloc(array_size * sizeof(int));

        // simple error check
        if (array == NULL)
        {
            fprintf(stderr, "[Primes]: Memory allocation failed\n");
            return -1.0;
        }

        // randomly populate the array
        for (int j = 0; j < array_size; ++j)
        {
            array[j] = random_in_range(50, 200);
        }

        int prime_count = get_prime_count(array, array_size);
        int none_prime_count = array_size - prime_count;
        float ratio = 0.0;
        if (none_prime_count > 0)
        {
            ratio = (float)prime_count / none_prime_count;
        }
        else
        {
            ratio = 0.0;
        }
        sum_ratios += ratio;

        if (prime_count > max_prime_count)
        {
            max_prime_count = prime_count;
            max_count_iteration = i;
        }
        // this will free the entire array
        free(array);
    }

    printf("[Primes]: Number of iterations: %d\n", total_iterations);
    printf("[Primes]: Max prime count: %d\n", max_count_iteration);

    if (total_iterations > 0)
    {
        return sum_ratios / total_iterations;
    }
    else
    {
        return 0.0;
    }
}
