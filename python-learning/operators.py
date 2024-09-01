"""
Operator Precedence (the order in which operators resolve)
Same level of precedence: order is evaluated left to right
()
**
+x, -x, ~x
*, /, //, %
+, -
<<, >>
&
^
|
==, !=, >, >=, <, <=, is, is not, in, not in
not
and
or
"""


def run_arithmetic_operations():
    addition = 2 + 2
    subtraction = 2 - 1
    multiplication = 2 * 5
    division = 10 / 2
    modulus = 10 % 100
    exponentiation = 10 ** 2
    floor_division = 15 // 2


def run_assignment_operators():
    x = 10
    x += 1
    x -= 1
    x *= 1
    x /= 1
    x %= 1
    x **= 1
    x //= 1
    x &= 1
    x |= 1
    x ^= 1
    x >>= 1
    x <<= 1
    (x := 1)


def run_comparison_operators(x = 0, y = 1):
    # will give you a boolean
    equals = x == y
    not_equals = x != y
    greater_than = x > y
    greater_than_equal = x >= y
    less_than = x < y
    less_than_equal = x <= y


def run_logical_operators(x = True, y = False):
    # will give you a boolean
    logical_and = x and y
    logical_or = x or y
    logical_not = not x


def run_identity_operators(x = 0, y = 1):
    z = x
    is_same_object = x is y
    is_copy_of_object = x is z
    is_not_same_object = x is not y


def run_membership_operators(x = 2, y = [0, 1, 2, 3]):
    is_in_sequence = x in y
    is_not_in_sequence = x not in y


def run_bitwise_operators(x = 1, y = 0):
    bitwise_and = x & y
    bitwise_or = x | y
    bitwise_xor = x ^ y
    bitwise_not = ~x
    zero_fill_leftshift = x << 2
    signed_right_shift = x >> 2