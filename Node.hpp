
#include<iostream>
#include<fstream>
#include<iostream>

using namespace std;

struct Node
{
	Node();
	Node(int, Node*, Node*);
	~Node();
	int data;
	Node* next;
	Node* previous;
};
