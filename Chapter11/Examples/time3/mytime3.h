//mytime3.h -- Time class with friends
#pragma once
#include <iostream>
class Time
{
private:
	int hours;
	int minutes;
public:
	Time();
	Time(int h, int m = 0);
	void AddMin(int m);
	void AddHr(int h);
	void Reset(int h, int m);
	Time operator+(const Time & t) const;
	Time operator-(const Time & t) const;
	Time operator*(double n) const;
	friend Time operator*(double n, Time & t) { return t*n; }
	friend std::ostream & operator<<(std::ostream & os, const Time & t);
};