#include <iostream>
using namespace std;

int main()
{
    int size = 0;
    int storage[20];    //declare the size of the array when initilized
    int luckyNums[] = {4,8,15,20,25};   //declare the size and what's inside the slots when initilized
    string letters[2][4] = {    //declare a nested array
        { "A", "B", "C", "D" },
        { "E", "F", "G", "H" }
    };
    size = sizeof(luckyNums) / sizeof(int);    //Get the size of an array
    luckyNums[10] = 100;    //set array slot to a new variable
    cout << luckyNums[2];   //outputs to the console
    return 0;
}