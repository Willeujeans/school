#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    string color, noun, job;

    cout << "enter a color: ";
    getline(cin, color);

    cout << "enter a noun: ";
    getline(cin, noun);

    cout << "enter a job: ";
    getline(cin, job);

    cout << "Roses are " << color << endl;
    cout << noun <<" are blue" << endl;
    cout << "I love "<< job << endl;
    return 0;
}