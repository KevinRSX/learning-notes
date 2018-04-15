#pragma once
#include <iostream>

//base class
class Cd		//represents a cd disk
{
private:
	char * performers;
	char * label;
	int selections;		//number of selections
	double playtime;	//play time in minutes
public:
	Cd(char * s1, char * s2, int n, double x);
	Cd(const Cd & d);
	Cd();
	virtual ~Cd();
	virtual void Report() const;	//reports all cd data
	Cd & operator=(const Cd & d);
};

class Classic :public Cd
{
private:
	char * important;
public:
	Classic();
	Classic(char * s1, char * s2, int n, double x, char * im);
	Classic(const Cd & d, char * im);
	Classic(const Classic & cl);
	virtual void Report() const;
	Classic & operator=(const Classic & cl);
	~Classic();
};