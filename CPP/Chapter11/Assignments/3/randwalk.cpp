//randwalk.cpp -- using the Vector Class
//compile with vector.cpp file
#include <iostream>
#include <cstdlib>	//rand(),srand() prototypes
#include <ctime>
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
	int times;
	int max = 0, min = 1000000, sum = 0;
	cout << "Enter the number of times you want to test: ";
	cin >> times;
	cout << "Enter target distance (q to quit): ";
	cin >> target;
	cout << "Enter step length: ";
	cin >> dstep;
	for (int i = 0; i < times; i++)
	{
		while (result.magval() < target)
		{
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			steps++;
		}
		/*cout << "After: " << steps << " steps, the subject has the following location:\n";
		cout << result << endl;
		result.polar_mode();
		cout << "or\n" << result << endl;
		cout << "Average outward distance per step = " << result.magval() / steps << endl;*/
		sum += steps;
		max = max > steps ? max : steps;
		min = min < steps ? min : steps;
		steps = 0;
		result.reset(0.0, 0.0);
	}
	cout << "High: " << max << endl;
	cout << "Mean: " << sum / (double)times << endl;
	cout << "Low: " << min << endl;
	cout << "Bye!\n";
	cin.clear();
	while (cin.get() != '\n')
		continue;
	return 0;
}