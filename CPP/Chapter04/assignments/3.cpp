#include <iostream>
#include <cstring>

int main()
{
	using namespace std;
	char firstName[10];
	char lastName[20];
	cout << "Enter your first name: ";
	cin >> firstName;
	cout << "Enter your last name: ";
	cin >> lastName;
	strcat(lastName, ", ");
	strcat(lastName, firstName);
	cout << "Here is the information in a single string: " << lastName << endl;

	return 0;
}