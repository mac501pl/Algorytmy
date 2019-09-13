#pragma once
#include <iostream>
#include <stdexcept>
#include <time.h>
#include <vector>
#include <random>
#include <algorithm>

struct bstNode {
	int data;
	bstNode* left;
	bstNode* right;
};

class BST
{
	int tree_size;
	bstNode* root;
	void insert(int);
	bstNode* search(int);
	void pre_order_traversal(bstNode*);
	void in_order_traversal(bstNode*);
	void post_order_traversal(bstNode*);
public:
	BST();
	void run();
};
