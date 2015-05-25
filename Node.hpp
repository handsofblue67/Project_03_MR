typedef int Node_entry;

struct Node
{
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
};
