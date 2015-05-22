#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class Stack
{
Public:
	//Name:		Stack constructor
	//Purpose:	create Stack objects
	//Parameters:	none
	//Returns:	none
	Stack();

	//Name:		Stack destructor
	//Purpose:	delete each item in stack and return memory to heap
	//Parameters:	none
	//Returns:	none
	~Stack();

	//Name:		push
	//Purpose:	add an item to the fron the the stack
	//Parameters:	one pointer to a node object
	//Returns:	none
	void push(Node*);

	//Name:		pop
	//Purpose:	remove and return one item from the front of the stack
	//Parameters:	none
	//Returns:	one pointer to a node object
	Node* serve();

Private:
	Node* top;
};

