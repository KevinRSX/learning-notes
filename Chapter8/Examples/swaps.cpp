#include <iostream>

void swapr(int & a, int & b);	//a, b are alisases for ints
void swapp(int * p, int * q);	//p, q are addresses of ints
void swapv(int a, int b);		//a, b are new variables

int main()
{
	using namespace std;
	int wallet1 = 300;
	int wallet2 = 400;
	cout << "wallet1 = $" << wallet1;
	cout << " wallet2 = $" << wallet2 << endl;

	cout << "Using references to swap contents:\n";
	swapr(wallet1, wallet2);	//pass variables
	cout << "wallet1 = $" << wallet1;
	cout << " wallet2 = $" << wallet2 << endl;

	cout << "Using references to swap contents:\n";
	swapp(&wallet1, &wallet2);	//pass adresses of variables
	cout << "wallet1 = $" << wallet1;
	cout << " wallet2 = $" << wallet2 << endl;

	cout << "Using references to swap contents:\n";
	swapv(wallet1, wallet2);	//pass values of variables
	cout << "wallet1 = $" << wallet1;
	cout << " wallet2 = $" << wallet2 << endl;

	return 0;
}

void swapr(int & a, int & b)	//use references
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void swapp(int * p, int * q)	//use pointers
{
	int temp;
	temp = *q;
	*q = *p;
	*p = temp;
}

void swapv(int a, int b)		//try using values
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}