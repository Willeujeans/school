def run_list_methods(list: list):
    list.append(elmnt = 1)	                # Adds elmnt at the end of the list
    list.clear()	                        # Removes all the elements from the list
    list.copy()	                            # Returns a copy of the list
    list.count(elmnt = 'x')	                # Returns the number of elements with elmnt value
    list.extend(iterable = [1, 2])	        # Add the elements of iterable to the end of the list
    list.index(elmnt = 'x')	                # Returns the index of the first element with elmnt value
    list.insert(pos = 1, elmnt = 'x')	    # Adds elmnt at pos
    list.pop(pos = 1)	                    # Removes the element at pos
    list.remove(elmnt = 1)	                # Removes first item with elmnt value
    list.reverse()	                        # Reverses list order 
    list.sort()	                            # Sorts list