//vector.h -- Vector class with <<, mode state
#pragma once
#include <iostream>
namespace VECTOR
{
	class Vector
	{
	public:
		enum Mode { RECT, POL };
		//RECT	FOR RECTANGULAR, POL for polar modes
	private:
		double x;		//horizontal value
		double y;		//vertical value
		//double mag;		//length of vector
		//double ang;		//direction of vector in degrees
		Mode mode;
		//private methods for setting values
		double set_x();
		double set_y();
	public:
		Vector();
		Vector(double n1, double n2, Mode form = RECT);
		void reset(double n1, double n2, Mode form = RECT);
		~Vector();
		//report x, y, magnitude, and angle
		double xval() const { return x; }
		double yval() const { return y; }
		double magval();
		double angval();
		void polar_mode();	//set mode to polar
		void rect_mode();
		//operator overloading
		Vector operator+(const Vector & b) const;
		Vector operator-(const Vector & b) const;
		Vector operator-() const;
		Vector operator*(double n) const;
		//friends
		friend Vector operator*(double n, const Vector & a);
		friend std::ostream & operator<<(std::ostream & os, Vector & v);
	};
}