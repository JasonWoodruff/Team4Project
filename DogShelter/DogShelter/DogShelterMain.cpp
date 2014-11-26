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
#include <Windows.h> //included by James for 'system("CLS")', a clear screen command for aesthetic purposes
#include <string>
#include <fstream>
#include "Dog.h"
#include "HashMap.h"
using namespace std;

bool readDogsToTreeFromFile(/*BinaryTree& dogIdTree*/);		//open the input file and read the dogs into a tree
bool readDogsToHashFromFile(HashMap& dogHash);							//open the input file and read the dogs into a hash

bool updateDogFile(/*BinaryTree& dogIdTree*/);			//probably want to change this later to take arguments

bool mainMenu();					//display the main menu
int getMainMenuChoice();
bool processMainMenuChoice(int choice/*, BinaryTree& dogIdTree*/, HashMap& dogHash);

bool addDog();						//add a dog to the tree and hash
bool removeDog();					//delete a dog from the tree and hash
bool displayDogInfoByIdSearch(HashMap& dogHash);	//displays all of a dog's info if it's found with an id search
bool displayDogsInHashSequence(HashMap& dogHash);	//display dogs in hash sequence
bool displayDogsInKeySequence(/*BinaryTree& dogIdTree*/);	//display dogs in key sequence
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

//JASON: Menu choices 1 and 2 will be consolidated later to: Load the Database
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
			displayDogInfoByIdSearch(dogHash);
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
			displayDogsInKeySequence(); //will display dogs by Inorder Tree traversal
			break;
		}
		case 9:
		{
			displayIndentedTree(); //call the Tree function that displays the tree
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
		//dogTree.add(*dog);
	}
	dogFile.close();
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
		Dog::keyNumGenerator--;
		/*Need to decrement keyNumGenerator because every time a Dog gets passed to a function, it is technically copied and generateId() is called.
		Run this code without the decrement to see what happens to keyNumGenerator.  cout << Dog::keyNumGenerator << " ";
		*/
	}
	dogFile.close();
	return true;
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
{	/*JAMES I've coded this to simply assemble a dog object from inputted data, but where this dog object goes is pretty important. 
	Does it get written to 'dog.txt'? Attached to the linked list or hash table? I can do any of those things, we just need to figure out which*/
	Dog* newDog = new Dog;
	string newName, newGender, newAge, newBreed, newDescription;
	char yn='x'; //for finalizing 
	cout << "Please enter the dog's name." << endl;
	cin.ignore();
	getline(cin, newName); newName[0] = toupper(newName[0]);          //capitalizes first letter to homogenize data
	
	while (newGender != "Male" && newGender != "Female")
	{
		cout << "\nEnter the dog's gender ('Male' or 'Female')." << endl;
		cin >> newGender; newGender[0] = toupper(newGender[0]);        //capitalizes the first character to simplify while loop
		if (newGender != "Male" && newGender != "Female"){ cout << "Only the inputs 'Male' and 'Female' are acceptable." << endl; system("pause"); }
	}

	cout << "\nEnter a qualitative estimate of the dog's age (ie 'Puppy', 'Young', 'Older')." << endl;
	cin.ignore();
	getline(cin, newAge); newAge[0] = toupper(newAge[0]);			   


	cout << "\nEnter the dog's breed (ie 'Beagle' or 'Scottish Terrier')." << endl;
	getline(cin, newBreed);	newBreed[0] = toupper(newBreed[0]);


	cout << "\nEnter a brief description of this dog's personality." << endl;
	getline(cin, newDescription); newDescription[0] = toupper(newDescription[0]);

	system("CLS"); //clears screen for aesthetics

	cout << "Name: " << newName << endl;
	cout << "Age: " << newAge << endl;
	cout << "Gender: " << newGender << endl;
	cout << "Breed: " << newBreed << endl;
	cout << "Description: " << newDescription << endl;
	
	while (yn != 'Y' && yn != 'N')
	{
		cout << "Finalize this new dog? (Y/N)" << endl;
		cin >> yn;
		yn = toupper(yn);
		if (yn != 'Y' && yn != 'N'){ cout << "Only the characters 'Y' and 'N' are acceptable." << endl; system("pause");}
	}

	if (yn == 'N'){ cout << "Dog discarded. Returning to main menu..." << endl; system("pause"); system("CLS"); }
	if (yn == 'Y')
	{ 
		newDog->setName(newName); 
		newDog->setBreed(newBreed);
		newDog->setGender(newGender);
		newDog->setAge(newAge);
		newDog->setDescription(newDescription);
		/*Obviously this ultimately does nothing. But we can assign this dog pointer to anything once I know where addDog()
		actually assigns a dog to*/
		cout << "Dog finalized. Returning to main menu..." << endl;
		system("pause"); system("CLS");
	}

	return true;
	return true;
}

bool removeDog()
{
	return true;
}

/*NOTE FOR LATER: We need a validation function, program WILL CRASH if the string passed to get is less than 3 chars.  The hash algorithm needs the last 3 chars.*/
bool displayDogInfoByIdSearch(HashMap& dogHash)
{
	string input;
	cout << "Enter the ID of the Dog to search for.\nUse the format \"DOG###\n";
	cout << "Enter the ID here: ";
	cin >> input;

	Dog dog = dogHash.get(input);

	if (dog.getName() == "")
		cout << "Dog not found" << endl << endl;
	else
		cout << dogHash.get(input).toString() << endl;

	// call the get function of the Hash
	// Display the Dog (override the ostream? <<)
	// write a function to verify that ID is entered in correct format?
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


