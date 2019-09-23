#pragma once

#include <iostream>
#include <stdexcept>

using std::cout;

struct linkedListNode {
	int data;
	linkedListNode* next;
};

class LinkedList
{
	void insertToTheBeginning(const int /*x*/, linkedListNode*& /*head*/) const;
	void removeFromTheBeginning(linkedListNode*& /*head*/) const;
	void insertToIndex(const int /*index*/, const int /*x*/, linkedListNode*& /*head*/) const;
	void removeFromIndex(const int /*index*/, linkedListNode*& /*head*/) const;
	void print(const linkedListNode* /*temp*/) const;
	bool search(const int /*x*/, const linkedListNode* /*head*/) const;
	int peekFromIndex(const int /*index*/, const linkedListNode* /*head*/) const;
	bool isEmpty(const linkedListNode* /*node*/) const;
	int size(const linkedListNode* /*head*/) const;
public:
	void run();
	LinkedList();
};

