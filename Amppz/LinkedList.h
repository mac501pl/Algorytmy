#pragma once

struct linkedListNode {
	int data;
	linkedListNode* next;
};

class LinkedList
{
	void insertToTheBeginning(int /*x*/, linkedListNode*& /*beginning*/);
	void removeFromTheBeginning(linkedListNode*& /*beginning*/);
	void insertToIndex(int /*i*/, int /*x*/, linkedListNode*& /*beginning*/);
	void removeFromIndex(int /*i*/, linkedListNode*& /*beginning*/);
	void display(linkedListNode*& /*beginning*/);
	bool search(int /*i*/, linkedListNode*& /*beginning*/);
	void peekFromIndex(int /*i*/, linkedListNode*& /*beginning*/);
	bool isEmpty(linkedListNode*& /*beginning*/);
public:
	void run();
	LinkedList();
};

