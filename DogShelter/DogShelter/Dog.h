#ifndef DOG_H
#define DOG_H
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

class Dog
{
private:
	static int keyNumGenerator = 1;     //increments when each new instance of Dog is created
	
	string ID;                          //format DOG001, DOG002
	string name;
	string age;
	string breed;
	string description;
	
protected:
	string generateID()
	{
		int tempID = keyNumGenerator++;
		string IDstr = itoa(tempID);
		
		//creates a "padding" of zeros for the id
		while(IDstr.length() < 4)
			IDstr += "0";
			
		ID = "DOG" + IDstr;
	}

public:
	Dog()
	{  ID = generateID();  }
	
	Dog(string strID, string strN, string strAge, string strB, string strD):
		ID(strID), name(strN), age(strAge), breed(strB), description(strD)
	
	string getID();
	{  return ID;  }
	
	string getName()
	{  return name;  }
	
	string getAge()
	{  return age;  }
	
	string getBreed()
	{  return breed;  }
	
	string getDescription()
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
