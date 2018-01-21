#include <iostream>

int main()
{
	using namespace std;

	int sum = 0;
	while (1)
	{
		int n;
		cout << "Enter a number (0 to end): ";
		cin >> n;
		if (n == 0) break;
		sum += n;
		cout << "Current sum = " << sum << ".\n";
	}

	return 0;
}