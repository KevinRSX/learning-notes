//stock20.h -- augmented version

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
	//two constructors
	Stock();	//default constructor
	Stock(const std::string & co, long n = 0, double pr = 0.0);
	~Stock();	//destructor
	void acquire(const std::string & co, long n, double pr);
	void buy(long num, double price);
	void sell(long num, double price);
	void update(double price);
	void show() const;
	const Stock & topval(const Stock & s) const;
};	//note the semicolon at the end