#include <iostream>
int main()
{
	using namespace std;
	long long seconds;
	cout << "Enter the number of seconds: ";
	cin >> seconds;
	int days, hours, minutes, restSeconds;
	const int sec_per_min = 60;
	const int min_per_hr = 60;
	const int hr_per_day = 24;

	
	days = seconds / (sec_per_min * min_per_hr * hr_per_day);
	hours = (seconds % (sec_per_min * min_per_hr * hr_per_day)) / (sec_per_min * min_per_hr);
	minutes = (seconds % (sec_per_min * min_per_hr * hr_per_day)) % (sec_per_min * min_per_hr) / (sec_per_min);
	restSeconds = (seconds % (sec_per_min * min_per_hr * hr_per_day)) % (sec_per_min * min_per_hr) % (sec_per_min);

	cout << seconds << " seconds = " << days << " days, " << hours << " hours, " << minutes << " minutes, " << restSeconds << " seconds";
	return 0;
}