#include <iostream>
int toMonth(int);

int main()
{
	using namespace std;
	cout << "Enter your age: ";
	int age;
	cin >> age;

	int month = toMonth(age);
	cout << "You have lived meaninglessly for " << month << " months." << endl;

	return 0;
}

int toMonth(int age)
{
	return age * 12;
}