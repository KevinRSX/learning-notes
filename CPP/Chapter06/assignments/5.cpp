#include <iostream>

const float inRate1 = 0.1;
const float inRate2 = 0.15;
const float inRate3 = 0.2;
float calcTax(int);

int main()
{
	using namespace std;
	int salary;
	cout << "Enter the salary: ";

	while (cin >> salary&&salary > 0)
	{
		float tax = calcTax(salary);
		cout << "Tax = " << tax << "tvarps\n";
		cout << "Enter the salary: ";
	}
	cout << "Terminating..";
	return 0;
}

float calcTax(int s)
{
	float tax;
	if (s <= 5000)
	{
		tax = 0.0;
	}
	else if (5000 < s&&s <= 15000)
	{
		tax = 5000 * 0.0 + (s - 5000)*inRate1;
	}
	else if (15000 < s&&s <= 35000)
	{
		tax = 5000 * 0.0 + 10000 * inRate1 + (s - 15000)*inRate2;
	}
	else if (s > 35000)
	{
		tax = 5000 * 0.0 + 10000 * inRate1 + 20000 * inRate2 + (s - 35000)*inRate3;
	}
	return tax;
}