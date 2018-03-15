#include <iostream>
#include "3.h"
#include <cstring>

Golf::Golf(const char * name, int hc)
{
	strcpy(fullname, name);
	handicap = hc;
}

void Golf::setgolf()
{
	using namespace std;
	cout << "Enter name: ";
	cin.getline(fullname, Len);
	cout << "Enter handicap: ";
	cin >> handicap;
}

void Golf::show() const
{
	using std::cout;
	using std::endl;
	cout << "NAME: " << fullname << endl;
	cout << "Handicap: " << handicap << endl;
	cout << endl;
}