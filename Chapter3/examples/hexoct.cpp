#include <iostream>
using namespace std;
int main()
{
	int chest = 42;
	int waist = 42;
	int inseam = 42;

	cout << "Monsieur cuts a striking figure!" << endl;
	cout << "Chest = " << chest << " (decimal for 42)" << endl;
	cout << hex;
	cout << "Waist = " << waist << " (heximal for 42)" << endl;
	cout << oct;
	cout << "inseam = " << inseam << " (octal for 42)" << endl;
	return 0;
}