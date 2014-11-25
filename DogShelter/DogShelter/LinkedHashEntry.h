#ifndef LINKED_HASH_ENTRY
#define LINKED_HASH_ENTRY
#include "Dog.h"

/*I've modified this to operate on the dog's ID number and the Dog class*/

/*I've also added a hashID() function to partition the strings like 'DOG001' and 'DOG002' into int values '01' and '02' respectively*/

//hopefully this commits

class LinkedHashEntry
{
private:
	int hashVal;
	string key; //this will be a string with the dog id (ex. "DOG002")
	/*JAMES: I left in the above string because I wasn't sure if it was needed. hashVal is the actual assigned hash value
	assigned to each dog node. It's derived from the Dog objects ID number (ie string "DOG002" has a hash value of '02'
	as an int. I don't know if this string belongs, but I'll leave it there until I know for sure.*/
	Dog dog; //the Dog object associated with the dog id
	LinkedHashEntry *next;
public:
	LinkedHashEntry(Dog entry)
	{
		this->hashVal = hashID(entry.getID()); //hashes the input Dog's ID string; creates an int that is just the last two characters in the dog's ID
		this->key = entry.getID();
		this->dog = entry;
		this->next = nullptr;
	}

	string getKey()
	{
		return key;
	}

	Dog getValue()
	{
		return dog;
	}

	void setValue(Dog value)
	{
		this->dog = value;
	}

	LinkedHashEntry *getNext()
	{
		return next;
	}

	void setNext(LinkedHashEntry *next)
	{
		this->next = next;
	}

	int hashID(string in)
	{//DOG002
		int hashValue = 0;
		char x = in[4], //takes the fifth letter in the string
			y = in[5]; //takes the sixth letter in the string
		/* Suggestion: to make this more efficient, think about the following:
		(int)'0' == 48   all the way to (int)'9' == 57
		Also #include<cctype> has a function isdigit(char) to check if a char is a # from '0' to '9'*/
		if (x = '0'){ hashValue += 0; }
		if (x = '1'){ hashValue += 10; }
		if (x = '2'){ hashValue += 20; }
		if (x = '3'){ hashValue += 30; }
		if (x = '4'){ hashValue += 40; }
		if (x = '5'){ hashValue += 50; }
		if (x = '6'){ hashValue += 60; }
		if (x = '7'){ hashValue += 70; }
		if (x = '8'){ hashValue += 80; }
		if (x = '9'){ hashValue += 90; } //makes the fifth integer the 'tens' value in the hash int

		if (y = '0'){ hashValue += 0; }
		if (y = '1'){ hashValue += 1; }
		if (y = '2'){ hashValue += 2; }
		if (y = '3'){ hashValue += 3; }
		if (y = '4'){ hashValue += 4; }
		if (y = '5'){ hashValue += 5; }
		if (y = '6'){ hashValue += 6; }
		if (y = '7'){ hashValue += 7; }
		if (y = '8'){ hashValue += 8; }
		if (y = '9'){ hashValue += 9; } //makes the sixth integer the 'ones' value in the hash int
		return hashValue;
	}
};

#endif
