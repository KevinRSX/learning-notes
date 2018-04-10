//strng.cpp -- StringBad class methods
#include <cstring>
#include "strngbad.h"
using std::cout;

//initializing static class member
int StringBad::num_strings = 0;

//class methods
//construct StringBad from C string
StringBad::StringBad(const char * s)
{
	len = std::strlen(s);			//set size
	str = new char[len + 1];		//allocate storage
	std::strcpy(str, s);			//initialize pointer
	num_strings++;					//set object count
	cout << num_strings << ": \"" << str << "\"objects created\n";	//for your information
}

StringBad::StringBad()
{
	len = 4;
	str = new char[4];
	std::strcpy(str, "C++");		//default string
	num_strings++;
	cout << num_strings << ": \"" << str << "\"objects created\n";	//for your information
}

StringBad::~StringBad()		//necessary destructor
{
	cout << "\"" << str << "\"obeject deleted, ";		//FYI
	--num_strings;		//required
	cout << num_strings << " left\n";					//FYI
	delete[] str;		//required
}

std::ostream & operator<<(std::ostream & os, const StringBad & st)
{
	os << st.str;
	return os;
}