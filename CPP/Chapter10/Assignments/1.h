#pragma once
#include <string>

class Account
{
private:
	std::string name;
	long number;
	double credit;
public:
	Account();
	Account(std::string n, long mnum, double mcredit);
	void show();
	void deposit(double money);
	void checkout(double money);
};