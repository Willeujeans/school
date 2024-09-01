import numpy as np
"""
Fibonacci(n) = Fibonacci(n-1) + Fibonacci(n-2)
"""
# O(2^n)
def primitive_fibonacci(n: int) -> int: # A recursive call
    assert(n >= 0) # input != negative
    if n == 0:
        return 0
    if n == 1:
        return 1
    return primitive_fibonacci(n - 1) + primitive_fibonacci(n - 2) # Tail Recursive: we can rewrite as a loop

print(primitive_fibonacci(9)) # run script, next line in termianl type "time !!" to get the time


# This fibonacci function with helper only follows the left hand side of the call graph
#             fib(n)
#               |
#        +------+------+
#        |             |
#     fib(n-1)     *fib(n-2)*
#        |
#   +----+--------+
#   |             |
# *fib(n-2)*     fib(n-3)
#
# if we only calculate the left side we avoid calculating duplicates as seen at the positions with *
#
# O(n)
def fibonacci_helper(n: int) -> tuple[int, int]:
    if n == 1: # this is always true
        return (1, 0)
    
    (fibonacci_minus_one, fibonacci_minus_two) = fibonacci_helper(n - 1)
    return (fibonacci_minus_one + fibonacci_minus_two, fibonacci_minus_one) # returns ( fibonacci(n), fibonacci(n-1) )


def fibonacci_with_helper(n: int) -> int:
    assert(n >= 0) # input != negative
    if n == 0:
        return 0
    if n == 1:
        return 1
    
    (fibonacci_minus_one, fibonacci_minus_two) = fibonacci_helper(n - 1) # tuple with ( fibonacci(n-1) , fibonacci(n-2) )
    return fibonacci_minus_one + fibonacci_minus_two # = Fibonacci(n)


# same exact theory however we replaced the tail recusion with a loop!
def fibonacci_iterative(n: int) -> int:
    assert(n >= 0)
    if n == 0:
        return 0
    if n == 1:
        return 1
    fibonacci_minus_one = 1
    fibonacci_minus_two = 0

    for i in range(2, n):
        temp = fibonacci_minus_one
        fibonacci_minus_one = fibonacci_minus_one + fibonacci_minus_two
        fibonacci_minus_two = temp

# Next step is to find the definitions of fibonacci, theres one in linear algebra
# matrix [1, 1, 1, 0]^2 = [F(n+1), F(n), F(n), F(n-1)]
# the matrix is being raised to the power of 2
# remember that exponents in algebra follow this rule: x^n = ( x^(n/2) * x^(n/2) )
# Now this definition lends itself to dividing and conquering 

# Matrix Exponent approach
# O(log n)
# ths problem is being divided in half each time
# we are returning the top right corner of the matrix

def odd(n):
    if(n % 2) == 1:
        return True
    else:
        return False


def matrix_exponentation(matrix, exponent):
    assert(exponent >= 1)

    if odd(exponent):
        if exponent == 1: # matrix^1 is just the matrix
            return matrix
        return np.matmul(matrix_exponentation(matrix, exponent-1), matrix)
    matrix_half = matrix_exponentation(matrix, exponent/2)
    return np.matmul(matrix_half, matrix_half)