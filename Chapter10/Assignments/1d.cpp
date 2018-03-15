#include <iostream>
#include <string>
#include "1.h"

Account::Account()
{
	name = "NONE";
	number = 00000000;
	credit = 0.0;
}

Account::Account(std::string n, long mnum, double mcredit)
{
	name = n;
	number = mnum;
	credit = mcredit;
}

void Account::show()
{
	using namespace std;
	cout << "User Name: " << name << endl;
	cout << "User ID: " << number << endl;
	cout << "Current credit balance: ";
	if (credit >= 0)
		cout << credit << endl;
	else
		cout << -credit << "DR" << endl;
}

void Account::deposit(double money)
{
	if (money < 0)
	{
		std::cout << "You should deposit positive amount of money!\n";
	}
	else
		credit += money;
}

void Account::checkout(double money)
{
	if (money < 0)
	{
		std::cout << "You should checkout positive amount of money!\n";
	}
	else
		credit -= money;
}