#pragma once
#include <iostream>
class Golf
{
private:
	static const int Len = 40;
	char fullname[Len];
	int handicap;
public:
	Golf(const char * name = "None", int hc = 0);
	void setgolf();
	void show() const;
};