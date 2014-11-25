/*
CIS22C Team 4 Project:	Dog Shelter Management Program

Purpose:	Create an easily accessible and editable catalog of dogs in a shelter
and allow the user to search through it based on dog attributes

@author		Jason Woodruff	-	Project Coordinator
Stacy Wheeler	-	Data Record
Bryson Li		-	I/O
James Juchau	-	Hashed Table
Kevin Chen		-	Binary Search Tree

@version	1.5
@since		11/25/2014
*/

#include <iostream>
#include <string>
#include <fstream>
/* 2 includes below not longer needed? */
#include <vector>//originally included by Sam Song
#include <map>//originally included by Sam Song
#include "Dog.h"
#include "HashMap.h" //was previously "LinkedHashEntry.h"
using namespace std;

bool readDogsToTreeFromFile(/*BinaryTree& dogIdTree*/);		//open the input file and read the dogs into a tree
bool readDogsToHashFromFile(HashMap& dogHash);							//open the input file and read the dogs into a hash

Dog* addToDog(string str); // will return a Dog, no longer need this in my opinion (JASON)
bool updateDogFile(/*BinaryTree& dogIdTree*/);			//probably want to change this later to take arguments

bool mainMenu();					//display the main menu
int getMainMenuChoice();
bool processMainMenuChoice(int choice/*, BinaryTree& dogIdTree*/, HashMap& dogHash);

bool addDog();						//add a dog to the tree
bool removeDog();					//delete a dog from the tree
bool displayDogInfoByIdSearch();	//displays all of a dog's info if it's found with an id search
bool displayDogsInHashSequence(HashMap& dogHash);	//display dogs in hash sequence
bool displayDogsInKeySequence();	//display dogs in key sequence
bool displayIndentedTree();			//print the indented tree
bool displayEfficiencyReport();		//print an efficiency report

//Team Choice 1
bool updateDog();	//This function will search the tree for the dog by id.
//If the dog is found, call updateDogMenu to work on it.
//Then, keep looping until the user is done updating.
//If the dog isn't found, display an error message.
bool updateDogMenu();
bool updateName();
bool updateAge();
bool updateBreed();
bool updateDesc();

/*Team Choice 2	-	Note:	This section may be tricky because we'll have to create many different trees.
I suggest we start with Team Choice 1 and do this if we have time.*/
bool SearchDogMenu();
bool searchDogByName();
bool searchDogByGender();
bool searchDogByAge();
bool searchDogByBreed();

void readToHashByFromFileTest(HashMap& dogHash);


const string FILENAME = "dog.txt";

int main()
{
	int choice = 0;

	/*BinaryTree dogIdTree;*/
	HashMap dogHash;

	while (choice != 13)
	{
		mainMenu();
		choice = getMainMenuChoice();
		processMainMenuChoice(choice /*, dogIdTree*/ , dogHash);
	}

	system("pause");
	return 0;
}

bool mainMenu()
{
	cout << "-----------------Main Menu-----------------" << endl << endl;
	cout << "1  - Create the search tree" << endl;
	cout << "2  - Create the hash table" << endl;
	cout << "3  - Add a dog" << endl;
	cout << "4  - Remove a dog" << endl;
	cout << "5  - Display dog attributes" << endl;
	cout << "6  - Update dog attributes" << endl;
	cout << "7  - Display dogs in hash sequence" << endl;
	cout << "8  - Display dogs in key sequence" << endl;
	cout << "9  - Display indented search tree" << endl;
	cout << "10 - Display efficiency report" << endl;
	cout << "11 - Clear the search tree" << endl;
	cout << "12 - Update the file" << endl;
	cout << "13 - Quit" << endl << endl;
	cout << "Enter your choice here: ";

	return true;
}

int getMainMenuChoice()
{
	string input;
	int choice;

	cin >> input;
	choice = atoi(input.c_str());
	HashMap dogHash;

	while (choice < 1 || choice > 13)
	{
		cout << "Invalid menu choice, try again: ";
		cin >> input;
		choice = atoi(input.c_str());
	}
	cout << endl;
	return choice;
}

bool processMainMenuChoice(int choice /*, BinaryTree& dogIdTree*/, HashMap& dogHash)
{
	switch (choice)
	{
		case 1:
		{
			readDogsToTreeFromFile(/*dogIdTree*/);
			break;
		}
		case 2:
		{
			readDogsToHashFromFile(dogHash);
			break;
		}
		case 3:
		{
			addDog();
			break;
		}
		case 4:
		{
			removeDog();
			break;
		}
		case 5:
		{
			displayDogInfoByIdSearch();
			break;
		}
		case 6:
		{
			updateDog();
			break;
		}
		case 7:
		{
			displayDogsInHashSequence(dogHash);
			break;
		}
		case 8:
		{
			displayDogsInKeySequence();
			break;
		}
		case 9:
		{
			displayIndentedTree();
			break;
		}
		case 10:
		{
			displayEfficiencyReport();
			break;
		}
		case 11:
		{
			/*dogIdTree.clear();*/
			break;
		}
		case 12:
		{
			updateDogFile(/*dogIdTree*/);
			break;
		}
		case 13:
		{
			cout << "Thank you, now exiting..." << endl << endl;
			break;
		}
	}
	return true;
}

