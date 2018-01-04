#include <iostream>
int main()
{
	using namespace std;
	float europe;
	cout << "Enter your consumption of gasoline in European style: ____L/100km\b\b\b\b\b\b\b\b\b\b\b";
	cin >> europe;
	const float kmToMiles = 62.14;
	const float galToLiters = 3.875;
	float us = (galToLiters*kmToMiles) / europe;
	cout << "In US style, your consumption is " << us << "mpg." << endl;

	return 0;
}