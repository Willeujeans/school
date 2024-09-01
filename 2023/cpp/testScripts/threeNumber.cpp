#include <iostream>
using namespace std;
int main() {
// Write your main here
double num1, num2, num3;
double storage;
cout << " Enter three numbers ";
cin >> num1 >> num2 >> num3;
cout << endl;
if (num1 > num2){
    storage = num1;
    num1 = num2;
    num2 = storage;
}
cout << " The numbers are in assending order are: ";
if ( num3 <= num1){
    cout << num3 << " " << num1 << " " << num2 << endl;
    }else if ( num1 <= num3 && num3 <= num2 ){
        cout << num1 << " " << num3 << " " << num2 << endl;
    }else{
        cout << num1 << " " << num2 << " " << num3 << endl;
    }
return 0;
}