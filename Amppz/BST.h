#pragma once
#include <iostream>
#include <stdexcept>
#include <time.h>
#include <vector>
#include <random>
#include <algorithm>

struct node {
	int data;
	node* left;
	node* right;
};

class BST
{
	int tree_size;
	node* root;
	void insert(int);
	node* search(int);
	void pre_order_traversal(node*);
	void in_order_traversal(node*);
	void post_order_traversal(node*);
public:
	BST();
	void run();
};
