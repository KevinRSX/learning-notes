//stone.cpp -- user-defined conversions
//compile with stonewt.cpp
#include <iostream>
using std::cout;
#include "stonewt.h"
void display(const Stonewt & st, int n);
int main()
{
	Stonewt incognito = 275;	//uses constructor for conversion
	//Actually, line 9 is equivalent with Stonewt incognito = Stonewt(275);
	//That is the implicit form of type conversion (double to Stonewt)
	//Since there is a method Stonewt::Stonewt(double);
	Stonewt wolfe(285.7);
	//also equivalent with Stone wolfe = 285.7;
	Stonewt taft(21, 8);

	cout << "The celebrity weighed ";
	incognito.show_stn();
	cout << "The detective weighed ";
	wolfe.show_stn();
	cout << "The president weighed ";
	taft.show_lbs();
	incognito = 276.8;	//also invokes implicit type conversion
	taft = 325;
	cout << "After dinner, the celebrity weighed ";
	incognito.show_stn();
	cout << "After dinner, the president weighed ";
	taft.show_lbs();
	display(taft, 2);
	cout << "The wrestler weighed even more.\n";
	display(422, 2);
	cout << "No stone left unearned\n";
	return 0;
}

void display(const Stonewt & st, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Wow! ";
		st.show_stn();
	}
}