#include "BST.h"
//todo: poprawki z clang tidy, warningi, drzewo, listy

BST::BST()
{
	root = nullptr;
}

void BST::insert(int x)
{
	node* newNode = new node;
	newNode->data = x;
	newNode->left = nullptr;
	newNode->right = nullptr;

	node* current = nullptr;

	if (!root)
	{
		root = newNode;
	}
	else
	{
		current = root;
		while (true)
		{
			if (x < current->data)
			{
				current = current->left;
				if (!current)
				{
					current = newNode;
					return;
				}
			}
			else
			{
				current = current->right;
				if (!current)
				{
					current = newNode;
					return;
				}
			}
		}
	}
}

node* BST::search(int x)
{
	if (!root)
	{
		throw std::runtime_error::runtime_error("Puste drzewo");
	}
	node* current = root;

	while (current->data != x)
	{
		if (x < current->data)
		{
			current = current->left;
		}
		else
		{
			current = current->right;
		}
		if (!current)
		{
			return nullptr;
		}
	}
	return current;
}

void BST::run()
{

}