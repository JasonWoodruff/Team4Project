#include <iostream>
#include "BinaryTree.h"
#include <string>
using namespace std;

const int NUM_NODES = 5;

int main()
{
	string name;

	//Create the binary tree.
	BinaryTree<string> tree;

	//Insert some names.
	for (int count = 0; count < NUM_NODES; count++)
	{
		cout << "Enter a name: ";
		getline(cin, name);
		tree.insertNode(name);
	}

	//Display the values.
	cout << "\nHere are the values in the tree:\n";
	tree.displayInOrder();

	system("pause");
	return 0;
}