#include<iostream>
#include<fstream>
#include<string>
#include "Node.hpp"

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
	
			while (!in.eof())
			{
				
					Queue<int> queue;
					Stack<int> stack;
					in >> command;
					if (command == "push")
					{
						in >> intValue;
						cout << "push\t\tstack\t\t" << intValue << "\t\t" << stack.push(intValue) << endl;
					}

					else if (command == "pop")
					{
						cout << "pop\t\tstack\t\t---\t\t" << stack.pop() << endl;
					}

					else if (command == "append")
					{
						in >> intValue;
						
						cout << "append\t\tqueue\t\t" << intValue << "\t\t" << queue.append(intValue) << endl;
					}

					else if (command == "serve")
					{
						if (queue.getFront() == nullptr)
						{
							cout << "serve\t\tqueue\t\t---\t\t" << queue.serve() << endl;
						}

						else
						{
							cout << "serve\t\tqueue\t\t" << queue.getFront()->data << "\t\t" << queue.serve() << endl;
						}
					}

					cout << queue.print() << stack.print();
				}
			}

			in.close();
			cout << "Enter 'y' if you want to enter another file" << endl;
			cin >> answer;
		}	
	} while (answer == "y");
	system("PAUSE");
	return 0;
}
