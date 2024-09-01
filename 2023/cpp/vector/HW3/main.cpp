#include "basic_vector.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main()
{
    basic_vector<int> bv;
    cout << boolalpha << "Initial size should be 0: " << bv.size() << '\n';
    cout << "Initial capacity should be 1: " << bv.capacity() << '\n';
    cout << "Vector should be empty: " << bv.empty() << '\n';
    return 0;
}
