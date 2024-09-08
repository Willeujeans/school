Write up
Assignment Overview
You need to create two C programs, Driver.c and Primes.c, for a memory allocation and prime number counting task. The Driver.c program will set up the environment and invoke functions in Primes.c. The Primes.c program will handle memory allocation, array population, prime counting, and ratio calculation. You will also test your programs with Valgrind to ensure there are no memory leaks.

Files to Create
Driver.c

Task:
- Read a seed value from command line arguments.
- Initialize the random number generator using the seed.
- Call the function from Primes.c to perform the required computations.
- Print the seed used, the number of iterations, the iteration with the maximum prime count, and the average prime/composite ratio.
- main: Handles command line input, initializes random number generation, and processes output.

Task:
Allocate and deallocate arrays of random sizes.
Populate arrays with random integers.
Count primes and non-primes in each array.
Calculate and print the ratio of primes to non-primes.
Track the maximum number of primes and the corresponding iteration.
Compute and return the average ratio of primes to non-primes.
Functions to Implement:
get_running_ratio(): Main function that performs the above tasks.
random_in_range(int lower_bound, int upper_bound): Generates a random integer within a specified range.
get_prime_count(int *array, int arraySize): Counts and returns the number of primes in the given array.
Helper Functions:
Implement additional functions as needed to assist in the tasks above.
Primes.h (Header file)

Task:
Declare functions from Primes.c so that they can be used in Driver.c.
Makefile

Task:
Define rules for compiling the Driver.c and Primes.c files.
Include targets for make, make clean, and make tar.
README.txt

Task:
Describe each file and its purpose.
Include the Valgrind output showing no memory leaks and showing a memory leak.
Provide any additional information needed for grading.
Step-by-Step Tasks
Initialize Driver.c:

Read Command Line Arguments: Parse the seed value from command line arguments.
Set Seed: Use srand(seed) to initialize the random number generator.
Call Primes Function: Call get_running_ratio() from Primes.c.
Print Results: Display the seed, the number of iterations, the iteration with the maximum prime count, and the average ratio.
Develop Primes.c:

Implement get_running_ratio():
Initialization: Set up variables to track maximum prime count and the corresponding iteration.
Loop for Iterations: Determine the number of iterations (between 50 and 100).
Array Allocation: For each iteration, allocate an array of a random size (between 150 and 200).
Populate Array: Fill the array with random integers (between 50 and 199).
Count Primes: Use get_prime_count() to count the number of primes.
Calculate Ratio: Compute the ratio of primes to non-primes and update the maximum count if needed.
Compute Average Ratio: Maintain a running sum of ratios and compute the average.
Implement random_in_range(): Generate a random number within a specified range.
Implement get_prime_count(): Count and return the number of prime numbers in the array.
Create Primes.h:

Declare Functions: Include declarations for random_in_range(), get_prime_count(), and get_running_ratio().
Write Makefile:

Compile and Link: Define rules to compile Driver.c and Primes.c and link them into an executable.
Clean Up: Include a rule to clean up generated files.
Create Archive: Define a target to create a tarball for submission.
Prepare README.txt:

Describe Files: Provide a description for each C file and its role.
Include Valgrind Outputs: Paste the Valgrind outputs showing no memory leaks and with a memory leak.
Additional Information: Include any notes or instructions necessary for the grader.
Testing and Submission
Test for Memory Leaks:

Use Valgrind to check for memory leaks in your program. Ensure there are no leaks before submission.
Inject a memory leak (by commenting out deallocation code) and provide Valgrind output showing the leak.
Create and Test the Submission File:

Zip Files: Ensure you include all necessary files in a zip archive.
Verify Archive: Test the zip file by extracting it to ensure it is valid and includes all required files.
Submit: Upload the zip file to Canvas by the deadline.