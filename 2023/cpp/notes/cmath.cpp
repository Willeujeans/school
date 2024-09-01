#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int num = pow(2,5);	//uses cmath to raise 2 to the power of 5
	int num = sqrt(36);	//uses cmath to square root 36
	int num = round(1.6);	//rounds up on 5 or above else round down
	int num = ceil(1.6);	//always rounds up
	int num = floor(1.6);	//always rounds down
	int num = max(5, 10);	//returns highest number
	int num = min(5, 10);	//returns lowest number
	int num = fmax(3, 10);	//returns highest number
	int num = fmin(3, 10);	//returns lowest number

	return 0;
}
