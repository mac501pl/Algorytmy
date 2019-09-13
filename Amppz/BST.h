#pragma once
#include <iostream>
#include <stdexcept>

class BST
{
	struct node {
		int data;
		node* left;
		node* right;
	};
	node* root;
	void insert(int);
	node* search(int);
public:
	BST();
	void run();
};
