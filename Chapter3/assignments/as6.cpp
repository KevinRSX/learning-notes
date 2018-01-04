#include <iostream>
int main()
{
	using namespace std;
	float distance, volume;
	cout << "Enter the distance in kilometers: ";
	cin >> distance;
	cout << "Enter the gasoline consumption in liters: ";
	cin >> volume;

	float consumptionPerUnit = volume / (distance / 100);
	cout << "Your gasoline consumption per 100 km is: " << consumptionPerUnit << endl;

	return 0;
}