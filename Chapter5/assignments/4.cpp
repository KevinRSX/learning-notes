#include <iostream>

int main()
{
	using namespace std;

	const int Capital = 100;
	const float InterD = 0.1;
	const float InterC = 0.05;
	float sumD = Capital, sumC = Capital;
	int year;

	for (year = 0; ; year++)
	{
		sumD += Capital*InterD;
		sumC *= (1 + InterC);
		if (sumC > sumD) break;
	}

	cout << year << endl;
	cout << "Cleo: " << sumC << endl;
	cout << "Daphne: " << sumD << endl;
}