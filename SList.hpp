// Author:			Michael Robison
// Assignment:		2
// File:			List.h
// Instructor:		
// Class:			CS 2420
// Date Written:	5/18/2015
// Description:		Node struct, single and double linked class definition

//I declare that the following source code was written only by me.
//I understand that copying any source code, in whole or in part, constitutes cheating,
//and that I will receive a zero on this project if I am found in violation of this policy.
typedef int Node_entry;

struct Node
{
	//data members 
	Node_entry data;
	Node* next;
	Node* previous; //(only used by double linked list.

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
	Node(Node_entry, Node*, Node*);
};

class SList
{
public:

	// Function Name:	SList constructor
	// Purpose:			constructs default single list objects
	// Parameters:		none
	// Returns:			none
	// Pre-conditions:	none
	// Post-conditions:	none
	SList();

	// Function Name:	SList destructor
	// Purpose:			destructs SList objects
	// Parameters:		none
	// Returns:			none
	// Pre-conditions:	none
	// Post-conditions:	none
	~SList();

	// Function Name:	getHead
	// Purpose:			getter for first node in list object
	// Parameters:		none
	// Returns:			one SNode pointer
	// Pre-conditions:	none
	// Post-conditions:	none
	Node* getHead();

	// Function Name:	push_back
	// Purpose:			push a node onto the end of the list
	// Parameters:		one SNode pointer
	// Returns:			none
	// Pre-conditions:	none
	// Post-conditions:	none
	void pushBack(int);

	// Function Name:	traverse
	// Purpose:			traverse through each node in list
	// Parameters:		one void function pointer that takes and integer as a parameter
	// Returns:			none
	// Pre-conditions:	none
	// Post-conditions:	none
	void traverse(void(*)(Node*));

	// Function Name:	popFront
	// Purpose:			remove the head of the list
	// Parameters:		none
	// Returns:			one SNode pointer
	// Pre-conditions:	none
	// Post-conditions:	none
	Node* popFront();

private:
	Node* head;
};



class DList : public SList
{
public:

	// Function Name:	DList constructor
	// Purpose:			constructs DList objects
	// Parameters:		none
	// Returns:			none
	// Pre-conditions:	none
	// Post-conditions:	none
	DList();

	// Function Name:	DList destructor
	// Purpose:			destructs DList objects
	// Parameters:		none
	// Returns:			none
	// Pre-conditions:	none
	// Post-conditions:	none
	~DList();

	// Function Name:	traverse
	// Purpose:			traverse through each node in list
	// Parameters:		one void function pointer that takes and integer as a parameter
	// Returns:			none
	// Pre-conditions:	none
	// Post-conditions:	none
	void traverse(void(*)(Node*));

	// Function Name:	push
	// Purpose:			push a node onto the list, in accending order
	// Parameters:		one DNode pointer
	// Returns:			none
	// Pre-conditions:	none
	// Post-conditions:	none
	void push(int);

	// Function Name:	popFront
	// Purpose:			remove the head of the list
	// Parameters:		none
	// Returns:			one DNode pointer
	// Pre-conditions:	none
	// Post-conditions:	none
	Node* popFront();

private:
	Node* head;
};