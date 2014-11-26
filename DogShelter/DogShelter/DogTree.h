#ifndef DOGTREE_H
#define DOGTREE_H
#include <iostream>
#include "Dog.h"
using namespace std;

template <class T>
class DogTree
{
private:
	struct TreeNode
	{
		Dog value;			//The value in the node
		TreeNode *left;		//Pointer to the left child node
		TreeNode *right;	//Pointer to right child node
	};

	TreeNode *root;			//Pointer to the root node

	//Private Member Functions
	void insert(TreeNode *&, TreeNode *&);
	void destroySubTree(TreeNode *);
	void deleteNode(Dog, TreeNode *&);
	void makeDeletion(TreeNode *&);
	void displayInOrder(TreeNode *) const;
	void displayPreOrder(TreeNode *) const;
	void displayPostOrder(TreeNode *) const;

public:
	//Constructor
	DogTree()
	{
		root = NULL;
	}

	//Destructor
	~DogTree()
	{
		destroySubTree(root);
	}

	//Dog Tree Operations
	void insertNode(Dog);
	bool searchNode(Dog);
	void remove(Dog);

	void displayInOrder() const
	{
		displayInOrder(root);
	}

	void displayPreOrder() const
	{
		displayPreOrder(root);
	}

	void displayPostOrder() const
	{
		displayPostOrder(root);
	}
};
#endif

// switched to Dog
template <class T>
void DogTree<T>::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
	if (nodePtr == NULL)
		nodePtr = newNode;						//Insert the node
	else if (newNode->value.getID() < nodePtr->value.getID())
		insert(nodePtr->left, newNode);			//Search the left branch
	else
		insert(nodePtr->right, newNode);		//Search the right branch
}

// Switched to Dog
template <class T>
void DogTree<T>::insertNode(Dog item)
{
	TreeNode *newNode;							//Pointer to a new node

	//Create a new node and store num in it.
	newNode = new TreeNode;
	newNode->value = item;
	newNode->left = newNode->right = NULL;

	//Insert the node.
	insert(root, newNode);
}

template <class T>
void DogTree<T>::destroySubTree(TreeNode *nodePtr)
{
	if (nodePtr)
	{
		if (nodePtr->left)
			destroySubTree(nodePtr->left);
		if (nodePtr->right)
			destroySubTree(nodePtr->right);
		delete nodePtr;
	}
}

template <class T>
bool DogTree<T>::searchNode(Dog item)
{
	TreeNode *nodePtr = root;

	while (nodePtr)
	{
		if (nodePtr->value.getID() == item.getID())
			return true;
		else if (item < nodePtr->value)
			nodePtr = nodePtr->left;
		else
			nodePtr = nodePtr->right;
	}
	return false;
}

template <class T>
void DogTree<T>::remove(Dog item)
{
	deleteNode(item, root);
}

template <class T>
void DogTree<T>::deleteNode(Dog item, TreeNode *&nodePtr)
{
	if (item < nodePtr->value.getID())
		deleteNode(item.getID(), nodePtr->left);
	else if (item.getID() > nodePtr->value.getID())
		deleteNode(item, nodePtr->right);
	else
		makeDeletion(nodePtr);
}

template <class T>
void DogTree<T>::makeDeletion(TreeNode *&nodePtr)
{
	//Define a temporary pointer to use in reattaching the left subtree
	TreeNode *tempNodePtr;

	if (nodePtr == NULL)
		cout << "Cannot delete empty node.\n";
	else if (nodePtr->right == NULL)
	{
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->left;				//Reattach the left child
		delete tempNodePtr;
	}
	else if (nodePtr->left == NULL)
	{
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->right;				//Reattach the right child
		delete tempNodePtr;
	}
	else
	{
		//Move one node to the right.
		tempNodePtr = nodePtr->right;
		//Go to the end left node.
		while (tempNodePtr->left)
			tempNodePtr = tempNodePtr->left;
		//Reattach the left subtree.
		tempNodePtr->left = nodePtr->left;
		tempNodePtr = nodePtr;
		//Reattach the right subtree.
		nodePtr = nodePtr->right;
		delete tempNodePtr;
	}
}

template <class T>
void DogTree<T>::displayInOrder(TreeNode *nodePtr) const
{
	if (nodePtr)
	{
		displayInOrder(nodePtr->left);
		cout << nodePtr->value.getID() << endl;
		displayInOrder(nodePtr->right);
	}
}

template <class T>
void DogTree<T>::displayPreOrder(TreeNode *nodePtr) const
{
	if (nodePtr)
	{
		cout << nodePtr->value << endl;
		displayPreOrder(nodePtr->left);
		displayPreOrder(nodePtr->right);
	}
}

template <class T>
void DogTree<T>::displayPostOrder(TreeNode *nodePtr) const
{
	if (nodePtr)
	{
		displayPostOrder(nodePtr->left);
		displayPostOrder(nodePtr->right);
		cout << nodePtr->value << endl;
	}
}
