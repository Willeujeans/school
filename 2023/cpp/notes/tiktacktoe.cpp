#include <iostream>
using namespace std;

int main()
{
    string arraySingle[8] ={"x","o","x","o","x","o"};
    for(int x = 0; x < 8; x++){
        cout << arraySingle[x];
    }

    string array[3][3] ={
		{ "x", "o" },
		{ "o", "x" },
		{ "x", "o" }
		} ;
    for(int x = 0; x < 2; x++){
        for(int y = 0; y< 2; y++){
            cout << array[x][y];
        }
    }
    return 0;
}


