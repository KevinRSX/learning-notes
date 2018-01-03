#include <iostream>
int main()
{
	using namespace std;
	int auks, bats, coots;
	//the following statement adds the values as double
	//then converts the result to int
	auks = 19.99 + 11.99;

	//these statements add values as int
	bats = int(19.99) + int(11.99);		//C++ syntax
	coots = (int)19.99 + (int)11.99;	//C syntax
	cout << "auks = " << auks << ", bats = " << bats << ", coots = " << coots << endl;

	char ch = 'Z';
	cout << "The code for " << ch << " is " << int(ch) << endl;	//print as char
	cout << "Yes, the code is ";								//print as int
	cout << static_cast<int>(ch) << endl;
	return 0;
}