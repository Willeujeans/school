"""
This file shows all default variable types in python
and the multiple ways you can declare them.
"""


def create_all_types():
    create_text_type()          # str
    create_numeric_types()      # int, float, complex
    create_sequence_types()     # list, tuple, range
    create_mapping_types()      # dict
    create_set_types()          # set, frozenset
    create_boolean_types()      # bool
    create_binary_types()       # bytes, bytearray, memoryview
    create_none_types()         # None


def create_text_type():
    string_single_quotes = ''
    string_double_quotes = ""
    string_with_type: str = ''
    age = 100
    string_unicode = u'this is a unicode string'
    string_formatted = f'This string can print variables, {age}!'
    string_raw = r'backslashes \n are treated literally here'


def create_numeric_types():
    # int uses Arbitrary Precision (number can be as large as memory is able to support)
    my_int = 1
    int_with_type: int = 1

    # Precision: ~15-17 decimal digits eg. (1.010101010101010)
    my_float = 1.0
    float_with_type: float = 1.0

    # 'j' is the representation of an imaginary number instead of 'i'
    complex_number = 1 + 1j
    complex_number_with_type: complex = 1 + 1j


def create_sequence_types():
    # lists are similar to arrays, however lists will double in size when the amount of elements exceeds the space
    my_list = []
    list_with_type: list = []
    list_holding_type: list[int] = [1, 2]
    list_holding_either_type: list[int | str] = [1, '2']
    list_with_initial_size = [1] * 100 # will populate a list with 100 1s 
    list_with_elements = [1, 2, 3, 4]

    # tuples are basically immutable lists
    my_tuple = ()
    tuple_with_type: tuple = ()
    tuple_with_elements = ('red', 'green', 'blue')
    tuple_holding_type: tuple[str, str, int] = ('red', 'green', 1)
    tuple_holding_either_type: tuple[str | int, str, int] = ('red', 'green', 1)

    # range(start, end, step)
    my_range = range(100)
    range_with_type: range = range(100)
    range_between_two = range(0, 100)
    range_between_two_with_step = range(0, 100, 2)
    range_backwards = range(10, 0, -1)


def create_mapping_types():
    # its a key value pair data structure
    dictionary = {}
    dictionary_with_type: dict = {}
    dictionary_with_elements = {'name': 'James', 'age': 100}


def create_set_types():
    # {} is reserved for dict so you need to be more explicit
    my_set = set()
    set_with_elements = {1, 2, 3}
    set_with_type: set = {1, 2, 3}

    # its a set, BUT! it cannot be changed
    my_frozenset = frozenset({'red', 'green', 'blue'})
    frozenset_with_type: frozenset = frozenset({'red', 'green', 'blue'})


def create_boolean_types():
    # True or False
    my_bool = False
    bool_number_true: bool = 1
    bool_number_false: bool = 0
    bool_with_type: bool = True


def create_binary_types():
    # Immutable sequence of bytes (bytes are 8 bits)
    my_bytes = b'Hello, World!'
    bytes_with_type: bytes = b'Hello, World!'

    # bytearray, a mutable sequence of bytes
    my_bytearray = bytearray(100)
    bytearray_with_type: bytearray = bytearray(100)

    # access bytes without copying it
    my_memoryview = memoryview(bytes(5))
    my_memoryview_with_type: memoryview = memoryview(bytes(5))


def create_none_types():
    my_none = None
    none_with_type: None = None