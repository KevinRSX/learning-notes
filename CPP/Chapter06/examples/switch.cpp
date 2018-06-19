#include <iostream>

using namespace std;
void showMenu(void);
void choose(int);

int main()
{
	showMenu();
	int choice;
	cin >> choice;
	while (choice != 5)
	{
		choose(choice);
		showMenu();
		cin >> choice;
	}
	return 0;
}

void showMenu()
{
	cout << "Please enter 1,2,3,4, or 5\n";
	cout << "(1) alarm\t(2) report\n"
		<< "(3) alibi\t(4) comfort\n"
		<< "(5) quit\n";
}

void choose(int c)
{
	switch (c)
	{
	case 1: cout << "\a\n";
		break;
	case 2: cout << "It's been an excellent week for business.\n"
			<< "Sales are up 120%. Expenses are down 35%.\n\n";
		break;
	case 3: cout << "The boss is in all day.\n\n";
		break;
	case 4: cout << "Your employees think you are the best CEO in the industry.\n\n";
		break;
	default:cout << "That's not a choice.\n\n";
	}
}