#pragma once
#include <iostream>
#include <stdexcept>
#include <ctime>
#include <vector>
#include <random>
#include <algorithm>

using std::cout;

struct bstNode {
	int data;
	bstNode* left;
	bstNode* right;
};

class BST
{
	int tree_size;
	bstNode* root;
	void insert(int /*x*/);
	bstNode* search(int /*x*/);
	void pre_order_traversal(bstNode* /*root*/);
	void in_order_traversal(bstNode* /*root*/);
	void post_order_traversal(bstNode* /*root*/);
public:
	BST();
	void run();
};
