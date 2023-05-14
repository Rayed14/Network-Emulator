#include<iostream>
#include<string>
#include<fstream>
using namespace std;


#include "Header.h"


class Query
{
	string command;
	string filename;

public:

	Query()
	{
		command = "";
		filename = "";
	}

	Query(string cm, string fn)
	{
		command = cm;
		filename = fn;
	}

	~Query() {}


};




void sendMessage(string fileName, Message msgObj[100], PriorityQueue &PQobj) //Will read the sent file and process all the messages in the file messages
{
	
	
	int objCount = 0;
	ifstream in(fileName);
	string text = "";
	

	while (getline(in, text)) //While loop runs till end of line of the file
	{
		int count = 0;
		int colCount = 0;
		string tempStr = "";
		while (text[count] != '\0')
		{
			if (text[count] != ':') //not having a colon
				tempStr += text[count];

			if (text[count] == ':') //If colon then increment colCount and count(for space after colon)
			{
				if (colCount == 0 && tempStr != "") //For ID
				{
					msgObj[objCount].setMsgID(stoi(tempStr));
					tempStr = "";
				}

				if (colCount == 1 && tempStr != "") //For priority
				{
					msgObj[objCount].setPriority(stoi(tempStr));
					tempStr = "";
				}

				if (colCount == 2 && tempStr != "") //For src
				{
					msgObj[objCount].setSrc(tempStr);
					tempStr = "";
				}

				if (colCount == 3 && tempStr != "") //For dest
				{
					msgObj[objCount].setDest(tempStr);
					tempStr = "";
				}

				colCount++;
				count++;
			}

			if (text[count + 1] == '\0' && tempStr != "") //For PayLoad
			{
				msgObj[objCount].setPayLoad(tempStr);
				tempStr = "";
			}


			count++;
		}

		PQobj.insert(msgObj[objCount]);

		objCount++;
	}
	in.close(); //closes the file
	
}



void changeRT(string router, string changeHow, string fileName)
{
	cout << router << " " << changeHow << " " << fileName << endl;
}

void printPath(Message msgObj[100])
{
	ofstream file;
	file.open("file.txt", ios::app);
	if (!file)
	{
		cout << "Error in opening file" << endl;
	}


	cout << "---------------PATHS OF EACH MESSAGE--------------" << endl;
	for (int i = 0; i < 5; i++)
	{
		file << msgObj[i].getPayLoad() << ": " << msgObj[i].getTrace() << endl;
		cout << msgObj[i].getPayLoad() << ": " << msgObj[i].getTrace() << endl;
	}

	file.close();
}


int returnDKnum(string src)
{
	if (src == "M1")
		return 0;
	else if (src == "M2")
		return 1;
	else if (src == "M3")
		return 2;
	else if (src == "M4")
		return 3;
	else if (src == "M5")
		return 4;
	else if (src == "M6")
		return 5;
	else if (src == "M7")
		return 6;
	else if (src == "M8")
		return 7;
	else if (src == "M9")
		return 8;
	else if (src == "M10")
		return 9;
	else if (src == "M11")
		return 10;
	else if (src == "M12")
		return 11;
	else if (src == "M13")
		return 12;
	else if (src == "M14")
		return 13;
	else if (src == "M15")
		return 14;
	else if (src == "R1")
		return 15;
	else if (src == "R2")
		return 16;
	else if (src == "R3")
		return 17;
	else if (src == "R4")
		return 18;
	else if (src == "R5")
		return 19;
}


