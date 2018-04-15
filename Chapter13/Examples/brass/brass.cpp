//brass.cpp -- bank account class methods
#include <iostream>
#include <iomanip>
#include "brass.h"

using std::cout;
using std::endl;
using std::string;

//Brass methods
Brass::Brass(const string & s, long an, double bal)
{
	fullName = s;
	acctNum = an;
	balance = bal;
}

void Brass::Deposit(double amt)
{
	if (amt < 0)
		cout << "Negative deposit not allowed; deposit is cancelled.\n";
	else
		balance += amt;
}

void Brass::Withdraw(double amt)
{
	cout << std::fixed;
	if (amt < 0)
	{
		cout << "Withdrawal amount must be positive; withdraw cancelled.\n";
	}
	else if (amt <= balance)
	{
		balance -= amt;
	}
	else
		cout << "Withdrawal amount of $" << std::setprecision(2) << amt << " exceeds your balance.\n" << "Withdrawal canceled.\n";
}

double Brass::Balance() const
{
	return balance;
}

void Brass::ViewAcct() const
{
	
	cout << std::fixed;
	cout << "Client: " << fullName << endl;
	cout << "Account number: " << acctNum << endl;
	cout << "Balance: $" << std::setprecision(2) << balance << endl;
}

//BrassPlus Methods
BrassPlus::BrassPlus(const string & s, long an, double bal, double ml, double r) :Brass(s, an, bal)
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}

BrassPlus::BrassPlus(const Brass & ba, double ml, double r) :Brass(ba)
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}

//redefine how ViewAcct() works
void BrassPlus::ViewAcct() const
{
	cout << std::fixed;
	Brass::ViewAcct();	//display base portion 
	cout << "Maximum loan: $" << maxLoan << endl;
	cout << "Owed to bank: $" << owesBank << endl;
	cout << "Loan Rate: " << 100 * rate << "%\n";
}

//redefine how Withdraw() works
void BrassPlus::Withdraw(double amt)
{
	cout << std::fixed;
	double bal = Balance();
	if (amt <= bal)
		Brass::Withdraw(amt);
	else if (amt <= bal + maxLoan - owesBank)
	{
		double advance = amt - bal;
		owesBank += advance*(1.0 + rate);
		cout << "Bank advance: $" << advance << endl;
		cout << "Finance charge: $" << advance*rate << endl;
		Deposit(advance);
		Brass::Withdraw(amt);
	}
	else
		cout << "Credit limit exceed. Transaction cancelled.\n";
}