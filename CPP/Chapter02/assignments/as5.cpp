#include <iostream>
double toFahrenheit(double);

int main()
{
	using namespace std;
	cout << "Please enter a Celsius value: ";
	double celsius;
	cin >> celsius;

	double fahrenheit = toFahrenheit(celsius);
	cout << celsius << " degrees Celsius is " << fahrenheit << " degrees Fahrenheit." << endl;

	return 0;
}

double toFahrenheit(double label)
{
	double fahrenheit;
	fahrenheit = 9 * label / 5 + 32;
	return fahrenheit;
}