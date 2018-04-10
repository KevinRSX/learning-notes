#include <iostream>
#include <cstdlib>
#include <ctime>
typedef unsigned long Item;

class Stack
{
private:
	enum { MAX = 10 };		//constant specific to class
	Item * pitems;			//holds stack items
	int size;				//number of elements in stack
	int top;				//index for top stack item
public:
	Stack(int n = MAX);			//creates stack with n elements
	Stack(const Stack & st);
	~Stack();
	bool isempty() const;
	bool isfull() const;
	//push() returns false if stack already is full, true otherwise
	bool push(const Item & item);		//add item to stack
	//pop() returns false if stack already is empty, true otherwise
	bool pop(Item & item);				//pop top into item
	Stack & operator=(const Stack & st);
	friend std::ostream & operator<<(std::ostream & os, const Stack & st);
};

int main()
{
	using namespace std;
	srand(time(0));
	Stack socialism(9);
	Item pre[100];
	for (int i = 0; i < 9; i++)
	{
		pre[i] = rand() % 300;
		socialism.push(pre[i]);
		cout << socialism << endl;
	}
	Stack capitalism = socialism;
	for (int i = 0; i < 9; i++)
	{
		capitalism.pop(pre[i]);
		cout << pre[i] << " poped" << endl;
	}
	return 0;
}

Stack::Stack(int n)
{
	size = n;
	top = 0;
	pitems = new Item[size];
}

Stack::Stack(const Stack & st)
{
	size = st.size;
	top = st.top;
	pitems = new Item[size];
	for (int i = 0; i < size; i++)
	{
		pitems[i] = st.pitems[i];
	}
}

Stack::~Stack()
{
	delete[] pitems;
}

bool Stack::isempty() const
{
	return (top == 0);
}

bool Stack::isfull() const
{
	return (top == size);
}

bool Stack::push(const Item & item)
{
	if (isfull())
		return false;
	pitems[top++] = item;
	return true;
}

bool Stack::pop(Item & item)
{
	if (isempty())
		return false;
	item = pitems[--top];	//note: if the latest element's index is x, then the index of top is x+1
}

Stack & Stack::operator=(const Stack & st)
{
	if (this == &st)
		return *this;
	size = st.size;
	top = st.top;
	delete[] pitems;
	pitems = new Item[size];
	for (int i = 0; i < size; i++)
	{
		pitems[i] = st.pitems[i];
	}
	return *this;
}

std::ostream & operator<<(std::ostream & os, const Stack & st)
{
	os << "Size: " << st.size << "; Top: " << st.top << std::endl;
	os << "Top ID: #" << st.pitems[st.top - 1];
	return os;
}