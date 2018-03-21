#pragma once
#include <iostream>
class Complex
{
private:
	double re;
	double img;
public:
	Complex(double a = 0, double b = 0);
	Complex operator+(Complex & z);
	Complex operator-(Complex & z);
	Complex operator-();
	Complex conjugate();
	Complex operator*(double m);
	friend Complex operator*(double m, Complex & z2);
	friend Complex operator*(Complex & z1, Complex & z2);
	friend std::ostream & operator<<(std::ostream & os, Complex & z);
	friend std::istream & operator>>(std::istream & is, Complex & z);
};