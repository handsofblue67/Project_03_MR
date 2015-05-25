#include "Node.hpp"

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

	//Name:		serve
	//Purpose:	create a node and add to the back of the queue object
	//Parameters:	one int
	//Returns:	none
	void append(int);

	//Name:		serve
	//Purpose:	remove and return one item from the front of the Queue
	//Parameters:	none
	//Returns:	one pointer to a node object
	Node* serve();

private:
	Node* front;
	Node* rear;
};
