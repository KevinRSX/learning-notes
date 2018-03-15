#include <iostream>
int main()
{
	using namespace std;
	int foot, inch;
	const int inches_per_foot = 12;

	cout << "Enter your height in inch: ";
	cin >> inch;
	foot = inch / inches_per_foot;
	inch %= inches_per_foot;

	cout << "Your are " << foot << "\'" << inch << "\" tall!" << endl;

	return 0;
}