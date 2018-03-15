#include <iostream>
#include "6.h"

Move::Move(double a, double b)
{
	x = a;
	y = b;
}

void Move::showmove() const
{
	std::cout << "Now (x,y)=(" << x << "," << y << ")\n";
}

Move Move::add(const Move & m) const
{
	Move mk;
	mk.x = x + m.x;
	mk.y = y + m.y;
	return mk;
}

void Move::reset(double a, double b)
{
	x = a;
	y = b;
}