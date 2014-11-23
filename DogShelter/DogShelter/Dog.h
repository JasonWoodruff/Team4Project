#ifndef DOG_H
#define DOG_H
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Dog
{
private:
	string ID;                          //format DOG001, DOG002
	string name;
	string age;
	string gender;
	string breed;
	string description;
	
protected:
	//generates a Dog ID based on a static variable which counts the instances of Dogs
	string generateID();
	
public:
	/*Default constructor creates a dogID only*/
	Dog();
	
	/**Constructor assigns all fields*/
	Dog(string strID, string strN, string strGen, string strAge, string strB, string strD);
	
	/**Accessor methods*/
	string getID() const;
	string getName() const;
	string getAge() const;
	string getGender() const;
	string getBreed() const;
	string getDescription() const;
	
	/**Mutator methods*/
	void setID(string key);
	void setName(string n);
	void setAge(string a);
	void setBreed(string type);
	void setDescription(string desc);

};

#endif
