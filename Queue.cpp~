#include "Queue.hpp"

Queue::Queue() : front(nullptr), rear(nullptr)
{

}

Queue::~Queue()
{
	while (rear != nullptr)
	{
		delete serve();
	}
}

void Queue::append(int _data)
{
	Node* p = new Node(_data, rear, nullptr);
	p->ahead = rear;
	rear = p;
}

Node* Queue::serve()
{
	Node* p = front;
	front = front->behind;
	front->ahead = nullptr;
	return p;
}
