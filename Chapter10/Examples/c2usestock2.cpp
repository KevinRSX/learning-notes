//usestock0.cpp -- the client program
//compile with c1stock00.cpp
#include <iostream>
#include "c2stock10.h"

int main()
{
	{
		using std::cout;
		cout << "Using constructors to create new objects\n";
		Stock stock1("NanoSmart", 12, 20.0);		//syntax1
		stock1.show();
		Stock stock2 = Stock("Boffo Objects", 2, 2.0);	//syntax2
		stock2.show();

		cout << "Assigning stock1 to stock2:\n";
		stock2 = stock1;
		cout << "Listing stock1 and stock2:\n";
		stock1.show();
		stock2.show();

		cout << "Using a constructor to reset an object\n";
		stock1 = Stock("Nifty Foods", 10, 50.0);	//temporary object
		cout << "Revised stock1:\n";
		stock1.show();
		cout << "Done\n";
	}
	return 0;
}