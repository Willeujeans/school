#include <iostream>     //library for configuring object oriented style of programming
using namespace std;    //using standard names in library

int main()      //function, anything inside will be executed when file is run
{
    int x, y, z;
    x = y = z = 50;
    int myNum = 5;               // Integer (whole number)
    float myFloatNum = 5.99;     // Floating point number
    double myDoubleNum = 9.98;   // Floating point number
    char myLetter = 'D';         // Character
    bool myBoolean = true;       // Boolean
    string myText = "His car\'s";     // String
    string myOtherText = "WhatUp!";
    string fullText = myText.append(myOtherText);
    int stringCount = fullText.length();
    int otherStringCount = fullText.size();

    cin >> myText;
    cout << "Hello " + myText + "!" << endl;     //console.out "Hello World!" then end the line
    return 0; 
}