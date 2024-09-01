"""
and	        A logical operator
as	        To create an alias
assert	    For debugging
break	    To break out of a loop
class	    To define a class
continue	To continue to the next iteration of a loop
def	        To define a function
del	        To delete an object
elif	    Used in conditional statements, same as else if
else	    Used in conditional statements
except	    Used with exceptions, what to do when an exception occurs
False	    Boolean value, result of comparison operations
finally	    Used with exceptions, a block of code that will be executed no matter if there is an exception or not
for	        To create a for loop
from	    To import specific parts of a module
global	    To declare a global variable
if	        To make a conditional statement
import	    To import a module
in	        To check if a value is present in a list, tuple, etc.
is	        To test if two variables are equal
lambda	    To create an anonymous function
None	    Represents a null value
nonlocal	To declare a non-local variable
not	        A logical operator
or	        A logical operator
pass	    A null statement, a statement that will do nothing
raise	    To raise an exception
return	    To exit a function and return a value
True	    Boolean value, result of comparison operations
try	        To make a try...except statement
while	    To create a while loop
with	    Used to simplify exception handling
yield	    To return a list of values from a generator
"""
import datetime
from datetime import time
import calendar as cal

def functions():
    pass
    return


def logical_operators(x = True, y = False):
    if x:
        pass
    x and y
    x or y
    x is y
    not x


def exceptions(x = 1):
    try:
        x > 3
    except:
        print("Something went wrong")
    else:
        print("Nothing went wrong")
    finally:
        print("The try...except block is finished")

    if x < 0:
        raise Exception("Exception Message")

 
def scope():
    global y

    x = "John"
    def myfunc2():
        nonlocal x
        x = "hello"
    myfunc2()
    return x


def loops():
    for x in 100:
        if x > 50:
            break
    while True:
        pass