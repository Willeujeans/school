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


def reverse(pattern: list) -> list:
    return pattern[::-1]


def remove_one_element(patterns: list[list]) -> list:
    left, right = patterns[0], patterns[1]
    for i, _ in enumerate(left):
        if left[i] != right[i]:
            remove_if_neighbor_can_replace(i, left, right)
    return left + right


def remove_if_neighbor_can_replace(i, left: list, right: list):
    if i+1 < len(left) and left[i+1] == right[i]:
        left.pop(i)  
    if i+1 < len(right) and right[i+1] == left[i]:
        right.pop(i)


def is_palindrome(pattern: list[list]) -> bool:
    for i in range(len(pattern[0])):
        if pattern[0][i] != pattern[1][i]:
            return False
    return True


# Fill in find_palindrome
def find_palindrome(pattern) -> tuple | None:
    if len(pattern) <= 2: # check for trivial solutions
        return None
    list_pattern = list(pattern)
    list_split = split_in_half(list_pattern)
    lists_aligned = [list_split[0], reverse(list_split[1])]
    
    if is_palindrome(lists_aligned): # already a palindrome, removing the center will always retain a palinedrome
        lists_aligned[1].pop(-1)
    else:
        remove_one_element(lists_aligned)
        if not is_palindrome(lists_aligned):
            return None
    
    result = tuple(lists_aligned[0] + reverse(lists_aligned[1]))
    return result


def find_palindrome_test():
    print("Palindrome: Number Tests")
    print("TEST(0) ", None == find_palindrome((1,1)))
    print("TEST(1) ", None == find_palindrome((1,)))
    print("TEST(2) ", None == find_palindrome((1,2,3,4,5)))
    print("TEST(3) ", (1,1) == find_palindrome((1,1,1)))
    print("TEST(4) ", (1,1) == find_palindrome((1,0,1)))
    print("TEST(5) ", (1,0,1) == find_palindrome((1,0,0,1)))
    print("TEST(6) ", (1,0,0,1) == find_palindrome((1,0,1,0,1)))
    print("TEST(7) ", (1,2,3,2,1) == find_palindrome((1,2,3,3,2,1)))
    print("TEST(8) ", (1,2,3,3,2,1) == find_palindrome((1,2,3,3,2,1,1)))
    print("Palindrome: String Tests")

find_palindrome_test()