//7.cpp -- fill, show, and reverse an array with pointer interval
#include <iostream>

double * fill_array(double * begin, double * end);
void show_array(double * begin, double * end);
void reverse_array(double * begin, double * end);

const int Size = 5;

int main()
{
	using namespace std;
	double my_array[Size];
	double * ep;
	ep = fill_array(my_array, my_array + Size);
	show_array(my_array, ep);
	cout << endl;
	reverse_array(my_array, ep);
	cout << "First reverse:\n";
	show_array(my_array, ep);
	cout << endl;
	reverse_array(my_array, ep);
	reverse_array(my_array + 1, ep - 1);
	cout << "Second reverse:\n";
	show_array(my_array, ep);
	cout << endl;
	return 0;
}

double * fill_array(double * begin, double * end)
{
	using namespace std;
	double * pi;
	for (pi = begin; pi != end; pi++)
	{
		cout << "Enter value: ";
		if (!(cin >> *pi))
			break;
	}
	return pi;
}

void show_array(double * begin, double * end)
{
	using namespace std;
	double * pi;
	int i;
	for (i = 0, pi = begin; pi != end; i++, pi++)
	{
		cout << "#" << i + 1 << ": " << *pi << endl;
	}
}

void reverse_array(double * begin, double * end)
{
	double * p1, * p2;
	for (p1 = begin, p2 = end - 1; p1 < p2; p1++, p2--)
	{
		double temp = *p1;
		*p1 = *p2;
		*p2 = temp;
	}
}