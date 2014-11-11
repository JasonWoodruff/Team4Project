/*
CIS22C Team 4 Project:	Dog Shelter Management Program

Purpose:	Create an easily accessible and editable catalog of dogs in a shelter
and allow the user to search through it based on dog attributes

@author		Jason Woodruff	-	Project Coordinator
Stacy Wheeler	-	Data Record
Bryson Li		-	I/O
James Juchau	-	Hashed Table
Kevin Chen		-	Binary Search Tree

@version	1.0
@since		11/10/2014
*/

#include <iostream>
#include <string>
using namespace std;

bool readDogsInFromFile(/*BinaryTree& dogIdTree*/);		//open the input file and read the dogs into a tree
bool updateDogFile(/*BinaryTree& dogIdTree*/);			//probably want to change this later to take arguments

bool mainMenu();					//display the main menu
int getMainMenuChoice();
bool processMainMenuChoice(int choice/*, BinaryTree& dogIdTree*/);

bool addDog();						//add a dog to the tree
bool removeDog();					//delete a dog from the tree
bool displayDogInfoByIdSearch();	//displays all of a dog's info if it's found with an id search
bool displayDogsInHashSequence();	//display dogs in hash sequence
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

int main()
{
	int choice = 0;

	/*BinaryTree dogIdTree;*/

	while (choice != 12)
	{
		mainMenu();
		choice = getMainMenuChoice();
		processMainMenuChoice(choice /*, dogIdTree*/);
	}

	system("pause");
	return 0;
}

bool mainMenu()
{
	cout << "-----------------Main Menu-----------------" << endl << endl;
	cout << "1  - Create the search tree" << endl;
	cout << "2  - Add a dog" << endl;
	cout << "3  - Remove a dog" << endl;
	cout << "4  - Display dog attributes" << endl;
	cout << "5  - Update dog attributes" << endl;
	cout << "6  - Display dogs in hash sequence" << endl;
	cout << "7  - Display dogs in key sequence" << endl;
	cout << "8  - Display indented search tree" << endl;
	cout << "9  - Display efficiency report" << endl;
	cout << "10 - Clear the search tree" << endl;
	cout << "11 - Update the file" << endl;
	cout << "12 - Quit" << endl << endl;
	cout << "Enter your choice here: ";

	return true;
}

int getMainMenuChoice()
{
	string input;
	int choice;

	cin >> input;
	choice = atoi(input.c_str());

	while (choice < 1 || choice > 12)
	{
		cout << "Invalid menu choice, try again: ";
		cin >> input;
		choice = atoi(input.c_str());
	}
	cout << endl;
	return choice;
}

bool processMainMenuChoice(int choice /*, BinaryTree& dogIdTree*/)
{
	switch (choice)
	{
	case 1:
	{
		readDogsInFromFile(/*dogIdTree*/);
		break;
	}
	case 2:
	{
		addDog();
		break;
	}
	case 3:
	{
		removeDog();
		break;
	}
	case 4:
	{
		displayDogInfoByIdSearch();
		break;
	}
	case 5:
	{
		updateDog();
		break;
	}
	case 6:
	{
		displayDogsInHashSequence();
		break;
	}
	case 7:
	{
		displayDogsInKeySequence();
		break;
	}
	case 8:
	{
		displayIndentedTree();
		break;
	}
	case 9:
	{
		displayEfficiencyReport();
		break;
	}
	case 10:
	{
		/*dogIdTree.clear();*/
		break;
	}
	case 11:
	{
		updateDogFile(/*dogIdTree*/);
	}
	case 12:
	{
		cout << "Thank you, now exiting..." << endl;
		break;
	}
	}
	return true;
}

bool readDogsInFromFile(/*BinaryTree& dogIdTree*/)
{
	return true;
}
bool updateDogFile(/*BinaryTree& dogIdTree*/)
{
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
	return true;
}

bool displayDogsInHashSequence()
{
	return true;
}

bool displayDogsInKeySequence()
{
	return true;
}

bool displayIndentedTree()
{
	return true;
}

bool displayEfficiencyReport()
{
	return true;
}

//Team Choice 1
bool updateDog()
{
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

//Testing this change on GitHub