int main()
{
	int ch;
	cout << "**********WELCOME**********\n\n\n" << endl;
	cout << "Enter 1 for LinkedList \nEnter 2 for SplayTree \nYour choice: ";
	cin >> ch;
	while (ch != 1 && ch != 2)
	{
		cout << "Please enter valid Input: ";
		cin >> ch;
	}
	system("cls");

	if (ch == 1)
	{
		cin.ignore();
		Message* msgObj = new Message[100]; // array of message objects which contains all the message sent from user
		string userInput;

		PriorityQueue PQobj;
		int arr2D[20][20];
		graph gobj(20);


		bool flag1 = true;
		while (flag1 == true) //While loop for multiple query entry
		{
			cout << "Please enter your Query: "; //Promting the user to enter query
			getline(cin, userInput);

			string checkCommand = "";
			int count1 = 0;

			while (userInput[count1] != '\0') //Check what command is in input
			{
				if (userInput[count1] == ' ')
					break;
				else
					checkCommand += userInput[count1];
				count1++;
			}

			if (checkCommand == "send") //if command is send msg
			{
				flag1 = false;
				string checkFile = "";
				int count2 = 0;
				int spaceCount = 0;

				while (userInput[count2] != '\0') //Check the file to send which has messages
				{
					if (spaceCount == 2)
						checkFile += userInput[count2];

					if (userInput[count2] == ' ')
						spaceCount++;

					count2++;
				}

				sendMessage(checkFile, msgObj, PQobj); //Calling function send Message
			}
			else if (checkCommand == "change")
			{
				flag1 = false;
				string router = "";
				string changeHow = "";
				string checkFile = "";
				int count2 = 0;
				int spaceCount = 0;

				while (userInput[count2] != '\0')
				{
					if (spaceCount == 4)
						checkFile += userInput[count2]; //Check file to send to change RT function

					if (spaceCount == 3)
						changeHow += userInput[count2]; //Check how to change to send to change RT function

					if (spaceCount == 2)
						router += userInput[count2]; //Check the router to send to change RT function

					if (userInput[count2] == ' ')
						spaceCount++;

					count2++;
				}
				changeRT(router, changeHow, checkFile);

			}
			else if (checkCommand == "print")
			{
				flag1 = false;
				cout << "print" << endl;
			}
			else //Neither of the 3 command
			{
				cout << "Wrong input command, try again!\n" << endl;
				userInput = "";
			}
		}

		cout << "---------------MAKING GRAPH----------------" << endl;
		readCSVfile("network.csv", gobj);
		cout << "\n---------------MAKING 2D ARRAY GRAPH----------------" << endl;
		readCSVfileAs2D("network.csv", arr2D);


		cout << "\n---------------NOW SENDING MESSAGES----------------" << endl;
		//For all message
		for (int i = 0; i < 5; i++)
		{
			Router routobj1;
			Message msgSendObj = PQobj.extractMax();
			cout << "Sending message: " << msgSendObj.getPayLoad() << endl;
			string tempSrc = msgSendObj.getSrc();
			int c = 0;
			int dkNum1;
			int dkNum2;

			while (c < 20)
			{
				if (gobj.Head[c].head->name == tempSrc)
					routobj1.rname = gobj.Head[c].head->next->name;
				c++;
			}

			cout << "Source: " << msgSendObj.getSrc() << endl;
			cout << "Destination: " << msgSendObj.getDest() << endl;

			routobj1.incomingQ.insert(msgSendObj);

			dkNum1 = returnDKnum(tempSrc);
			dkNum2 = returnDKnum(msgSendObj.getDest());

			dijkstra(arr2D, dkNum1, dkNum2);

			string bestRouter = "";
			int tempCount = 0;
			while (bestrt[tempCount] != '\0')
			{
				if (tempCount == 4)
					break;
				if (tempCount >= 2)
					bestRouter += bestrt[tempCount];

				tempCount++;
			}
			msgObj[i].trace += bestRouter;
			bestrt = "";

			cout << "Message going from " << routobj1.rname << " to " << bestRouter << endl;
			routobj1.outgoingQ.enqueue(msgSendObj);

			while (bestRouter[0] != 'M')
			{
				cout << bestRouter << endl;
				Router nextrouter;

				int b = 0;

				while (b < 20)
				{
					if (gobj.Head[b].head->name == bestRouter)
						nextrouter.rname = gobj.Head[b].head->next->name;
					b++;
				}

				nextrouter.incomingQ.insert(msgSendObj);

				dkNum1 = returnDKnum(bestRouter);
				dkNum2 = returnDKnum(msgSendObj.getDest());

				dijkstra(arr2D, dkNum1, dkNum2);
				if (bestrt[0] == 'M')
					break;
				bestRouter = "";
				tempCount = 0;
				while (bestrt[tempCount] != '\0')
				{
					if (tempCount == 4)
						break;
					if (tempCount >= 2)
						bestRouter += bestrt[tempCount];

					tempCount++;
				}
				msgObj[i].trace += " " + bestRouter;
				bestrt = "";


				cout << "Message going from " << nextrouter.rname << " to " << bestRouter << endl;
				nextrouter.outgoingQ.enqueue(msgSendObj);
			}
			cout << "------------NOW NEXT MESSEGE SEND----------------" << endl;
		}


		printPath(msgObj);
	}
	else
	{
	     SplayTree<int> splayobj;
		 splayobj.insert(10);
		 splayobj.insert(15);
		 splayobj.insert(13);
		 splayobj.insert(16);
		 splayobj.insert(11);
		 splayobj.insert(17);
		 splayobj.insert(18);


		 cout << "Root: " << splayobj.getrootvalue() << endl;
		 splayobj.displayInOrder();


    }
	






	


	return 0;
}