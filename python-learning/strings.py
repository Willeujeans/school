"""
strings are immutable meaning you cannot do this:
string[0] = 'k'

python does not have characters so all methods will work with any size string
character are just strings with a length of 1
"""


def run_string_methods():
    string: str = 'Midway upon the journey of our life\n I found myself within a forest dark,\n For the straightforward pathway had been lost.'
    string_case_methods(string)


def string_case_methods(string: str):
    # returns a new str
    string.capitalize()     # first character is capitilized 
    string.casefold()       # all characters are lowercase  
    string.lower()          # all characters are lowercase  
    string.upper()          # all characters are uppercase
    string.swapcase()       # lowercase characters become uppercase & vice versa
    string.title()          # capitilizes first character in words


def string_identification(string: str):
    # returns a bool
    string.isalnum()        # if: all characters in string are alphanumeric
    string.isalpha()        # if: all characters in string are in alphabet
    string.isascii()        # if: all characters are ascii characters
    string.isdecimal()      # if: all characters are decimals
    string.isdigit()        # if: all characters are digits
    string.isidentifier()   # if: string is identifier
    string.islower()        # if: all characters are lowercase
    string.isnumeric()      # if: all characters are numbers
    string.isprintable()    # if: all characters are printable
    string.isspace()        # if: all characters are spaces
    string.istitle()        # if: characters at the start of words are capitilized
    string.isupper()        # if: all characters are uppercase
    string.endswith('x')    # if: string ends with given value
    string.startswith('x')  # if: string starts with given value


def string_manipulation(string: str):
    # returns a new string
    string += "concatination"                               # will concatinate the word 'concatination'
    string = "concat" + "ination"                           # will make the string 'concatination'
    translation_map = str.maketrans({'!': '?', ' ': '_'})   # map used for translate
    string.translate(translation_map)                       # replaces characters with given map
    string.replace('x', 'y')                                # replaces x with y
    string[::-1]                                            # reverses the order of the string
    string.strip('x')                                       # removes x from both ends of the string
    string.rstrip('x')                                      # removes x from right side of string
    string.lstrip('x')                                      # removes x from left side of string
    string.rjust(width = 1, fillchar = ' ')                 # creates a right justified string
    string.ljust(width = 1, fillchar = ' ')                 # creates a left justified string
    string.expandtabs(10)                                   # sets the tab size of the string
    string.zfill(100)                                       # adds given number of zeros to the front of the string


def string_search(string: str):
    string.index('x')       # returns the position where it finds x, throws value error if x not found
    string.find('x')        # returns the position where it finds x, returns -1 if x not found
    string.count('x')       # returns the number of times x occurs in string
    string.rindex('x')      # returns the position of the last occurance of x, throws value error if x not found
    string.rfind('x')       # returns the position of the last occurance of x, returns -1 if x not found


def string_iterables(string: str, my_list: list):
    'x'.join(my_list)       # creates a string from an iterable, adding x inbetween each element
    string.split('x')       # returns a list where the string is split by x
    string.splitlines()     # returns a list where the string is split by newlines
    string.rsplit('x')      # returns a list where the string is split by x
    string.partition('x')   # returns a tuple (before x, x, after x)


def string_conversions(string: str):
    string.encode(encoding = 'ascii', errors = 'backslashreplace')         # will encode the given encoding type, default is UTF-8