#include <iostream>
#include "9.h"

struct CandyBar
{
	char label[20];
	double weight;
	int calories;
};

int main()
{
	using namespace std;
	CandyBar * snack = new CandyBar[3];
	snack[0] = { "fuck you", 3.3, 100 };
	snack[1] = { "motherfucker", 21.2, 30 };
	snack[2] = { "fuck off", 6.4, 89 };

	cout << (snack + 1)->label << endl;
	delete[] snack;
	return 0;
}