#include<iostream>
#include<fstream>
#include<string>
#include "Node.hpp"
#include "Queue.hpp"
#include "Stack.hpp"

using namespace std;

int main()
{
	string answer = "";
	string file = "";

	do
	{
		string command = "";
		ifstream in;
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
			
			Queue* queue = new Queue();
			Stack* stack = new Stack();
			int intValue;
			string command;
			int num;
			
			while (!in.eof())
			{
				if (!in >> intValue)
				{
					if ( command == "push")
					{
						in >> intValue;
						stack->push(intValue);
						cout << "push\t\tstack\t\tsuccess" << endl;
					}

					else if (command == "pop")
					{
						num = stack->pop()->data;
						cout << "pop\t\tstack\t\tsuccess" << endl;
					}

					else if (command == "append")
					{
						
						in >> intValue;
						queue->append(intValue);
						cout << "append\t\tqueue\t\tsuccess" << endl;
					}
	
					else if (command == "serve")
					{
						
						num = queue->serve()->data;
						queue->serve();
						cout << "serve\t\tqueue\t\tsuccess" << endl;
					}
				}	
			}
		}
		in.close();
		cout << "Enter 'y' if you want to enter another file" << endl;
	}while (answer == "y");
	return 0;
}
