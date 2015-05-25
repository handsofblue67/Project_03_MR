// Author:			Michael Robison
// Assignment:		2
// File:			List.cpp
// Instructor:		
// Class:			CS 2420
// Date Written:	5/18/2015
// Description:		function definitions for Node struct, single, doublelinked-list class

//I declare that the following source code was written only by me.
//I understand that copying any source code, in whole or in part, constitutes cheating,
//and that I will receive a zero on this project if I am found in violation of this policy.
#include "SList.h"

Node::Node()
{
	next = nullptr;
	previous = nullptr;
}

Node::Node(Node_entry _data, Node* _next, Node* _previous)
{
	data = _data;
	next = _next;
	previous = _previous;
}

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

Node* SList::getHead()
{
	return head;
}

Node* SList::popFront()
{
	if (head == nullptr) //if list is empty, return nullptr
	{
		return nullptr;
	}

	else if (head->next == nullptr) //if only one node in the list remove it and return it
	{
		Node* p = head;
		head = nullptr; //set head to nullptr
		return p; // return the severed node pointer
	}

	else //otherwise remove the first node from the list and return it
	{
		Node* p = head;
		head = p->next; //set first to the currently second on the list
		return p; //return the severed node
	}

}

void SList::pushBack(int _data)
{
	if (head == nullptr) //if list is empty and add the item to a node and put at the head of the list.
	{
		head = new Node(_data, nullptr, nullptr);
	}

	else if (head->next == nullptr) //if only one node in list, add the item to a node and put it at the end of the list.
	{
		head->next = new Node(_data, nullptr, nullptr);
	}

	else //otherwise traverse list and add the item to a node and link to the end of the list.
	{
		Node* q = head;
		while (q->next != nullptr)
		{
			q = q->next;
		}
		q->next = new Node(_data, nullptr, nullptr);
	}
}

void SList::traverse(void f(Node*))
{
	Node* p = head;

	while (p != nullptr)
	{
		f(p);
		p = p->next;
	}
}



DList::DList()
	:SList()
{

}

DList::~DList()
{
	//while a node exists, call the pop_front function to separate it from the list, then delete it.
	while (head != nullptr)
	{
		delete popFront();
	}

}

void DList::traverse(void f(Node*))
{
	Node* p = head;

	while (p != nullptr)
	{
		f(p);
		p = p->next;
	}
}

Node* DList::popFront()
{
	if (head == nullptr) //if list is empty, return nullptr
	{
		return nullptr;
	}

	else if (head->next == nullptr) //if only one node in the list remove it and return it
	{
		Node* p = head;
		head = nullptr; //set head to nullptr
		return p; // return the severed node pointer
	}

	else //otherwise remove the first node from the list and return it
	{
		Node* p = head;
		head = p->next; //set first to the currently second on the list
		head->previous = nullptr;
		return p; //return the severed node
	}

}

void DList::push(int _data)
{
	Node* q = head;

	if (head == nullptr) //if list is empty
	{
		head = new Node(_data, nullptr, nullptr);
	}
	
	else if (head->next == nullptr) //if list has at least one node
	{
		if (_data > q->data) //if true, head will point to new data
		{
			q->next = new Node(_data, nullptr, q);
		}

		else //new data becomes head
		{
			head = new Node(_data, q, nullptr);
			q->previous = head;
		}
	}

	else //more than one node in list
	{
		while (q->next != nullptr && _data > q->data)
		{
			q = q->next;
		}
		
		if (q->next != nullptr) //if failed exclusivly because data was less than a number that is not last
		{
			if (q->previous != nullptr) //if new data isn't smaller than head
			{
				q->previous->next = new Node(_data, q, q->previous);
				q->previous = q->previous->next;
			}
			else //if q is head
			{
				head = new Node(_data, q, nullptr);
				q->previous = head;
			}
			
		}

		else //if q is the last in the list
		{
			if (_data > q->data) //if new data is to be the last on the list
			{
				q->next = new Node(_data, nullptr, q);
			}

			else
			{
				q->previous->next = new Node(_data, q, q->previous);
				q->previous = q->previous->next;
			}

		}

	}

}
