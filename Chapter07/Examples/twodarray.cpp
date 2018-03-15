#include <iostream>

void getArray(int arr[][5], int n);
void showArray(const int arr[][5], int n);
double calcAverage(const int arr[][5],int n);

int main()
{
	using namespace std;
	int mark[4][5];
	getArray(mark, 4);
	cout << endl;
	showArray(mark, 4);
	double average = calcAverage(mark, 4);
	cout << "Average: " << average << endl;
	return 0;
}

void getArray(int arr[][5], int n)
{
	using namespace std;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << "Enter student #" << i + 1 << "'s #" << j + 1 << " mark: ";
			cin >> arr[i][j];
		}
	}
}

void showArray(const int arr[][5], int n)
{
	using namespace std;
	for (int i = 0; i < n; i++)
	{
		cout << "Student #" << i + 1 << ": \t";
		for (int j = 0; j < 5; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

double calcAverage(const int arr[][5], int n)
{
	double total = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			total += arr[i][j];
		}
	}
	double ava = total / (n * 5);
	return ava;
}