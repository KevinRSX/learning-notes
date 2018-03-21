//vector.cpp --methods for the Vector class
#include <cmath>
#include "vector.h"

using namespace std;

namespace VECTOR
{
	//compute degrees in one radian
	const double Rad_to_deg = 45.0 / atan(1.0);


	Vector::Vector()
	{
		x = y = 0.0;
		mode = RECT;
	}

	//construct vector from rectangular coordinates if form is r
	//(the default) or else from polar coordinates if form is p
	Vector::Vector(double n1, double n2, Mode form)
	{
		mode = form;
		if (form == RECT)
		{
			x = n1;
			y = n2;
		}
		else if (form == POL)
		{
			x = set_x();
			y = set_y();
		}
		else
		{
			cout << "Incorrect 3rd argument to Vector(), can only set RECT vectors -- vector set to 0\n";
			x = y = 0.0;
			mode = RECT;
		}
	}

	double Vector::set_x()
	{
		return magval()*cos(angval());
	}

	double Vector::set_y()
	{
		return magval()*sin(angval());
	}

	//reset vector from rectangular coordinates if form is
	//RECT (the default) or else from polar coordinates if
	//form is POL
	void Vector::reset(double n1, double n2, Mode form)
	{
		mode = form;
		if (form == RECT)
		{
			x = n1;
			y = n2;
		}
		else if (form == POL)
		{
			x = n1*cos(n2);
			y = n1*sin(n2);
		}
		else
		{
			cout << "Incorrect 3rd argument to Vector(), can only set RECT vectors -- vector set to 0\n";
			x = y = 0.0;
			mode = RECT;
		}
	}

	Vector::~Vector() {}	//destructor
	void Vector::polar_mode()
	{
		mode = POL;
	}
	void Vector::rect_mode()
	{
		mode = RECT;
	}

	//operator overloading
	Vector Vector::operator+(const Vector & b) const
	{
		return Vector(x + b.x, y + b.y);
	}
	Vector Vector::operator-(const Vector & b) const
	{
		return Vector(x - b.x, y - b.y);
	}
	Vector Vector::operator-() const	//reverse the sign of an operator
	{
		return Vector(-x, -y);
	}
	Vector Vector::operator*(double n) const
	{
		return Vector(n*x, n*y);
	}

	//friend methods
	//multiply n by vector a
	Vector operator*(double n, const Vector & a)
	{
		return a*n;
	}

	//display rectangular coordinates if mode is RECT,
	//else display polar coordinates if mode is POL
	std::ostream & operator<<(std::ostream & os, Vector & v)
	{
		if (v.mode == Vector::RECT)
		{
			os << "(x,y)=(" << v.x << ", " << v.y << ")";
		}
		else if (v.mode == Vector::POL)
		{
			os << "(m,a)=(" << v.magval() << ", " << v.angval() << ")";
		}
		else
			os << "Vecotr object mode is invalid";
		return os;
	}

	double Vector::magval()
	{
		return sqrt(x*x + y*y);
	}

	double Vector::angval()
	{
		if (x == 0 && y == 0)
			return 0.0;
		else
			return Rad_to_deg*atan2(y, x);
	}
}