#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class Queue
{
Public:
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

	//Name:		serve
	//Purpose:	remove and return one item from the front of the Queue
	//Parameters:	none
	//Returns:	one pointer to a node object
	void append(Node*);

	//Name:		serve
	//Purpose:	remove and return one item from the front of the Queue
	//Parameters:	none
	//Returns:	one pointer to a node object
	Node* serve();

Private:
	Node* front;
	Node* rear;
};

