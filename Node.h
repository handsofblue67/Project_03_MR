// Author:			Michael Robison
// Assignment:		3
// File:			Node.h
// Instructor:		
// Class:			CS 2420
// Date Written:	5/28/2015
// Description:		Node struct and function definitions

//I declare that the following source code was written only by me.
//I understand that copying any source code, in whole or in part, constitutes cheating,
//and that I will receive a zero on this project if I am found in violation of this policy.

#ifndef NODE_H
#define NODE_H
#include<string>
#include<sstream>
using namespace std;

//enum ErrorCode{success, underflow};

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

#endif
