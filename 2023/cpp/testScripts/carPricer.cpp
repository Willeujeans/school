#include <iostream>     //library for configuring Object Oriented style of programming
using namespace std;    //using standard names in library

int main()
{
    //INITIALIZING VARIABLES
    float radius = 0;
    float volume = 0; 
    float surfaceArea = 0;
    float PI = 3.141592;	  //Because you said PI would just be 3.141592 in this case I initialized its value

    //TAKING INPUT
    cout << "Enter Radius Value: " <<endl;  //console output to ask the user to input the radius
    cin >> radius;  //I’m setting the radius to whatever the user inputs using console input

   //CALCULATING VALUES
    surfaceArea = 4*PI*(radius * radius);  //Using the basic formula for surface area I plug in the values
    volume = PI * radius * radius;  //I don’t have a math library so I’m multiplying radius by itself to get radius^2

    //PRINTING RESULT
    cout << "Area of the Circle is: " << surfaceArea <<"The volume is: "<< volume <<endl;  //log result to the console
    return 0;	//The function requires something to get returned so I return 0
}
