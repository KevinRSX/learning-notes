//6.cpp -- fill, show, and reverse an array
#include <iostream>

int fill_array(double ar[], int n);
void show_array(const double ar[], int n);
void reverse_array(double ar[], int n);

const int Size = 5;

int main()
{
	using namespace std;
	double my_array[Size];
	int num;
	num = fill_array(my_array, Size);
	show_array(my_array, num);
	cout << "First reverse:\n";
	reverse_array(my_array, num);
	show_array(my_array, num);
	cout << endl;
	cout << "Second reverse:\n";
	reverse_array(my_array, num);
	reverse_array(my_array + 1, num - 2);
	show_array(my_array, num);
	cout << endl;
	return 0;
}

int fill_array(double ar[], int n)
{
	using namespace std;
	int i;
	for (i = 0; i < n; i++)
	{
		cout << "Enter #" << i + 1 << ": ";
		if (!(cin >> ar[i]))
			break;
	}
	return i;
}

void show_array(const double ar[], int n)
{
	using namespace std;
	for (int i = 0; i < n; i++)
	{
		cout << "#" << i + 1 << ": " << ar[i] << endl;
	}
}

void reverse_array(double ar[], int n)
{
	int i, j;
	for (i = 0, j = n - 1; i < j; i++, j--) 
	{
		double temp;
		temp = ar[i];
		ar[i] = ar[j];
		ar[j] = temp;
	}
}