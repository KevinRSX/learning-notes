//usestock2.cpp -- using the Stock class
//compile with c3stock20.cpp
#include <iostream>
#include "c3stock20.h"

const int STKS = 4;
int main()
{
	//create an array with initialized objects
	Stock Stocks[STKS] =
	{
		Stock("NanoSmart",12,20.0),
		Stock("Boffo Objects",200,2.0),
		Stock("Monolithic Obelisks",130,3.25),
		Stock("Fleep Enterprises",60,6.5)
	};
	std::cout << "Stock holdings:\n";
	int st;
	for (st = 0; st < STKS; st++)
		Stocks[st].show();
	const Stock * top = &Stocks[0];
	for (st = 1; st < STKS; st++)
		top = &top->topval(Stocks[st]);
	//now top points to the most valuable holding
	std::cout << "\nMost valuable holding:\n";
	top->show();
	return 0;
}