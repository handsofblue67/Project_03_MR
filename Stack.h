// Author:		Michael Robison
// Assignment:		3
// File:		Stack.h
// Instructor:		
// Class:		CS 2420
// Date Written:	5/28/2015
// Description:		Stack class and function definitions

//I declare that the following source code was written only by me.
//I understand that copying any source code, in whole or in part, constitutes cheating,
//and that I will receive a zero on this project if I am found in violation of this policy.

#ifndef STACK_H
#define STACK_H
#include "Node.h"
template<typename T>
class Stack
{
public:
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
	
	//Name:			getTop()
	//Purpose:		return node at top of stack
	//Parameters:	None
	//Returns:		one node pointer
	Node<T>* getTop();

	//Name:		push
	//Purpose:	add an item to the front the the stack
	//Parameters:	one int
	//Returns:	none
	string push(const T);

	//Name:		pop
	//Purpose:	remove and return one item from the front of the stack
	//Parameters:	none
	//Returns:	one pointer to a node object
	string pop();

	//Name:		print
	//Purpose:	return a string that contains the current data stored on the stack
	//Parameters:	none
	//Returns:	one (long) string
	string print();
private:
	Node<T>* top;
}; 

template<typename T>
Node<T>* Stack<T>::getTop()
{
	return top;
}

template<typename T>
Stack<T>::Stack() : top(nullptr)
{

}

template<typename T>
Stack<T>::~Stack()
{
	while (top != nullptr)
	{
		pop();
	}
}

template<typename T>
string Stack<T>::push(const T _data)
{
	string outcome = "success";
	if (top == nullptr)
	{
		top = new Node<T>(_data, nullptr, nullptr);
	}

	else
	{
		Node<T>* p = new Node<T>(_data, top, nullptr);
		top = p;

	}
	return outcome;
}

template<typename T>
string Stack<T>::pop()
{
	string outcome = "success";
	Node<T>* p = top;
	if (top == nullptr)
	{
		outcome = "underflow";

	}

	else if (top->ahead == nullptr)
	{
		delete p;
		top = nullptr;

	}

	else
	{
		top = top->ahead;
		delete p;

	}
	
	return outcome;
}

template<typename T>
string Stack<T>::print()
{
	ostringstream oss;
	Node<T>* p = top;

	while (p != nullptr)
	{
		oss << p->data << endl;
		p = p->ahead;
	}

	return oss.str();

}

#endif
