#include <iostream>
int main()
{
	using namespace std;
	int degrees, minutes, seconds;
	cout << "Enter a latitude in degrees, minutes, and seconds:" << endl;
	cout << "First, enter the degrees: ";
	cin >> degrees;
	cout << "Next, enter the minutes of arc: ";
	cin >> minutes;
	cout << "Finally, enter the seconds of arc: ";
	cin >> seconds;

	const double min_per_degree = 60;
	const double sec_per_min = 60;
	double latitude = degrees + (minutes / min_per_degree) + (seconds / sec_per_min / min_per_degree);

	cout << degrees << " degrees, " << minutes << " minutes, " << seconds << " seconds = " << latitude << " degrees" << endl;
}