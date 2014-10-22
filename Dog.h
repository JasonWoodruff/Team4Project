#ifndef dog.h
#include <iostream>
#include <string>
using namespace std;

class dog
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
	void printIndentedTree(dog[]);

	
	void efficiencyReport();
};

#endif
