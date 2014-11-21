#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include "Dog.h"

using namespace std;

int addToDog(string str);

int main() 
{
	string line;
	string formatted;
	vector<string> unparsed;
	ifstream myfile;
	myfile.open("dogs.txt");
	cout << "Attempting open" << endl;

	cout << myfile.is_open() << endl;
	if (myfile.is_open())
	{
		cout << "File has been opened" << endl;
		cout << "Is file good?" <<myfile.good() << endl;
		while (myfile.good())
		{
			cout << "Attempting to read from file" << endl;
			getline(myfile, line);
			cout << line << '\n';
			unparsed.push_back(line);
			addToDog(line);
		}
		myfile.close();
		cout << "File has been closed" << endl;
	}

	else cout << "Unable to open file";

	cout << unparsed.size() << " lines have been read in." << endl;
	return 0;
}

/*
addToDog(string str)
Precondition: A string containing the data to be stored within the Dog class
Postcondition: Creates a new object of class Dog and then return it. Does not Happen!

Notes: temporary not ment for linked list
*/

int addToDog(string str)
{
	int stringSize;
	int segmentNo = 0;
	string temp = "";
	string segment[6];
	//Dog aDog; //not working for some reason claims no default constructor
	map<char, int> ignore; //0 = ignore character, 1 = end of segment, 2 stop reading
	ignore['<'] = 0;  
	ignore['>'] = 2;
	ignore['/'] = 2;
	ignore[','] = 1;
	for (int i = 0; i < str.length(); i++)
	{
		char ch = str.at(i);
		//cout << "ignore count is" << ignore.count(ch) << endl;
		if (ignore.count(ch) < 1)
		{
			temp += ch;
			//cout << "adding " << ch << "	";
		} //adds char to temporary string for that particular segment
		else
		{
			int instruction = ignore.find(ch)->second;
			switch (instruction)
			{
				case 0:	//ignores that particular character.
					break; 
				case 1:	//moves onto next segment.
					cout << temp << endl;
					segment[segmentNo] = temp;
					segmentNo++;
					cout << "Segment has been successfully added." << endl;
					temp = ""; //empties temp
					//aDog.addData(temp);
					break;
				case 2:
					return 0;
			}
		}
	}
	return 0;
}
