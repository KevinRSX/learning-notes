#include <iostream>
#include <cmath>

struct polar
{
	double distance;
	double angle;
};

struct rect
{
	double x;
	double y;
};

void show_polar(polar stats);
polar calc_polar(rect coordinates);

int main()
{
	using namespace std;
	cout << "Enter the x and y values: ";
	rect user_point;
	polar pol_coo;
	while (cin >> user_point.x >> user_point.y)
	{
		pol_coo = calc_polar(user_point);
		show_polar(pol_coo);
		cout << "Next two numbers (q to quit): ";
	}
	cout << "Bye!\n";
	return 0;
}

polar calc_polar(rect coordinates)
{
	polar result;
	const double Rad_to_deg = 57.29577951;
	result.distance = sqrt(coordinates.x*coordinates.x + coordinates.y*coordinates.y);
	result.angle = atan2(coordinates.y, coordinates.x)*Rad_to_deg;
	return result;
}

void show_polar(polar stats)
{
	using namespace std;
	cout << "Distance = " << stats.distance << ", angle = " << stats.angle << " degrees\n";
}