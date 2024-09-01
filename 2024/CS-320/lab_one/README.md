# Lab 1 Finding a Palindrome

## Task
Write a routine called find_palindrome(**pattern**: tuple)->tuple | None:
The returned tuple must be a palindrome which is results from removing just one element from the **pattern**
### Rules
- The Algorithm must run at O(n) time complexity
- Single element palindromes return **None**
- Throw no exceptions
- Only way to change a pattern is to remove a whole element
- You must remove one element for the output to be valid
### Examples
- ✅ (3,1,2,3)         -- remove  2  --> (3,1,3)
- ❌ ("ab","a","a")    -- remove "b" --> ("a","a","a")
- ✅ ("g","a","a","g") -- remove "a" --> ("g","a","g")

## Planning
### Ideas
- Palindromes by definition can be split in half, because the first half should always be the same as the second half we only need to check them with eachother. Find if there is ONE difference and remove it. If there is more than one difference then return None.
```
(1,2,2,3,1) -> (1,2) & (3,1) -> (1,2) & (1,3) -> (1,2,2,1)
     ^               ^                ^              ^
     |               |                |              |
   input           split             flip          result
in this case, remove the element that is not similar to middle element

(1,2,3,1) -> (1,2) & (3,1) -> (1,2) & (1,3) -> (1,2,2,1)
    ^              ^                ^              ^
    |              |                |              |
  input          split             flip          result
in this case, remove either of them it doesnt matter
```

### Example
1. Input: pattern: tuple
2. Check if tuple element count is greater than 2
3. Find the midpoint of the tuple, odd: split on either side of element, even: split in half evenly
4. Compare first half with second, if there is one difference remove it if its not the same as the middle number


