//stock00.h -- Stock Class interface
//version 00
#pragma once
#include <string>

class Stock	//class declaration
{
private:
	std::string company;
	long shares;
	double shares_val;
	double total_val;
	void set_tot() { total_val = shares*shares_val; }
public:
	void acquire(const std::string & co, long n, double pr);
	void buy(long num, double price);
	void sell(long num, double price);
	void update(double price);
	void show();
};	//note the semicolon at the end