// Author:			Michael Robison
// Assignment:		3
// File:		main.cpp
// Instructor:		
// Class:			CS 2420
// Date Written:	5/29/2015
// Description:		driver for node containing queue and stack	

//I declare that the following source code was written only by me.
//I understand that copying any source code, in whole or in part, constitutes cheating,
//and that I will receive a zero on this project if I am found in violation of this policy.

#include<iostream>
#include<fstream>
#include<string>
#include "Node.h"
#include "Queue.h"
#include "Stack.h"
using namespace std;

int main()
{
	string answer = ""; //determines if loop will be repeated
	string command; //the "opcode" to be performed on the data structure of which it is apart
	ifstream in; //the file stream of opcodes
	int intValue; //the data to be stored in the structure

	do
	{
		
		string file = ""; //file name
		cout << "Enter the name of the file" << endl;
		cin >> file;
		

		in.open(file);
		if (in.fail()) //if fail, ask for the file name again
		{
			cout << "there was an error while opening the file" << endl;
			answer = "y";
		}

		else 
		{
			Queue<int> queue; 
			Stack<int> stack;
			cout << "\n\nOperation\tStructure\tContents\tReturn Code\n\n";
			cout << "_________________________________________________________\n";
			while (in >> command)
			{
				
					if (command == "push") //if opcode push
					{
						in >> intValue;
						cout << "|push\t|\tstack\t|\t" << intValue << "\t|\t" << stack.push(intValue) << "\t|" << endl;
					}

					else if (command == "pop") //if opcode pop
					{
						if (stack.getTop() == nullptr) //check if empty, if so print error and blank data
						{
							cout << "|pop\t|\tstack\t|\t---\t|\t" << stack.pop() << "\t|"<< endl;
						}
						
						else //otherwise, get data stored at the top of the stack, then pop
						{
							cout << "|pop\t|\tstack\t|\t" << stack.getTop()->data;
							cout << "\t|\t" << stack.pop() << "\t|" << endl;
						}
					}

					else if (command == "append") //if opcode append
					{
						in >> intValue;
						cout << "|append\t|\tqueue\t|\t" << intValue << "\t|\t" << queue.append(intValue) << "\t|" << endl; 
					}

					else if (command == "serve") //if opcode serve
					{
						if (queue.getFront() == nullptr) //if queue is empty, print blank data and underflow
						{
							cout << "|serve\t|\tqueue\t|\t---\t|\t" << queue.serve() << "\t|" << endl;
						}

						else
						{
							cout << "|serve\t|\tqueue\t|\t" << queue.getFront()->data; //otherwise, get data from front of queue and then serve
							cout << "\t|\t" << queue.serve() << "\t|" << endl;
						}
					}

				}
			cout << "_________________________________________________________\n";

			in.close();
			cout << "\nQueue Contents\n" << queue.print(); //print remaining content of queue
			cout << "\n\nStack Contents\n" << stack.print() << endl; //print remaining content of stack
			cout << "Enter 'y' if you want to enter another file" << endl;
			cin >> answer;
		}	
	} while (answer == "y");
	system("PAUSE");
	return 0;
}
