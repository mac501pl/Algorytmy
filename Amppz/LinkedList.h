#pragma once

#include <iostream>
#include <stdexcept>

struct linkedListNode {
	int data;
	linkedListNode* next;
};

class LinkedList
{
	void insertToTheBeginning(int /*x*/, linkedListNode*& /*head*/);
	void removeFromTheBeginning(linkedListNode*& /*head*/);
	void insertToIndex(int /*index*/, int /*x*/, linkedListNode*& /*head*/);
	void removeFromIndex(int /*index*/, linkedListNode*& /*head*/);
	void print(linkedListNode* /*temp*/);
	bool search(int /*x*/, linkedListNode* /*head*/);
	int peekFromIndex(int /*index*/, linkedListNode* /*head*/);
	bool isEmpty(linkedListNode* /*node*/);
	int size(linkedListNode* /*head*/);
public:
	void run();
	LinkedList();
};

