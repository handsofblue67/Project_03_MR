#include "Queue.hpp"
#include "Node.hpp"
Queue() : front(nullptr), rear(nullptr)
{

}

~Queue()
{
	while (rear != nullptr)
	{
		delete rear->serve();
	}
}

void append(Node* p)
{
	Node* q = rear;
	p->ahead = rear;
	rear = p;
}

Node* serve()
{
	Node* p = front;
	front = front->behind;
	front->ahead = nullptr;
	return p;
}
