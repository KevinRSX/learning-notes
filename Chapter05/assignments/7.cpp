#include <iostream>
#include <string>

using namespace std;

struct car
{
	string make;
	int year;
};

int main()
{
	int car_num;
	cout << "How many cars do you wish to catolog? ";
	cin >> car_num;
	cin.get();
	car * collection = new car[car_num];

	for (int i = 0; i < car_num; i++)
	{
		cout << "Please enter the make: ";
		getline(cin, collection[i].make);
		cout << "Please enter the year made: ";
		cin >> collection[i].year;
		cin.get();
	}
	
	cout << "Here is your collection: " << endl;
	for (int i = 0; i < car_num; i++)
	{
		cout << collection[i].year << ' ' << collection[i].make << endl;
	}

	delete[] collection;

	return 0;
}