
#include<iostream>
#include<fstream>
#include<iostream>

using namespace std;

struct Node
{
	Node()
	{

	}

	Node(int _data, Node* _next, Node* _previous)
	{
		data = _data;
		next = _next;
		previous = _previous;
	}
	~Node()
	{

	}
}
