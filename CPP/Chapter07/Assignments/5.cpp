#include <iostream>

long double calc_factorial(int n);

int main()
{
	using namespace std;
	long co;
	cin >> co;
	long double result = calc_factorial(co);
	cout << fixed << "Result: " << result << endl;
	return 0;
}

long double calc_factorial(int n)
{
	long double total = 1;
	if (n == 0)
	{
		return total;
	}
	else
	{
		total *= n--;
		if (n > 0)
			total *= calc_factorial(n);	//pass the return value of the function to its outer shell
		return total;
	}
}