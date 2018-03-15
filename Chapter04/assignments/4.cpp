#include <iostream>
#include <cstring>
#include <string>

int main()
{
	using namespace std;
	string firstName;
	string lastName;
	cout << "Enter your first name: ";
	cin >> firstName;
	cout << "Enter your last name: ";
	cin >> lastName;
	lastName += ", " + firstName;
	cout << "Here is the information in a single string: " << lastName << endl;

	return 0;
}