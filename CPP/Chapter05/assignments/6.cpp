#include <iostream>

int main()
{
	using namespace std;

	const int Year = 3, Month = 12;
	const char * Months[] = { "January","February","March","April","May","June","July","August",
		"September","October","Novemnber","December" };

	int total = 0, sales[Year][Month], yearSum[Year] = { 0 };

	for (int i = 0; i < Year; i++)
	{
		cout << "Enter the sales number in year" << i << endl;
		for (int j = 0; j < Month; j++)
		{
			cin >> sales[i][j];
			yearSum[i] += sales[i][j];
			total += sales[i][j];
		}
	}

	for (int i = 0; i < Year; i++)
	{
		cout << "Year " << i + 1 << ":\t";
		for (int j = 0; j < Month; j++)
		{
			cout << Months[j] << ": " << sales[i][j] << "\t";
		}
		cout << "Year sum: " << yearSum[i] << endl;
	}
	cout << "Total: " << total << endl;

	return 0;
}