//typedef int node_entry;

class Node
{
public:
	Node();
	Node(node_entry, Node*, Node*);
	int getData();
private:
	int data;
	Node* behind;
	Node* ahead;
};

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
