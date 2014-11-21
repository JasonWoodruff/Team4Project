using namespace std;

#include<iostream>
#include <string>
#include <sstream>

#include "Dog.h"

static int keyNumGenerator = 1; //increments when each new instance of Dog is created

Dog::Dog()
{ ID = generateID(); }

Dog::Dog(string strID, string strN, string strGen, string strAge, string strB, string strD) :
ID(strID), name(strN), gender(strGen), age(strAge), breed(strB), description(strD)
{}

string Dog::getID() const
{ return ID; }

string Dog::getName() const
{ return name; }

string Dog::getAge() const
{ return age; }

string Dog::getGender() const
{ return gender; }

string Dog::getBreed() const
{ return breed; }

string Dog::getDescription() const
{ return description; }

void Dog::setID(string key)
{ ID = key; }

void Dog::setName(string n)
{ name = n; }

void Dog::setAge(string a)
{ age = a; }

void Dog::setBreed(string type)
{ breed = type; }

void Dog::setDescription(string desc)
{ description = desc; }

string Dog::generateID()
{
  int tempID = keyNumGenerator++; //next number available for id assignment
  string pad = ""; //a cushion of filler 0s
  stringstream s;
  if (tempID < 10) //create the filler 0s if needed
    pad = "00";
  else if (tempID < 100)
    pad = "0";
  s << "DOG" << pad << tempID; //concatenate all parts of id
  return s.str();
}
