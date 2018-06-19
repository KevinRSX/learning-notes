//randwalk.cpp -- using the Vector Class
//compile with vector.cpp file
#include <iostream>
#include <cstdlib>	//rand(),srand() prototypes
#include <ctime>
#include <fstream>
#include "vector.h"

int main()
{
	using namespace std;
	using VECTOR::Vector;
	srand(time(0));		//seed random number generator
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	ofstream fout;
	fout.open("random_walk.txt");
	cout << "Enter target distance (q to quit): ";
	while (cin >> target)
	{
		cout << "Enter step length: ";
		if (!(cin >> dstep))
			break;
		fout << "Target distance: " << target << ", Step Size: " << dstep << endl;
		fout << "0: ";
		fout << result << endl;
		int i = 0;
		while (result.magval() < target)
		{
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			steps++;
			i++;
			fout << i << ": ";
			fout << result << endl;
		}
		fout << "After: " << steps << " steps, the subject has the following location:\n";
		fout << result << endl;
		result.polar_mode();
		fout << "or\n";
		fout << result << endl;
		fout << "Average outward distance per step = " << result.magval() / steps << endl;
		steps = 0;
		result.reset(0.0, 0.0);
		fout << endl;
		cout << "Enter the target distance (q to quit): ";
	}
	cout << "See the file in root. Bye!\n";
	cin.clear();
	while (cin.get() != '\n')
		continue;
	return 0;
}