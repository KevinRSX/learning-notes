#include <iostream>
double toAU(double);

int main()
{
	using namespace std;
	cout << "Enter the number of light years: ";
	double lightYear;
	cin >> lightYear;

	double astronomicalUnit;
	astronomicalUnit = toAU(lightYear);
	cout << lightYear << " light years = " << astronomicalUnit << " astronomical units." << endl;

	return 0;
}

double toAU(double ly)
{
	return 63420 * ly;
}