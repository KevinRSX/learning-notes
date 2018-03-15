#pragma once
#include <iostream>
#include <string>
class Person
{
private:
	static const int LIMIT = 25;
	std::string lname;	//person's last name
	char fname[LIMIT];	//person's first name
public:
	Person() {lname = ""; fname[0] = '\0'; }	//#1
	Person(const std::string & ln, const char * fn = "Heyyou");
	//the following methods display lname and faname
	void show() const;			//firstname,lastname format
	void FormalShow() const;	//lastname,firstname format
};