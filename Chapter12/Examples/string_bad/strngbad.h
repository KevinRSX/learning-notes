//strngbad.h -- flawed string class definition
#pragma once
#include <iostream>

class StringBad
{
private:
	char * str;				//pointer to string
	int len;				//length of string
	static int num_strings;	//number of objects, static makes there only one copy in all objects
public:
	StringBad(const char * s);	//constructor
	StringBad();				//default constructor
	~StringBad();				//destructor
	//friend function
	friend std::ostream & operator<<(std::ostream & os, const StringBad & st);
};