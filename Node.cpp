
#include "Node.hpp"

Node::Node()
{
	behind = nullptr;
	ahead = nullptr;
}

Node::Node(Node_entry _data, Node* _behind, Node* _ahead)
{
	data = _data;
	behind = _behind;
	ahead = _ahead;
}
<<<<<<< HEAD

SList::SList()
{
	head = nullptr;
}

SList::~SList()
{
	//while a node exists, call the pop_front function to separate it from the list, then delete it.
	while (head != nullptr)
	{
		delete popFront();
	}

}
}
=======
>>>>>>> origin/master
