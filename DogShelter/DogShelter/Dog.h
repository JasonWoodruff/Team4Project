#ifndef DOG_H
#define DOG_H
#include <string>
#include <iostream>

using namespace std;

class Dog
{
private:
	string ID; //format DOG001, DOG002
	string name;
	string age;
	string breed;
	string description;

public:
	Dog();
	Dog(string strID, string strN, string strAge, string strB, string strD);

};

#endif
