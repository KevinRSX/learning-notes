//8b.cpp -- use array in a structure to record season sales
#include <iostream>

const int Seasons = 4;
const char * Snames[Seasons] = { "spring","summer","autumn","winter" };

void show(const double ar[], int n);
void fill(double ar[], int n);

struct price
{
	double sales[Seasons];
};

int main()
{
	price year;
	fill(year.sales, Seasons);
	show(year.sales, Seasons);
}


void show(const double ar[], int n)
{
	using namespace std;
	cout << "EXPENSES\n";
	for (int i = 0; i < n; i++)
	{
		cout << Snames[i] << ": " << ar[i] << endl;
	}
}

void fill(double ar[], int n)
{
	using namespace std;
	for (int i = 0; i < n; i++)
	{
		cout << "Enter " << Snames[i] << " expenses: ";
		while (!(cin >> ar[i]))
		{
			while (cin.get() != '\n')
				continue;
			cout << "Enter " << Snames[i] << " expenses: ";
		}
	}
}