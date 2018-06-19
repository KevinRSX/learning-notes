//string2.h -- fixed, augmented and extended string class definition
#pragma once
#include <iostream>
using std::istream;
using std::ostream;

class String
{
private:
	char * str;		//pointer to string
	int len;		//length of string
	static int num_strings;		//number of objects
	static const int CINLIM = 80;	//cin input limit
public:
	//constructors and other methods
	String(const char * s);		//constructor
	String();					//default constructor
	String(const String &);		//copy constructor
	~String();					//destructor
	int length() const { return len; }
	String & stringlow();
	String & stringup();
	int has(const char ch);
	//overloaded operator methods
	String & operator=(const String &);
	String & operator=(const char *);
	char & operator[](int i);
	const char & operator[](int i) const;
	//overloaded operator friends
	friend String operator+(const String & st1, const String & st2);
	friend bool operator<(const String & st, const String & st2);
	friend bool operator>(const String & st1, const String & st2);
	friend bool operator==(const String & st1, const String & st2);
	friend ostream & operator<<(ostream & os, const String & st);
	friend istream & operator>>(istream & os, String & st);
	//static function
	static int HowMany();
};