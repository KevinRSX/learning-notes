#include <iostream>
#include <cctype>

int main()
{
	using namespace std;
	const int Max = 10;
	double donation[Max];

	cout << "Enter donation (q to terminate): \n";
	cout << "Donation #1: ";
	int i = 0;
	while (i < Max && (cin >> donation[i]))
	{
		i++;
		cout << "Donation #" << i + 1 << ": ";
	}
	double total = 0;
	for (int j = 0; j < i; j++)
	{
		total += donation[j];
	}
	double average = total / i;
	int higher = 0;
	for (int j = 0; j < i; j++)
	{
		if (donation[j] > average)
		{
			higher++;
		}
	}
	cout << "Average: " << average << endl;
	cout << "Higher values: " << higher << endl;
}