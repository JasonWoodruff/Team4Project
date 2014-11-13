#pragma once
#ifndef DOG_H
#define DOG_H
#include <string>
#include <iostream>

using namespace std;

class Dog
{
private:
	int age;
	string ID; //format DOG001, DOG002
	string name;
	string breed;
	string size; //small, medium, large
	string description;

public:

	Dog(int a, string strID, string strN, string strB, string strS, string strD);


	void update();
	void add();
	void deleteDog();
	void searchByID();
	void searchByAge();
	void searchBySize();
	void searchByName();
	void listByID(Dog[]);
	void listByHashSequence(Dog[]);//List by hash table sequence
	void printIndentedTree(Dog[]);

	
	void efficiencyReport();
};

#endif
