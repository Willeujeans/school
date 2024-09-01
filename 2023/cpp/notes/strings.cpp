#include <iostream>
using namespace std;

int main()
{
	char letter = 'B';
	string phrase = "hello world";
	cout << phrase << endl;	//prints [phrase] to console
	cout << phrase.substr(0, 3) << endl;		
    cout << phrase.substr(3, 2) << endl;

return 0;
}
