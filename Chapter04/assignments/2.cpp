#include <iostream>
#include <cstring>
#include <string>

int main()
{
	using namespace std;

	cout << "What is your first name? ";
	string firstName;
	getline(cin, firstName);

	cout << "What is your last name? ";
	string lastName;
	getline(cin,lastName);

	cout << "What letter grade did you receive? ";
	char grade;
	cin >> grade;
	grade++;

	cout << "What is your age? ";
	int age;
	cin >> age;
	cin.get();

	cout << "Name: " << lastName << ", " << firstName << endl;
	cout << "Grade: " << grade << endl;
	cout << "Age: " << age << endl;

	return 0;
}