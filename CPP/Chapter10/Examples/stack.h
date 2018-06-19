#pragma once
//stack.h -- class definition for the stack ADT
typedef unsigned long Item;
class Stack
{
private:
	enum { MAX = 10 };	//constant specific to class
	Item items[MAX];	//holds stack items
	int top;			//index for top stock item
public:
	Stack();
	bool isempty() const;
	bool isfull() const;
	//push() returns false if stack is already full, true otherwise
	bool push(const Item & item);
	//pop() returns false if stack is empty, true otherwise
	bool pop(Item & item);
};