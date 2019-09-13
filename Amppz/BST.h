#pragma once
#include <iostream>
#include <stdexcept>

struct node {
	int data;
	node* left;
	node* right;
};

class BST
{
	node* root;
	void insert(int);
	node* search(int);
public:
	BST();
	void run();
};
