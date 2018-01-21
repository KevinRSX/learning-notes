#include <iostream>
int main()
{
	using namespace std;
	cout << "Enter two integers (from smaller one to bigger one): " << endl;
	int x, y;
	cin >> x >> y;
	int sum = 0;
	for (; x <= y; x++)
	{
		sum += x;
	}
	cout << "Sum of them: " << sum << endl;
	return 0;
}