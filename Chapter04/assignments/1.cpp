#include <iostream>
#include <cstring>

int main()
{
	using namespace std;
	
	cout << "What is your first name? ";
	char firstName[20];
	cin.getline(firstName, 20);
	
	cout << "What is your last name? ";
	char lastName[10];
	cin.getline(lastName, 10);
	
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