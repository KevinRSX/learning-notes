#include <iostream>
using namespace std;
#include "complex0.h"

int main()
{
	Complex a(3.0, 4.0);
	Complex c;
	cout << "Enter a complex number (q to quit): \n";
	while (cin >> c)
	{
		cout << "c=" << c << endl;
		cout << "~c=" << c.conjugate() << endl;
		cout << "a=" << a << endl;
		cout << "a+c=" << a + c << endl;
		cout << "a-c=" << a - c << endl;
		cout << "a*c=" << a * c << endl;
		cout << "2*c=" << 2 * c << endl;
		cout << "Enter a complex number (q to quit): \n";
	}
}