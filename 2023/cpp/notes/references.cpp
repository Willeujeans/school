#include <iostream>
using namespace std;

int main()      //function, anything inside will be executed
{
    string food = "Pizza";  // food variable
    string &meal = food;    // reference to food
    cout << &food; // Outputs memory address
    string* ptr = &food;    // A pointer variable, with the name ptr, that stores the address of food

    // Change the value of the pointer
    *ptr = "Hamburger";
}
