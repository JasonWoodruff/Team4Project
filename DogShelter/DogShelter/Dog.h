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
	string generateID()
	{
		int tempID = keyNumGenerator++;             //next number available for id assignment
		string pad = "";                            //a cushion of filler 0s
		stringstream s;

		if (tempID < 10)                           //create the filler 0s if needed
			pad = "00";
		else if (tempID < 100)
			pad = "0";

		s << "DOG" << pad << tempID;                //concatenate all parts of id

		return s.str();
	}

public:
	static int keyNumGenerator = 1;     //increments when each new instance of Dog is created
	
	Dog()
	{  ID = generateID();  }
	
	Dog(string strID, string strN, string strGen, string strAge, string strB, string strD) :
		ID(strID), name(strN), gender(strGen), age(strAge), breed(strB), description(strD)
	{}
	
	string getID() const
	{  return ID;  }
	
	string getName() const
	{  return name;  }
	
	string getAge() const
	{  return age;  }
	
	string getGender() const
	{  return gender;  }

	string getBreed() const
	{  return breed;  }
	
	string getDescription() const
	{  return description;  }
	
	void setID(string key)
	{  ID = key;  }
	
	void setName(string n)
	{  name = n;  }
	
	void setAge(string a)
	{  age = a;  }
	
	void setBreed(string type)
	{  breed = type;  }
	
	void setDescription(string desc)
	{  description = desc;  }

};

#endif
