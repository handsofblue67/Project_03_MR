#include<iostream>
#include<fstream>
#include<string>
#include "Node.hpp"
#include "Queue.hpp"
#include "Stack.hpp"

using namespace std;

int readValue(in)
{
	int n;
	cin >> n;
	return n;
}

int main()
{
	string answer = "";

	do
	{
		Queue* queue = new Queue();
		Stack* stack = new Stack();
		string command = "";
		ifstream in;

		cout << "Enter the name of the file" << endl;
		cin >> in;

		in.open;
		if (in.fail)
		{
			cout << "there was an error while opening the file" << endl;
			answer = y;
		}

		else
		{
			int intValue;
			string command;
			while (cin >> intValue) || cin >> command)
			{
				if (!cin >> intValue)
				{
					if ( command == "push")
					{
						intValue = readValue();
						stack.push(intValue);
						cout << "push\t\tstack\t\tsuccess" << endl;
					}

					else
					{
						num = stack.pop()->data;
						cout << "pop\t\tstack\t\tsuccess" << endl;
					}

					if (command == "append")
					{
						intValue = readValue();
						queue.append(intValue);
						cout << "append\t\tqueue\t\tsuccess" << endl;
					}
	
					else
					{
						num = queue.serve->data;
						queue.serve();
						cout << "serve\t\tqueue\t\tsuccess" << endl;
					}
				}	
			}


		}
		in.close();
		cout << "Enter 'y' if you want to enter another file" << endl;
	} while (answer == "y");
	return 0;
}
