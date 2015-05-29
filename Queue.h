// Author:			Michael Robison
// Assignment:		3
// File:			Queue.h
// Instructor:		
// Class:			CS 2420
// Date Written:	5/28/2015
// Description:		Queue class and function definitions

//I declare that the following source code was written only by me.
//I understand that copying any source code, in whole or in part, constitutes cheating,
//and that I will receive a zero on this project if I am found in violation of this policy.

#ifndef QUEUE_H
#define QUEUE_H
#include "Node.h"

template<typename T>
class Queue
{
public:
	//Name:			Queue constructor
	//Purpose:		create queue objects
	//Parameters:	none
	//Returns:		none
	Queue();

	//Name:			Queue destructor
	//Purpose:		delete nodes in the queue and return the memory back to the heap
	//Parameters:	none
	//Returns:		none
	~Queue();

	//Name:		getFront
	//Purpose:	return pointer to the node at the front of the queue
	//Parameters:	none
	//Returns:	one node pointer
	Node<T>* getFront();

	//Name:		serve
	//Purpose:	create a node and add to the back of the queue object
	//Parameters:	one piece of data (templatized)
	//Returns:	one string for error code
	string append(const T);

	//Name:		serve
	//Purpose:	remove one item from the front of the queue
	//Parameters:	none
	//Returns:	one string for error code
	string serve();

	//Name:		print
	//Purpose:	return a string that contains the current data stored on the stack
	//Parameters:	none
	//Returns:	one (long) string
	string print();

private:
	Node<T>* front;
	Node<T>* rear;
};

template<typename T>
Queue<T>::Queue() : front(nullptr), rear(nullptr)
{

}

template<typename T>
Queue<T>::~Queue()
{
	while (rear != nullptr)
	{
		serve();
	}
}

template<typename T>
Node<T>* Queue<T>::getFront()
{
	return front;
}

template<typename T>
string Queue<T>::append(const T _data)
{
	string outcome = "success";
	if (front == nullptr)
	{
		front = rear = new Node<T>(_data, nullptr, nullptr);
	}

	else
	{
		rear->behind = new Node<T>(_data, rear, nullptr);
		rear = rear->behind;
	}
	return outcome;
}

template<typename T>
string Queue<T>::serve()
{
	string outcome = "success";
	Node<T>* p = front;
	if (front == nullptr)
	{
		outcome = "underflow";

	}

	else if (front->behind == nullptr)
	{
		delete p;
		front = rear = nullptr;
	
	}

	else
	{
		front = front->behind;
		front->ahead = nullptr;
		delete p;

	}
	
	return outcome;
}

template<typename T>
string Queue<T>::print()
{
	ostringstream oss;
	Node<T>* p = front;

	while (p != nullptr)
	{
		oss << p->data << endl;
		p = p->behind;
	}

	return oss.str();

}

#endif
