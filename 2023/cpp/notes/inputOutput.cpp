#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    string name;
    cout << "Enter your name: ";
    getline(cin, name);
    cin >> name;

    cout << "Hello " << name << " welcome in!";
    return 0;
}
