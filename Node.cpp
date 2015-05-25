
#include "Node.hpp"

Node::Node()
{
	data = -1;
	ahead = nullptr;
	behind = nullptr;
}

Node::Node(Node_entry _data, Node* _ahead, Node* _behind)
{
	data = _data;
	behind = _behind;
	ahead = _ahead;
}
