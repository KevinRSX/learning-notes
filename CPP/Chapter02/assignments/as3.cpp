#include <iostream>
void first();
void second();
using namespace std;

int main()
{
	first();
	first();
	second();
	second();
}

void first()
{
	cout << "Three blind mouse." << endl;
}

void second()
{
	cout << "See how they run." << endl;
}