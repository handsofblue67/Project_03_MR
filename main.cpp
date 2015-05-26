#include<iostream>
#include<fstream>
#include<string>
#include "Node.hpp"

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
			
			Queue<int> queue;
			Stack<int> stack;
			int intValue;
			string command;
			int num;
			
			while (in >> command >> intValue)
			{
				{
					if ( command == "push")
					{
						in >> intValue;
						cout << "push\t\tstack\t\t" << intValue << "t\t" << stack.push(intValue) << endl;
					}

					else if (command == "pop")
					{
						num = stack.pop();
						cout << "pop\t\tstack\t\t---\t\t" << stack.pop() << endl;
					}

					else if (command == "append")
					{
						
						in >> intValue;
						cout << "append\t\tqueue\t\t" << intValue << "\t\t" << queue.append(intValue) << endl;
					}
	
					else if (command == "serve")
					{
						
						cout << "serve\t\tqueue\t\t---\t\t" << queue.serve() << endl;
					}
				}	
			}
		}
		in.close();
		cout << "Enter 'y' if you want to enter another file" << endl;
	}while (answer == "y");
		system("pause");
		return 0;
}
