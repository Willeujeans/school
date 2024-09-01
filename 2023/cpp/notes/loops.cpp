#include <iostream>
using namespace std;

int main()      //function, anything inside will be executed
{
    //WHILE loop
    int i = 0;
    while (i < 5) {
        cout << i << "\n";
        i++;
    }

    //DO WHILE loop
    int i = 0;
    do {
        cout << i << "\n";
        i++;
    }
    while (i < 5);

    //FOR loop
    for (int i = 0; i < 5; i++) {
        cout << i << "\n";
    }

    //WHILE with BREAK (breaks out of the whole loop)
    int i = 0;
    while (i < 10) {
        cout << i << "\n";
        i++;
        if (i == 4) {
            break;
        }
    }

    //WHILE with CONTINUE (breaks out of one loop, does the rest)
    int i = 0;
    while (i < 10) {
        if (i == 4) {
        i++;
        continue;
        }
        cout << i << "\n";
        i++;
    }
}
