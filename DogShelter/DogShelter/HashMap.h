#ifndef HASH_MAP
#define HASH_MAP
#include "LinkedHashEntry.h"
//included by James, doesn't compile yet

#include <iostream>
#include <string>
using namespace std;

const int TABLE_SIZE = 31;

class HashMap
{
private:
	LinkedHashEntry **table;
	
public:
	HashMap()
	{
		table = new LinkedHashEntry*[TABLE_SIZE];
		for (int i = 0; i < TABLE_SIZE; i++)
			table[i] = nullptr;
	}
	
	string get(int key)
	{
		int hash = (key % TABLE_SIZE);
		if (table[hash] == nullptr)
			return "";
		else
		{
			LinkedHashEntry *entry = table[hash];
			while (entry != nullptr && entry->getKey() != key)
				entry = entry->getNext();
			if (entry == nullptr)
				return "";
			else
				return entry->getValue();
		}
	}

	void put(int key, string value)
	{
		int hash = (key % TABLE_SIZE);
		if (table[hash] == nullptr)
			table[hash] = new LinkedHashEntry(key, value);
		else
		{
			LinkedHashEntry *entry = table[hash];
			while (entry->getNext() != nullptr)
				entry = entry->getNext();
			if (entry->getKey() == key)
				entry->setValue(value);
			else
				entry->setNext(new LinkedHashEntry(key, value));
		}
	}

	void remove(int key)
	{
		int hash = (key % TABLE_SIZE);
		if (table[hash] != nullptr)
		{
			LinkedHashEntry *prevEntry = nullptr;
			LinkedHashEntry *entry = table[hash];
			while (entry->getNext() != nullptr && entry->getKey() != key)
			{
				prevEntry = entry;
				entry = entry->getNext();
			}
			if (entry->getKey() == key)
			{
				if (prevEntry == nullptr)
				{
					LinkedHashEntry *nextEntry = entry->getNext();
					delete entry;
					table[hash] = nextEntry;
				}
				else
				{
					LinkedHashEntry *next = entry->getNext();
					delete entry;
					prevEntry->setNext(next);
				}
			}
		}
	}

	//I added this in to test the hash output
	void display()
	{
		for (int i = 0; i < TABLE_SIZE; i++)
		{
			if (table[i] != nullptr)
			{
				LinkedHashEntry *entry = table[i];
				cout << entry->getValue() << endl;;
				while (entry->getNext() != nullptr)
				{
					entry = entry->getNext();
					cout << entry->getValue() << endl;
				}
				
			}
		}
	}

	~HashMap()
	{
		for (int i = 0; i < TABLE_SIZE; i++)
		{
			if (table[i] != nullptr)
			{
				LinkedHashEntry *prevEntry = nullptr;
				LinkedHashEntry *entry = table[i];
				while (entry != nullptr)
				{
					prevEntry = entry;
					entry = entry->getNext();
					delete prevEntry;
				}
			}
		}
		delete[] table;
	}
};

#endif
