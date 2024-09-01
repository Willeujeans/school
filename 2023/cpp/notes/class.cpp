#include <iostream>
using namespace std;


class Animal { //Animal class
  public:    //Access specifier           
  int age;
  string name;
    void speak() {  // Method/function defined inside the class
      cout << "woof woof";
    }
};


class Dog {   //Dog class
  public:   //Access specifier             
  int age;
  string name;
  string brand;  // var
  string model;  // var
  int year;      // var
    void speak() {  // Method/function defined inside the class
    cout << "woof woof";
  }

  Dog(string name, int age) {  // Constructor with parameters
    name = name;
    age = age;
  }
  protected: //can also be accessed in the inherited class
  string nickname = "boyo";
};

class superHero {
  public:    // Public access specifier
    int x;   // Public attribute

  private:   // Private access specifier
    string name = "Frompst";   // Private attribute
};

class superDog: public Dog, public superHero {
};

int main()
{
    Dog myDog("Bruno",24);  // Create an object of dog
    myDog.age = 15;   //setting age of new instance of dog
    myDog.name = "Some text";   //setting name of new instance of dog
}


