#include <iostream>

using namespace std;
const int strsize = 10;
void showMenu(void);
void choose(void);

struct bop
{
	char fullname[strsize];
	char title[strsize];
	char bopname[strsize];
	int preference;
};
bop programmer[3]=
{
	{ "A.K.","St.","Ho",0 },
	{ "B.K.","Dr.","CA",1 },
	{ "C.K.","Prof.","Sum",2 }
};

int main()
{
	showMenu();
	choose();
	return 0;
}

void showMenu()
{
	cout << "Benevolt Order of Programmers Report\n";
	cout << "a. display by name\tb. display by title\n";
	cout << "c. display by popname\td. display by preference\n";
	cout << "q. quit\n";
}

void choose()
{
	cout << "Enter your choice: ";
	char choice;
	cin >> choice;
	while (choice != 'q')
	{
		switch (choice)
		{
		case 'a':
			for (int i = 0; i < 3; i++)
			{
				cout << programmer[i].fullname << endl;
			}
			cout << "Next choice: ";
			cin >> choice;
			break;
		case 'b':
			for (int i = 0; i < 3; i++)
			{
				cout << programmer[i].title << endl;
			}
			cout << "Next choice: ";
			cin >> choice;
			break;
		case 'c':
			for (int i = 0; i < 3; i++)
			{
				cout << programmer[i].bopname << endl;
			}
			cout << "Next choice: ";
			cin >> choice;
			break;
		case 'd':
			for (int i = 0; i < 3; i++)
			{
				switch (programmer[i].preference)
				{
				case 0:
					cout << programmer[i].fullname << endl;
					break;
				case 1:
					cout << programmer[i].title << endl;
					break;
				case 2:
					cout << programmer[i].bopname << endl;
					break;
				}
			}
			cout << "Next choice: ";
			cin >> choice;
			break;
		default:
			cout << "Choose again: \n";
			cin >> choice;
		}
	}
}