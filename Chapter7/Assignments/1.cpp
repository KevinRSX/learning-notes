#include <iostream>
double har_mean(double x, double y);

int main()
{
	using namespace std;
	double x, y;
	cout << "Enter two numbers (to quit, input 0 for any number):\n";
	while (cin >> x >> y && (x != 0 && y != 0))
	{
		double harmonic = har_mean(x, y);
		cout << "Harmonic Mean: " << harmonic << endl;
		cout << "Enter two numbers (to quit, input 0 for any number):\n";
	}
	cout << "Done!\n";
	return 0;
}

double har_mean(double x, double y)
{
	double hm = 2 * x*y / (x + y);
	return hm;
}