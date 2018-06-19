#include <iostream>

int input_array(int ar[], int n);
double calc_average(const int ar[], int n);
void show_score(const int ar[], int n, double a);

const int Size = 10;


int main()
{
	int golf[Size];
	int number = input_array(golf, Size);
	double average = calc_average(golf, number);
	show_score(golf, number, average);
	return 0;

}

int input_array(int ar[], int n)
{
	using namespace std;
	int i;
	for (i = 0; i < n; i++)
	{
		cout << "Enter score #" << i + 1 << " (q to complete): ";
		if (!(cin >> ar[i]))
			break;
	}
	return i;
}

double calc_average(const int ar[], int n)
{
	int total = 0;
	for (int i = 0; i < n; i++)
	{
		total += ar[i];
	}
	double average = total / n;
	return average;
}

void show_score(const int ar[], int n, double a)
{
	using namespace std;
	cout << "Your golf score: \n";
	for (int i = 0; i < n; i++)
	{
		cout << ar[i] << '\t';
	}
	cout << endl;
	cout << "Average: " << a << endl;
}