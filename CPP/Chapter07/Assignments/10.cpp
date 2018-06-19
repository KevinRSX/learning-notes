#include <iostream>

double add(double x, double y);
double minu(double x, double y);
double multiply(double x, double y);
double calculate(double x, double y, double(*pf)(double, double));

int main()
{
	using namespace std;
	double a, b;
	double(*pf[3])(double, double);
	pf[0] = add;
	pf[1] = minu;
	pf[2] = multiply;
	cout << "Enter to numbers: (q to quit)\n";
	while (cin >> a >> b)
	{
		for (int i = 0; i < 3; i++)
		{
			double t = calculate(a, b, pf[i]);
			cout << "Result " << i + 1 << ": " << t << endl;
		}
	}
}

double add(double x, double y)
{
	return x + y;
}
double minu(double x, double y)
{
	return x - y;
}
double multiply(double x, double y)
{
	return x / y;
}
double calculate(double x, double y, double(*pf)(double, double))
{
	return (*pf)(x, y);
}