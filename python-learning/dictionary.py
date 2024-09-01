def run_dictionary_methods(dictionary: dict):
    dictionary.clear()	                                        # Removes all the elements from the dictionary
    dictionary.copy()	                                        # Returns a copy of the dictionary
    dictionary.fromkeys(keys = ('x', 'y'), value = 'x')         # Returns dictionary with specified keys & value (optional)
    dictionary.get(keyname = 'x', value = 'y')	                # Returns value of the specified key, if key does not exist value (optional) is returned
    dictionary.items()	                                        # Returns a list containing a tuple for each key value pair
    dictionary.keys()	                                        # Returns a list containing the dictionary's keys
    dictionary.pop(keyname = 'x', defaultvalue = 'y')	        # Removes the element with keyname, if no element found defaultvalue (optional) is returned
    dictionary.popitem()	                                    # Removes the last inserted key-value pair
    dictionary.setdefault(keyname = 'x', value = 'y')           # Returns the value of the specified key. If the key does not exist: insert the key, with the specified value
    dictionary.update(iterable = {'key': 'value'})              # Updates the dictionary with the specified key-value pairs
    dictionary.values()                                         # Returns a list of all the values in the dictionary