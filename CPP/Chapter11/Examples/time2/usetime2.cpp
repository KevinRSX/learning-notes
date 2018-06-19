//usetime2.cpp -- using the third draft of the Time class
//compile usetime2.cpp and mytime2.cpp together
#include <iostream>
#include "mytime2.h"

int main()
{
	using std::cout;
	using std::endl;
	Time weeding(4, 35);
	Time waxing(2, 47);
	Time total;
	Time diff;
	Time adjusted;

	cout << "weeding time = ";
	weeding.Show();

	cout << "waxing time = ";
	waxing.Show();

	cout << "Total work time = ";
	total = weeding + waxing;	//using operator+()
	total.Show();

	diff = weeding - waxing;	//using operator-()
	cout << "weeding - waxing = ";
	diff.Show();

	adjusted = total*1.5;		//using operator*()
	cout << "adjusted work time = ";
	adjusted.Show();

	return 0;
}