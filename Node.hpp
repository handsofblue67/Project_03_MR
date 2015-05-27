// Author:			Michael Robison
// Assignment:		2
// File:			Node.hpp
// Instructor:		
// Class:			CS 2420
// Date Written:	5/18/2015
// Description:		Node struct, single and double linked class definition

//I declare that the following source code was written only by me.
//I understand that copying any source code, in whole or in part, constitutes cheating,
//and that I will receive a zero on this project if I am found in violation of this policy.
//typedef int Node_entry;
#include<string>
#include<sstream>
using namespace std;
template<typename T>

enum ErrorCode{success, underflow};

template<typename T>
struct Node
{
	//data members 
	T data;
	Node* behind;
	Node* ahead; //(only used by double linked list.

	// Function Name:	SNode default constructor
	// Purpose:			constructs default double-list node objects
	// Parameters:		none
	// Returns:			none
	// Pre-conditions:	none
	// Post-conditions:	none
	Node();

	// Function Name:	SNode parameterized constructor
	// Purpose:			constructs parameterized double-list node objects
	// Parameters:		one int
	// Returns:			none
	// Pre-conditions:	none
	// Post-conditions:	none
	Node(T, Node*, Node*);
};


template<typename T>
Node<T>::Node()
{
	behind = nullptr;
	ahead = nullptr;
}

template<typename T>
Node<T>::Node(T _data, Node* _ahead, Node* _behind)
{
	data = _data;
	behind = _behind;
	ahead = _ahead;
}

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
class Queue
{
public:
	//Name:		Queue constructor
	//Purpose:	create queue objects
	//Parameters:	none
	//Returns:	none
	Queue();

	//Name:		Queue destructor
	//Purpose:	delete nodes in the queue and return the memory back to the heap
	//Parameters:	none
	//Returns:	none
	~Queue();

	//Name:		getFront
	//Purpose:	return pointer to the node at the front of the queue
	//Parameters:	none
	//Returns:	one node pointer
	Node<T>* getFront();

	//Name:		serve
	//Purpose:	create a node and add to the back of the queue object
	//Parameters:	one int
	//Returns:	none
	ErrorCode append(const T);

	//Name:		serve
	//Purpose:	remove and return one item from the front of the Queue
	//Parameters:	none
	//Returns:	one pointer to a node object
	ErrorCode serve();
	
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
string Queue<T>::print()
{
	ostringstream oss;
	Node<T>* p = rear;
	
	while (p != nullptr)
	{
		oss << p->data << endl;
		p = p->ahead;
	}
	
	return oss.str();
	
}

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
ErrorCode Queue<T>::append(const T _data)
{
	ErrorCode outcome = success;
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
ErrorCode Queue<T>::serve()
{
	if (front == nullptr)
	{
		ErrorCode outcome = underflow;
		return outcome;
	}

	ErrorCode outcome = success;
	Node<T>* p = front;
	if (front->behind == nullptr)
	{
		delete p;
		front = rear = nullptr;
		return outcome;
	}

	front = front->behind;
	front->ahead = nullptr;
	delete p;
	return outcome;
}

template<typename T>
string Queue<T>::print()
{
	ostringstream oss;
	Node<T>* p = rear;
	
	while (p != nullptr)
	{
		oss << p->data << endl;
		p = p->ahead;
	}
	
	return oss.str();
	
}
