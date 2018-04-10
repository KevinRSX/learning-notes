//string1.cpp -- String class methods
#include <cstring>
#include "string1.h"

using std::cin;
using std::cout;

int String::num_strings = 0;

//static method

int String::HowMany()
{
	return num_strings;
}

//class methods
String::String(const char * s)		//construct string from cstring
{
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	num_strings++;
}

String::String()					//default constructor
{
	len = 4;
	str = new char[1];
	str[0] = '\0';
	num_strings++;
}

String::String(const String & st)
{
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	//since it is a constructor used in initialization,
	//there is no need to use delete operator
}

String::~String()
{
	--num_strings;
	delete[] str;
}

//overload operator methods

String & String::operator=(const String & st)
{
	if (this == &st)
		return *this;
	delete[] str;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	return *this;
}

String & String::operator=(const char * s)
{
	delete[] str;
	len = strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	return *this;
}

char & String::operator[](int i)		//read & write
{
	return str[i];
}

const char & String::operator[](int i) const	//read only
{
	return str[i];
}

//overloaded operator friends
bool operator<(const String & st1, const String & st2)
{
	return(std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String & st1, const String & st2)
{
	return(std::strcmp(st1.str, st2.str) > 0);
}

bool operator==(const String & st1, const String & st2)
{
	return(std::strcmp(st1.str, st2.str) == 0);
}

//simple String output
ostream & operator<<(ostream & os, const String & st)
{
	os << st.str;
	return os;
}

//quick and dirty string input
istream & operator>>(istream & is, String & st)
{
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if (is)
		st = temp;		//using assignment function
	while (is&&is.get() != '\n')
		continue;
	return is;
	
}
