#include <iostream>
#define ZERO 0
#include <climits>
int main()
{
	using namespace std;
	short sam = SHRT_MAX;
	unsigned short sue = sam;

	cout << "Sam has " << sam << " dollars and sue has " << sue;
	cout << " dollars deposited." << endl
		<< "Add $1 to each account." << endl << "Now ";
	sam++;
	sue++;
	cout << "Sam has " << sam << " dollars and Sue has " << sue;
	cout << " dollars deposited." << endl << "Poor Sam!";

	sam = ZERO;
	sue = ZERO;
	cout << "Sam has " << sam << " dollars and sue has " << sue;
	cout << " dollars deposited." << endl
		<< "Take $1 from each account." << endl << "Now ";
	sam--;
	sue--;
	cout << "Sam has " << sam << " dollars and Sue has " << sue;
	cout << " dollars deposited." << endl << "Lucky Sue!";
}