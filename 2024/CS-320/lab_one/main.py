# Determine if a tuple can be made into a palindrome by removing exactly one element

# An example import. Delete or replace as desired. Be careful with what libraries you use:
# Non-default python libraries may not work in Zybooks.
import math 

# Subroutines if any, go here
def split_in_half(pattern: list) -> list[list]:
    center = int(len(pattern)/2)
    left_side = pattern[:center]
    right_side = pattern[center:]
    return [left_side, right_side]


def reverse_order(pattern: list) -> list:
    return pattern[::-1]


def remove_one_element(patterns: list[list]) -> list:
    left, right = patterns[0], patterns[1]
    for i, _ in enumerate(right):
        if left[i] != right[i]:
            if left[i+1] == right[i]:
                left.pop(i)
            elif right[i+1] == left[i]:
                right.pop(i)
    return left + right


def is_palindrome(pattern: list[list]) -> bool:
    for i in range(len(pattern[1])):
        if pattern[0][i] != pattern[1][i]:
            return False
    return True


# Fill in find_palindrome
def find_palindrome(pattern) -> tuple:
    list_pattern = list(pattern)
    list_split = split_in_half(list_pattern)
    lists_aligned = [list_split[0], reverse_order(list_split[1])]
    if is_palindrome(lists_aligned):
        lists_aligned[1].pop(-1)
    else:
        remove_one_element(lists_aligned)
    result = tuple(lists_aligned[0] + reverse_order(lists_aligned[1]))
    print(result)
    return result


def find_palindrome_test():
    print("TEST(1) ", (1,2,3,2,1) == find_palindrome((1,2,3,3,2,1)))
    print("TEST(2) ", (1,2,3,3,2,1) == find_palindrome((1,2,3,3,2,1,1)))

find_palindrome_test()