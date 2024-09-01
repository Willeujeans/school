#include <iostream>
using namespace std;


void myFunction(string parameter1, string parameter2, string parameter3) {
  // code to be executed
  cout << "I just got executed!";
}

//function has a default country value
void myOtherFunction(string country = "Norway") {
  cout << country << "\n";
}

//function with references as params
void swapNums(int &x, int &y) {
  int z = x;
  x = y;
  y = z;
}

int num1 = 25;
int num2 = 15;

int sum(int k) {
  if (k > 0) {
    return k + sum(k - 1);
  } else {
    return 0;
  }
}

int main(){
  myFunction("my","name","will"); // call the function
  myOtherFunction("America");
  swapNums(num1, num2);
  sum(10);
  return 0;
}