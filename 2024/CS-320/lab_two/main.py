# extract values from a sorted list

import math  # optional and you can delete this line if not useful

# subroutines if any, go here


# your subroutine goes here
def new_words(words, wordlist):
    # Input validation
    if words == None or wordlist == None:
        return None
    if type(words) != tuple or type(wordlist) != tuple:
        return None
    
    # make a new tuple because they are immutable
    for each in words:
        each.lower()
    # Convert all elements in words and wordlist to lowercase
    pass