/* This function will be deleted later
because it will be combined with the
readDogsToHashFromFile function
*/
bool readDogsToTreeFromFile(/*BinaryTree& dogIdTree*/)
{
	ifstream infile;
	infile.open(FILENAME.c_str());
	// will read in dogs hre
	string temp;
	cout << "File contains: " << endl;
	while (getline(infile, temp))
	{
		//Dog(int a, string strID, string strN, string strB, string strS, string strD);
		cout << temp << endl;
		Dog* currentDog = addToDog(temp);
		/*
			This is where you will add the dogs
		*/

	}
	cout << endl;
	infile.close();
	return true;
}

/*JASON I changed the file a lot.  Reading from it will be much easier if
we just comment delimit everything by comments and delimit the last entry by a newline*/
bool readDogsToHashFromFile(HashMap& dogHash)
{
	fstream dogFile;

	dogFile.open(FILENAME, fstream::in);
	while (!dogFile.eof())
	{
		string tempId = "";
		string tempName = "";
		string tempAge = "";
		string tempGender = "";
		string tempBreed = "";
		string tempDesc = "";

		getline(dogFile, tempId, ',');
		getline(dogFile, tempName, ',');
		getline(dogFile, tempAge, ',');
		getline(dogFile, tempGender, ',');
		getline(dogFile, tempBreed, ',');
		getline(dogFile, tempDesc, '\n');

		Dog* dog = new Dog(tempId, tempName, tempAge, tempGender, tempBreed, tempDesc);
		dogHash.put(*dog);
	}
	dogFile.close();
	return true;
}


/*
JASON - I don't think we need to use this.  
Check out ReadDogsToHashFromFile() for a working example that is simpler

BRYSON - I agree.

addToDog(string str)
Precondition: A string containing the data to be stored within the Dog class
Postcondition: Creates a new object of class Dog and then return it.

Notes: temporary not meant for linked list
This code was written by Sam Song and then adapted for linked lists/ binary search tree

Returns a Dog object from the string representation
DOGID, dog name, dog gender, dog age, dog breed, dog description. <-- period at end is important
*/

Dog* addToDog(string str)
{
	int segmentNo = 0;
	string temp = "";
	string segment[7];

	map<char, int> ignore; //0 = ignore character, 1 = end of segment, 2 stop reading
	ignore['<'] = 0;
	ignore['>'] = 2;
	ignore['.'] = 2;
	ignore['/'] = 2;
	ignore[','] = 1;
	for (int i = 0; i < str.length(); i++)
	{
		char ch = str.at(i);

		if (ignore.count(ch) < 1)
		{
			temp += ch;
		} //adds char to temporary string for that particular segment
		else
		{
			int instruction = ignore.find(ch)->second;
			switch (instruction)
			{
			case 0:	//ignores that particular character.
				break;
			case 1:	//moves onto next segment.
				segment[segmentNo] = temp;
				segmentNo++;
				//				cout << "Segment has been successfully added." << endl;
				temp = ""; //empties temp
				//aDog.addData(temp); 
				break;
			case 2:
				//				cout << "Segment has been successfully added." << endl;
				segment[segmentNo] = temp;
			}
		}
	}
	Dog *aDog = new Dog(segment[0], segment[1], segment[2], segment[3], segment[4], segment[5]);
	return aDog;

	/*string partsOfDog[] = { "ID", "Name", "Gender", "Age", "Breed", "Description", "extra?" };
	cout << "Finished reading in dog with " << endl;
	for (int i = 0; i < 6; i++)
		cout << partsOfDog[i] << ": " << segment[i] << endl;
	cout << endl;
	return 0;*/
}

bool updateDogFile(/*BinaryTree& dogIdTree*/)
{
	ofstream out;
	//out.open(FILENAME.c_str());
	// will update dogs hre

	//out.close();
	return true;
}

bool addDog()
{
	return true;
}

bool removeDog()
{
	return true;
}

bool displayDogInfoByIdSearch()
{
	string input;
	cout << "Enter the ID of the Dog to search for.\nUse the format \"DOG###\" -> ";
	cin >> input;
	// call the search function of the BST
	// Display the Dog (override the ostream? <<)
	// write a function to verify that ID is entered in correct format?
	cout << endl;
	return true;
}

bool displayDogsInHashSequence(HashMap& dogHash)
{
	dogHash.display();
	return true;
}

bool displayDogsInKeySequence()
{
	// call the BST in-order traversal
	return true;
}

bool displayIndentedTree()
{
	// call the display tree function (avl tree)?
	return true;
}

/*
Load Factor
Longest Linked List
Average number of nodes in linked lists 8
*/
bool displayEfficiencyReport()
{
	
	return true;
}

//Team Choice 1
bool updateDog()
{
	string input;
	cout << "Enter the ID of the Dog to search for.\nUse the format \"DOG###\" -> ";
	cin >> input;
	// call the search function of the BST
	// Display the Dog (override the ostream? <<)
	// write a function to verify that ID is entered in correct format?
	cout << endl;
	return true;
}

bool updateDogMenu()
{
	return true;
}

bool updateName()
{
	return true;
}

bool updateAge()
{
	return true;
}

bool updateBreed()
{
	return true;
}

bool updateDesc()
{
	return true;
}

/*Team Choice 2	-	Note:	This section may be tricky because we'll have to create many different trees.
I suggest we start with Team Choice 1 and do this if we have time.*/
bool SearchDogMenu()
{
	return true;
}

bool searchDogByName()
{
	return true;
}

bool searchDogByGender()
{
	return true;
}

bool searchDogByAge()
{
	return true;
}

bool searchDogByBreed()
{
	return true;
}


