#include "Stack.hpp"

Stack::Stack() : top(nullptr)
{

}

Stack::~Stack()
{
	while (top != nullptr)
	{
		delete top();
	}
}

void Stack::push(int _data)
{
	Node* p = new Node(_data, top, nullptr);
	top->behind = p;
	top = p;
}

Node* Stack::serve()
{
	Node* p = top;
	p->ahead->behind = nullptr;
	top = p->ahead;
	return p;
}
