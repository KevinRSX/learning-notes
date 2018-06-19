#include <iostream>
void showTime(int, int);
using namespace std;

int main()
{
	cout << "Enter the number of hours: ";
	int hours;
	cin >> hours;

	cout << "Enter the number of minutes: ";
	int minutes;
	cin >> minutes;

	showTime(hours, minutes);

	return 0;
}

void showTime(int h, int m)
{
	cout << "Time: " << h << " : " << m << endl;
}