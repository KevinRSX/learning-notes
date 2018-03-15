//stock00.cpp -- implementing the Stock Class
//version 00
#include <iostream>
#include "c1stock00.h"

void Stock::acquire(const std::string & co, long n, double pr)
{
	company = co;
	if (n < 0)
	{
		std::cout << "Number of shares can't be negative; " << company << "share set to 0.\m";
		shares = 0;
	}
	else
		shares = n;
	shares_val = pr;
	set_tot();
}

void Stock::buy(long num, double price)
{
	if (num < 0)
	{
		std::cout << "Number of shares purchased can't be negative. Transaction is aborted.\n";
	}
	else
	{
		shares += num;
		shares_val = price;
		set_tot();
	}
}

void Stock::sell(long num, double price)
{
	using std::cout;
	if (num < 0)
	{
		cout << "Number of shares sold can't be negative. Transaction is aborted.\n";
	}
	else if (num > shares)
	{
		cout << "You can't sell more than you have! Transaction is aborted.\n";
	}
	else
	{
		shares -= num;
		shares_val = price;
		set_tot();
	}
}

void Stock::update(double price)
{
	shares_val = price;
	set_tot();
}

void Stock::show()
{
	std::cout << "Company: " << company << " Shares: " << shares << std::endl;
	std::cout << " Share Price :$" << shares_val << " Total Worth: $" << total_val << std::endl;
}