#include <iostream>

int main()
{
	using namespace std;
	int a = 5;
	int * pa = &a;
	int & ra = *pa;
	cout << "a: " << a << endl;
	cout << "&a: " << &a << endl;
	cout << "pa: " << pa << endl;
	cout << "ra: " << ra << endl << endl;
	int b = 10;
	pa = &b;
	cout << "a: " << a << endl;
	cout << "&a: " << &a << endl;
	cout << "pa: " << pa << endl;
	cout << "ra: " << ra << endl << endl;
	return 0;
}