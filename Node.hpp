typedef int node_entry;

struct Node
{
	Node();
	Node(int, Node*, Node*);
	~Node();
	Node* behind;
	Node* ahead;
	node_entry data;
};
