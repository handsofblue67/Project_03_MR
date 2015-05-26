<<<<<<< HEAD
typedef int Node_entry;
=======
//typedef int node_entry;
>>>>>>> origin/master

class Node
{
<<<<<<< HEAD
	//data members 
	Node_entry data;
	Node* behind;
	Node* ahead; 

	// Function Name:	SNode default constructor
	// Purpose:			constructs default double-list node objects
	// Parameters:		none
	// Returns:			none
	// Pre-conditions:	none
	// Post-conditions:	none
	Node();

	// Function Name:	SNode parameterized constructor
	// Purpose:			constructs parameterized double-list node objects
	// Parameters:		one int
	// Returns:			none
	// Pre-conditions:	none
	// Post-conditions:	none
	Node(Node_entry, Node*, Node*);
=======
public:
	Node();
	Node(node_entry, Node*, Node*);
	int getData();
private:
	int data;
	Node* behind;
	Node* ahead;
>>>>>>> origin/master
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
