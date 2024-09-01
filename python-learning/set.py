def run_set_methods(set_a: set, set_b: set):
    set_a.add()	 	                            # Adds an element to the set
    set_a.clear()	 	                        # Removes all the elements from the set
    set_a.copy()	 	                        # Returns a copy of the set
    set_a.difference(set_b)	                    # Returns a set containing the difference between two or more sets
    set_a.difference_update(set_b)	            # Removes the items in this set that are also included in another, specified set
    set_a.discard()	 	                        # Remove the specified item
    set_a.intersection(set_b)	                # Returns a set, that is the intersection of two other sets
    set_a.intersection_update(set_b)	        # Removes the items in this set that are not present in other, specified set(s)
    set_a.isdisjoint(set_b)	 	                # Returns whether two sets have a intersection or not
    set_a.issubset(set_b)	                    # Returns whether another set contains this set or not
    set_a.issuperset(set_b)	                    # Returns whether this set contains another set or not
    set_a.pop()	 	                            # Removes an element from the set
    set_a.remove('x')	 	                    # Removes the specified element
    set_a.symmetric_difference(set_b)	        # Returns a set with the symmetric differences of two sets
    set_a.symmetric_difference_update(set_b)    # Inserts the symmetric differences from this set and another
    set_a.union(set_b)	                        # Return a set containing the union of sets
    set_a.update(set_b)	                        # Update the set with the union of this set and others

    set_a - set_b                               # difference()
    set_a -= set_b                              # difference_update()
    set_a & set_b                               # intersection()
    set_a &= set_b                              # intersection_update()
    set_a <= set_b                              # issubset()
    set_a >= set_b                              # issuperset()
    set_a ^ set_b                               # symmetric_difference()
    set_a ^= set_b                              # symmetric_difference_update()
    set_a | set_b                               # union()
    set_a |= set_b                              # update()
    
    set_a < set_b 	                            # Returns whether all items in this set is present in other, specified set(s)
    set_a > set_b 	                            # Returns whether all items in other, specified set(s) is present in this set

