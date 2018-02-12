#include <iostream>

unsigned int c_in_str(const char * str, char ch);

int main()
{
	using namespace std;
	char mmm[15] = "minimum";

	char * wail = "ululate";

	unsigned int ms = c_in_str(mmm, 'm');
	unsigned int us = c_in_str(wail, 'u');
	cout << ms << " m characters in " << mmm << endl;
	cout << us << " m characters in " << wail << endl;
	return 0;
}

unsigned int c_in_str(const char * str, char ch)
{
	unsigned int count = 0;
	while (*str)		//quit when *str is '\0'
	{
		if (*str == ch)
			count++;
		str++;			//move pointer to next char
	}
	return count;
}