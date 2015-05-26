#include "Stack.hpp"

Stack::Stack() : top(nullptr)
{

}

Stack::~Stack()
{
	while (top != nullptr)
	{
		delete pop();
	}
}

Error_code Stack::push(int _data)
{
	Node* p = new Node(_data, top, nullptr);
	top->behind = p;
	top = p;
}

Node* Stack::pop()
{
	Node* p = top;
	p->ahead->behind = nullptr;
	top = p->ahead;
	return p;
}
