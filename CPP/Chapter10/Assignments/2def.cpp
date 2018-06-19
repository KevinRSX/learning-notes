#include <iostream>
#include <string>
#include <cstring>
#include "2.h"

Person::Person(const std::string & ln, const char * fn)
{
	strcpy(fname, fn);
	lname = ln;
}

void Person::show() const
{
	if (fname[0] == '\0' || lname[0] == '\0')
		std::cout << "Information not correct\n";
	else
		std::cout << fname << ' ' << lname << std::endl;
}

void Person::FormalShow() const
{
	if (fname[0] == '\0' || lname[0] == '\0')
		std::cout << "Information not correct\n";
	else
		std::cout << lname << ", " << fname << std::endl;
}