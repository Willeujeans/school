#include <iostream>
using namespace std;

    struct {    //basically an object that holds pieces of data thats linked together
        string brand;
        string model;
        int year;
    } myCar1, myCar2; // We can add variables by separating them with a comma here

    struct car {    // This is a named structure
        string brand;
        string model;
        int year;
    };

int main(){
    myCar1.brand = "BMW";   //Put data into the first structure
    myCar2.brand = "Ford";  //Put data into the second structure
    cout << myCar1.brand;
}



