#ifndef DOG_H
#define DOG_H

#include <iostream>
#include <string>
using namespace std;

class Dog
{
	int age;
	string ID, //format DOG001, DOG002
		name,
		breed,
		size, //small, medium, large
		description;


	void update();
	void add();
	void deleteDog();
	void searchByID();
	void searchByAge();
	void searchBySize();
	void searchByName();
	void listByID(dog[]);
	void listByHashSequence(Dog[]);//List by hash table sequence
	void printIndentedTree(Dog[]);

	
	void efficiencyReport();
};

#endif
