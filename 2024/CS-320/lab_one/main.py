# Determine if a tuple can be made into a palindrome by removing exactly one element

# An example import. Delete or replace as desired. Be careful with what libraries you use:
# Non-default python libraries may not work in Zybooks.
import math 

# Subroutines if any, go here
def split_tuple_into_list(pattern: tuple) -> list[list]:
    first_half = []
    middle = []
    second_half = []
    half_point = (len(pattern)-1)/2
    for i, element in enumerate(pattern):
        if i == half_point and is_odd(len(pattern)):
            middle.append(element)
        elif i < half_point:
            first_half.append(element)
        elif i > half_point:
            second_half.append(element)
    return [first_half, middle ,second_half]


def is_odd(number: int) -> bool:
    if number % 2 == 1:
        return True
    else:
        return False


def reverse_second_half_order(split_tuple: tuple) -> list[list]:
    split_tuple[2] = split_tuple[2][::-1]
    return split_tuple


def check_for_differences(tuple_a: tuple, tuple_b: tuple) -> list[int]:
    print("checking for diff: ", tuple_a, tuple_b)
    index_of_differences: list[int] = []
    for i in range(len(tuple_a)):
        if not tuple_a[i] == tuple_b[i]:
            index_of_differences.append(i)
    return index_of_differences


def can_be_valid_palindrome(index_of_differences) -> bool:
    if len(index_of_differences) > 1:
        return False
    return True


# Fill in find_palindrome
def find_palindrome(pattern: tuple) -> tuple | None:
    if len(pattern) <= 2:
        return None
    split_tuples = split_tuple_into_list(pattern)
    split_tuples_ordered = reverse_second_half_order(split_tuples)
    index_of_differences = check_for_differences(split_tuples_ordered[0], split_tuples_ordered[2])
    if not can_be_valid_palindrome(index_of_differences):
        return None
    if len(index_of_differences) > 0 and is_odd(pattern):
        return None
    # remove the element with the difference
    # (1,0,0,1) -> remove mid point
    # (1,2,3,4) -> too many differences, can't work
    # (1,2,3,1) -> found a difference, remove it
    # (1,2,3,2,5) -> (1,2,3,2) still does not work: 1 difference, odd
    # (1,2,3,5,1) -> one difference, odd, doesn't work
    # (1,2,3,1,1)
    # (1,2,3)
    # (1,2,1,2,1)
    # (1,1,3) # remove end
    # (3,2,3) # remove center
    # (1,1,1,2,1) # Odd, has a difference
    # (1,2,1,2,1)
    # (1,2,1,1,1) # remove difference, that is not equal to the middle number
    # (1,2,3,3,2,1,1) -> (1,2,3,3,2,1)

    # odd, 2 differences
    # (1,2,3)
    # (3)
    # (1,1,2)

    # ( ,1,2,3)
    # (1,1,2,3)

    # (1,2,3,2,1)
    # (1,2,3)
    # (1,2)

    # (1,2,3,1)

    #Cases:
    #Odd:
    #   if there is any difference, it cannot be made into a palindrome
    #   if there is no differences then remove the center element
    #Even:
    #   

    # types of removals
    # center removal, only happens when the whole tuple is already a palindrome
    # inside removal, when there is a difference in the halves
    # outside removal, when a palindrome exists within the tuple already
    return (0,0)


def test_find_palindrome():
    print("test1: None ", None == find_palindrome((0, )))
    print("test2: None ", None == find_palindrome((0, 0)))
    print("test3: (0,0) ", (0,0) == find_palindrome((0, 0, 0)))
    print("test4: (1,0,1) ", (1,0,1) == find_palindrome((1, 0, 0, 1)), find_palindrome((1, 0, 0, 1)))
    print("test5: None ", None == find_palindrome((1,0,1,2,1)), find_palindrome((1,0,1,2,1))) 
    print("test6: None ", None == find_palindrome((1,2,3,4,5,6)), find_palindrome((1,2,3,4,5,6))) 
    # almost there, if there's a difference, check if either side of the middle number is equal to the middle, if it is then we can still have a palindrome by removing the one that isn't the same.
    # It will not be eligable when theres a difference and BOTH sides of the middle number is not equal to the middle number


test_find_palindrome()