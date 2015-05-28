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

	//Name:		push
	//Purpose:	add an item to the front the the stack
	//Parameters:	one int
	//Returns:	none
	ErrorCode push(const T);

	//Name:		pop
	//Purpose:	remove and return one item from the front of the stack
	//Parameters:	none
	//Returns:	one pointer to a node object
	ErrorCode pop();

	//Name:		print
	//Purpose:	return a string that contains the current data stored on the stack
	//Parameters:	none
	//Returns:	one (long) string
	string print();
private:
	Node<T>* top;
}; 


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
ErrorCode Stack<T>::push(const T _data)
{
	ErrorCode outcome = success;
	if (top == nullptr)
	{
		top = new Node<T>(_data, nullptr, nullptr);
	}

	else
	{
		top = new Node<T>(_data, top, nullptr);
		top = top->ahead;

	}
	return outcome;
}

template<typename T>
ErrorCode Stack<T>::pop()
{
	if (top == nullptr)
	{
		ErrorCode outcome = underflow;
		return outcome;
	}

	ErrorCode outcome = success;
	if (top->ahead == nullptr)
	{
		delete top;
		top = nullptr;
		return outcome;
	}

	Node<T>* p = top;
	top = p->ahead;
	top->behind = nullptr;
	delete p;
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