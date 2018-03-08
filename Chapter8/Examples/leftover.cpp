//leftover.cpp -- overloading the left() function
#include <iostream>

unsigned long left(unsigned long num, unsigned int ct);
char * left(const char * str, int n = 1);

int main(int argc, char * argv)
{
	using namespace std;
	char * trip = "Hawaii!!";	//test value
	unsigned long n = 12345678;	//test value
	int i;
	char * temp;

	for (int i = 1; i < 10; i++)
	{
		cout << left(n, i) << endl;
		temp = left(trip, i);
		cout << temp << endl;
		delete[] temp;	//point to temporary storage
	}
}

//This function returns the first ct digits of the number num.
unsigned long left(unsigned long num, unsigned int ct)
{
	unsigned digits = 1;
	unsigned long n = num;

	while (n /= 10)
	{
		digits++;
	}
	if (digits > ct)
	{
		ct = digits - ct;
		while (ct--)
		{
			num /= 10;
		}
		return num;
	}
	else
		return num;
}

//This function returns a pointer to a new string
//consisting of the first n characters in the str string
char * left(const char * str, int n)
{
	if (n < 0)
		n = 0;
	char * p = new char[n + 1];
	int i;
	for (i = 0; str[i] && i < n; i++)
	{
		p[i] = str[i];
	}
	while (i <= n)
	{
		p[i++] = '\0';
	}
	return p;
}