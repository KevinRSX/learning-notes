//stonewt1.h -- revised definition for the Stonewt class
#pragma once
class Stonewt
{
private:
	enum { Lbs_per_stn = 14 };
	int stone;			//whole stones
	double pds_left;	//fractional pounds
	double pounds;		//entire weight in pounds
public:
	Stonewt(double lbs);	//constructor for double pounds
	Stonewt(int stn, double lbs);	//constructor for stone, lbs
	Stonewt();
	~Stonewt();
	void show_lbs() const;	//show weight in pounds format
	void show_stn() const;	//show weight in stone format
	//conversion functions
	operator int() const;
	operator double() const;
};