#include <iostream>
using namespace std;
#include <cstring>

struct stringy
{
	char * str;
	int ct;
};

void set(stringy &cstr, const char * words);
void show(const stringy &cstr, int n = 1);
void show(const char * tests, int n = 1);

int main(int argc, char * argv[])
{
	stringy benny;
	char testing[] = "Reality isn't what it used to be.";

	set(benny, testing);
	show(benny);
	show(benny, 2);
	testing[0] = 'D';
	testing[1] = 'u';
	show(testing);
	show(testing, 3);
	show("Done!");
	delete[] benny.str;
	return 0;
}

void set(stringy &cstr, const char * words)
{
	int i = 0;
	while (words[i++]);
	cstr.ct = i;
	cstr.str = new char[cstr.ct + 1];
	strcpy(cstr.str, words);
}

void show(const stringy &cstr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << cstr.str << endl;
	}
}

void show(const char * tests, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << tests << endl;
	}
}