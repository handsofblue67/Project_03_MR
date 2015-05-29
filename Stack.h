// Author:		Michael Robison
// Assignment:		3
// File:		Stack.h
// Instructor:		
// Class:		CS 2420
// Date Written:	5/29/2015
// Description:		Stack class and function definitions

//I declare that the following source code was written only by me.
//I understand that copying any source code, in whole or in part, constitutes cheating,
//and that I will receive a zero on this project if I am found in violation of this policy.

#ifndef STACK_H
#define STACK_H
#include "Node.h"

//stack class definition
template<typename T>
class Stack
{
public:
	//Name:			Stack constructor
	//Purpose:		create Stack objects
	//Parameters:	none
	//Returns:		none
	Stack();

	//Name:			Stack destructor
	//Purpose:		delete each item in stack and return memory to heap
	//Parameters:	none
	//Returns:		none
	~Stack();
	
	//Name:			getTop()
	//Purpose:		return node at top of stack
	//Parameters:	None
	//Returns:		one node pointer
	Node<T>* getTop();

	//Name:			push
	//Purpose:		add an item to the front the the stack
	//Parameters:	one item
	//Returns:		none
	string push(const T);

	//Name:			pop
	//Purpose:		remove and return one item from the front of the stack
	//Parameters:	none
	//Returns:		one string representing return code of operation
	string pop();

	//Name:			print
	//Purpose:		return a string that contains the current data stored on the stack
	//Parameters:	none
	//Returns:		one (long, and formatted) string
	string print();
private:
	Node<T>* top;
}; 

//stack class function definitions
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
Node<T>* Stack<T>::getTop()
{
	return top;
}

template<typename T>
string Stack<T>::push(const T _data)
{
	string outcome = "success";
	if (top == nullptr) //if stack is empty, parameter into a new node and place at top
	{
		top = new Node<T>(_data, nullptr, nullptr);
	}

	else //otherwise place at top point it to the item below
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
	if (top == nullptr) //if stack is empty, underflow
	{
		outcome = "underflow";

	}

	else if (top->ahead == nullptr) //if only one item is stack
	{
		delete p;
		top = nullptr;

	}

	else
	{
		top = top->ahead; //otherwise, delete top, and set the one below it top
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
