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

};

#endif
