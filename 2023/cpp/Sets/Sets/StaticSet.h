/*
 Constructors and some additional member functions are already implemented:

 Contains(const T& item) uses the unordered_set's count() function to determine if the set contains the item. If count() returns 1, the item is in the set and Contains() returns true. Otherwise the item is not in the set and Contains() returns false.
 GetSize() uses the unordered_set's size() function to determine the number of elements in the set. GetSize() returns the set's size as an integer.
 
 Implement the StaticSet class's Union(), Intersection(), Difference(), Filter(), and Map() member functions.
 
 Each must not change the StaticSet itself, but rather build and return a new StaticSet.

 Step 3: Test in develop mode, then submit

 Implement the StaticSet class's:
    -Union()
    -Intersection()
    -Difference()
    -Filter()
    -Map()
    Each must not change the StaticSet itself, but rather build and return a new StaticSet.
 */

//What does virtual do
//We are constructing new static sets
//Each construct of a static set must have these functions
//-Union()
//-Intersection()
//-Difference()
//-Filter()
//-Map()

#ifndef STATICSET_H
#define STATICSET_H

#include <functional>
#include <iostream>
#include <unordered_set>
#include <vector>

template <typename T>
class StaticSet {
private:
   std::unordered_set<T> set;

public:
   // Constructs an empty StaticSet
   StaticSet() {
   }

   // Constructs the StaticSet by adding all vector items
   StaticSet(const std::vector<T>& items) {
      for (const T& item : items) {
         set.insert(item);
      }
   }
   
   // Constructs the StaticSet by copying itemsToCopy's items
   StaticSet(const std::unordered_set<T>& itemsToCopy) : set(itemsToCopy) {
   }
   
   virtual ~StaticSet() {
   }
   
   bool Contains(const T& item) const {
      return 1 == set.count(item);
   }
   
   int GetSize() const {
      return (int) set.size();
   }
   
   void Print(std::ostream& output, std::string separator,
      std::string prefix="", std::string suffix="") const {
      output << prefix;
      bool firstItem = true;
      for (const T& item : set) {
         if (firstItem) {
            output << item;
            firstItem = false;
         }
         else {
            output << separator << item;
         }
      }
      output << suffix;
   }
   
    
    
    
    
//COMPLETE
   StaticSet<T> Difference(const StaticSet& otherSet) const {
       //create a new set
       StaticSet<T> newSet;
       
       //this will loop through the current set
       for(auto element : this->set){
           //checking if they have the same element
           if(otherSet.Contains(element) == false){
               //insert the different element into newSet
               newSet.set.insert(element);
           }
       }
       //returns newSet with differences
      return newSet;
   }
   
    //COMPLETE
   StaticSet<T> Filter(std::function<bool(const T&)> predicate) const {
       StaticSet<T> newSet;
       //predicate is a function that is being passed into the argument of this function
       //We can see it returns a bool
       //and takes in a references element within a set
       //Using that knowledge we can cycle through this set and pass the element into the predicate argument
       //This returns a bool which we will check
       //If the bool is true add this element into our new set
       for(auto element : this->set){
           if(predicate(element) == true){
               newSet.set.insert(element);
           }
       }
       //return the newSet with inserted elements
      return newSet;
   }
   
    //COMPLETE
   StaticSet<T> Intersection(const StaticSet& otherSet) const {
       //Create a new set
       StaticSet<T> newSet;
       //cycle through this instance's set
       for(auto element : this->set){
           //compare with the other set
           if(otherSet.Contains(element) == true){
               //that element is within the otherSet then add it to the new set
               newSet.set.insert(element);
           }
       }
       //return the newSet containing all of the similarities
      return newSet;
   }
   
    //Calls mapFunction(item) for each item in this set and adds the returned item to a StaticSet<U>.
    //After mapFunction has been called for each item in this set, the StaticSet<U> object is returned.
    //FUNCTION TO CHANGE
    
   template <typename U>
   StaticSet<U> Map(std::function<U(const T&)> mapFunction) const {
       //mapFunction is a function being passed as an argument into this function
       //takes in a setElement
       //returns a set with the type of U
       std::vector<U> newSetVector;
       for(auto element : this->set){
           newSetVector.push_back(mapFunction(element));
       }
       
       return StaticSet<U>(newSetVector);
   }
   
   // Returns a StaticSet<T> containing every element from this set and every element from otherSet.
    //FUNCTION TO CHANGE
   StaticSet<T> Union(const StaticSet& otherSet) const {
       //create a new set, using argument constructor to populate with this set
       StaticSet<T> newSet(this->set);
       //check against the other set for duplicates, add the differences
       for(auto otherElement : otherSet.set){
           if(newSet.Contains(otherElement) == false){
               newSet.set.insert(otherElement);
           }
       }
       //return the newSet
      return newSet;
   }
};

#endif
