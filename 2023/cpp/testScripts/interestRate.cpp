#include <iostream>

using namespace std;

//input netBalance, d1, payment, d2, interestRate
int main(int argc, char *argv[]){
    for (int i = 0; i < argc; i++) {
        printf(argv[i]);
    }
  double netBalance,payment,d1, d2, interestRate;
  d1 = atof(argv[2]);
  payment = atof(argv[3]);
  d2 = atof(argv[4]);
  interestRate = atof(argv[5]);
  double averageDailyBalance = 0;
  double interest = 0;
  averageDailyBalance = (netBalance * d1 - payment * d2) / d1;
  interest = averageDailyBalance * interestRate;
  cout << interest;
  return 0;
}


//output interest
