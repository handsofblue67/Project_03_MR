// Author:			Michael Robison
// Assignment:		3
// File:		main.cpp
// Instructor:		
// Class:			CS 2420
// Date Written:	5/28/2015
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
	string answer = "";
	string command;
	ifstream in;
	int intValue;

	do
	{
		
		string file = "";
		cout << "Enter the name of the file" << endl;
		cin >> file;
		

		in.open(file);
		if (in.fail())
		{
			cout << "there was an error while opening the file" << endl;
			answer = "y";
		}

		else
		{
			Queue<int> queue;
			Stack<int> stack;
			cout << "____________________________________________________________\n";
			cout << "|Operation\t|Structure\t|Contents\t|Return Code|\n\n";
			while (in >> command)
			{
				
					if (command == "push")
					{
						in >> intValue;
						cout << "|push\t\t|stack\t\t|" << intValue << "\t\t|" << stack.push(intValue) << "|" << endl;
					}

					else if (command == "pop")
					{
						if (stack.getTop() == nullptr)
						{
							cout << "|pop\t\t|stack\t\t|---\t\t|" << stack.pop() << "|"<< endl;
						}
						
						else
						{
							cout << "|pop\t\t|stack\t\t|" << stack.getTop()->data;
							cout << "\t\t|" << stack.pop() << "|" << endl;
						}
					}

					else if (command == "append")
					{
						in >> intValue;
						
						cout << "|append\t\t|queue\t\t|" << intValue << "\t\t|" << queue.append(intValue) << "|" << endl;
					}

					else if (command == "serve")
					{
						if (queue.getFront() == nullptr)
						{
							cout << "|serve\t\t|queue\t\t|---\t\t|" << queue.serve() << "|" << endl;
						}

						else
						{
							cout << "|serve\t\t|queue\t\t|" << queue.getFront()->data;
							cout << "\t\t|" << queue.serve() << "|" << endl;
						}
					}

				}

			in.close();
			cout << "\nQueue Contents\n" << queue.print();
			cout << "\n\nStack Contents\n" << stack.print() << endl;
			cout << "Enter 'y' if you want to enter another file" << endl;
			cin >> answer;
		}	
	} while (answer == "y");
	system("PAUSE");
	return 0;
}
