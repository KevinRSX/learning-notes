#include "complex0.h"
Complex::Complex(double a, double b)
{
	re = a;
	img = b;
}

Complex Complex::operator+(Complex & z)
{
	return Complex(re + z.re, img + z.img);
}

Complex Complex::operator-(Complex & z)
{
	return Complex(re - z.re, img - z.img);
}

Complex Complex::operator-()
{
	return Complex(-re, -img);
}

Complex Complex::conjugate()
{
	return Complex(re, img);
}


Complex Complex::operator*(double m)
{
	return Complex(m*re, m*img);
}

Complex operator*(double m, Complex & z)
{
	return z*m;
}

Complex operator*(Complex & z1, Complex & z2)
{
	return Complex(z1.re*z2.re - z1.img*z2.img, z1.re*z2.img + z1.img*z2.re);
}

std::ostream & operator<<(std::ostream & os, Complex & z)
{
	if (z.img != 0)
	{
		if (z.img > 0)
		{
			os << z.re << "+" << z.img << "i";
		}
		else if (z.img == 0)
		{
			os << z.re;
		}
		else
		{
			os << z.re << "-" << -z.img << "i";
		}
	}
	else
	{
		if (z.img > 0)
		{
			os << z.img << "i";
		}
		else if (z.img == 0)
		{
			os << z.re;
		}
		else
		{
			os << "-" << -z.img << "i";
		}
	}
	return os;
}

std::istream & operator>>(std::istream & is, Complex & z)
{
	std::cout << "real: ";
	is >> z.re;
	if (!is)
	{
		std::cout << "Done!\n";
		exit;
	}
	else
	{
		std::cout << "imaginary: ";
		is >> z.img;
	}
	return is;
}