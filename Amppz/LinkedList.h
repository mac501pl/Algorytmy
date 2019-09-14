#pragma once

#include <iostream>
#include <stdexcept>

struct linkedListNode {
	int data;
	linkedListNode* next;
};

class LinkedList
{
	void insertToTheBeginning(int /*x*/, linkedListNode*& /*beginning*/);	//done
	void removeFromTheBeginning(linkedListNode*& /*beginning*/);
	void insertToIndex(int /*index*/, int /*x*/, linkedListNode*& /*beginning*/);
	void removeFromIndex(int /*index*/, linkedListNode*& /*beginning*/);
	void print(linkedListNode* /*temp*/);	//done
	bool search(int /*x*/, linkedListNode*& /*beginning*/);
	int peekFromIndex(int /*index*/, linkedListNode* /*beginning*/);
	bool isEmpty(linkedListNode* /*node*/);	//done
	int size(linkedListNode* /*head*/);	//done
public:
	void run();
	LinkedList();
};

