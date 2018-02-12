#include <iostream>

using namespace std;
void showMenu(void);
void choose(char);

int main()
{
	showMenu();
	char choice;
	cin >> choice;
	choose(choice);
	while ((choice != 'c') && (choice != 'p') && (choice != 't') && (choice != 'g'))
	{
		cin >> choice;
		choose(choice);
	}

	return 0;
}

void showMenu()
{
	cout << "Please enter one of the following choices:\n";
	cout << "c)carnivore\tp)pianist\nt)tree\t\tg)game\n";
}

void choose(char c)
{
	switch (c)
	{
	case 'c':
		cout << "You chose carnivore.\n";
		break;
	case 'p':
		cout << "You chose pianist.\n";
		break;
	case 't':
		cout << "You chose tree.\n";
		break;
	case 'g':
		cout << "You chose game.\n";
	default:
		cout << "Please enter a c, p, t, or g: ";
	}
}