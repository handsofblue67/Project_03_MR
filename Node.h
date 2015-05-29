// Author:			Michael Robison
// Assignment:		3
// File:			Node.h
// Instructor:		
// Class:			CS 2420
// Date Written:	5/29/2015
// Description:		Node struct and function definitions

//I declare that the following source code was written only by me.
//I understand that copying any source code, in whole or in part, constitutes cheating,
//and that I will receive a zero on this project if I am found in violation of this policy.

#ifndef NODE_H
#define NODE_H
#include<string>
#include<sstream>
using namespace std;

//node struct definition
template<typename T>
struct Node
{
	//data members 
	T data;
	Node* behind; //specifies a node that is younger
	Node* ahead; //specifies a node that has existed in the data structure longer (stack: node ahead, is below. queue: node ahead is closer to front)

	// Function Name:	Node default constructor
	// Purpose:			constructs default node objects
	// Parameters:		none
	// Returns:			none
	// Pre-conditions:	none
	// Post-conditions:	none
	Node();

	// Function Name:	Node parameterized constructor
	// Purpose:			constructs parameterized node objects
	// Parameters:		one item to be stored, and two node pointers
	// Returns:			none
	// Pre-conditions:	none
	// Post-conditions:	none
	Node(T, Node*, Node*);
};


//node struct function definitions
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
