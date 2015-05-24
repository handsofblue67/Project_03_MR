#include "Stack.hpp"
#include "Node.hpp"

Stack() : top(nullptr)
{

}

~Stack()
{
	while (top != nullptr)
	{
		delete top();
	}
}

void push(Node* p)
{
	top->behind = p;
	p->ahead = top;
	top = p;
	p->behind = nullptr;
}

Node* serve()
{
	Node* p = top;
	p->ahead->behind = nullptr;
	top = p->ahead;
	return p;
}
