#include <iostream>
#include <array>

int main()
{
	using namespace std;
	const int ArSize = 101;
	array <int, ArSize> numbers;
	cout << "0! = " << 1 << endl;
	long double factorials = 1;
	for (int i = 1; i < ArSize; i++)
	{
		numbers[i] = i;
		factorials *= numbers[i];
		cout << i << "! = " << factorials << endl;
	}

	return 0;
}