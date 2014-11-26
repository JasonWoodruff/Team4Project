#include <iostream>
#include "BinaryTree.h"
#include <string>
#include "Dog.h"
using namespace std;

const int NUM_NODES = 5;

int main()
{
	string name;

	//Create the Dog tree.
	DogTree<string> tree;

	//Insert some names.
	for (int count = 0; count < NUM_NODES; count++)
	{
		cout << "Enter a test ID: ";
		getline(cin, name);
		Dog testDog = Dog(name,"","","","","");
		tree.insertNode(testDog);
	}

	//Display the values.
	cout << "\nHere are the values in the tree:\n";
	tree.displayInOrder();

	system("pause");
	return 0;
}
