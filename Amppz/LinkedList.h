#pragma once

struct linkedListNode {
	int data;
	linkedListNode* next;
};

class LinkedList
{
	void insertToTheBeginning(int, linkedListNode*&);
	void removeFromTheBeginning(linkedListNode*&);
	void insertToIndex(int, int, linkedListNode*&);
	void removeFromIndex(int, linkedListNode*&);
	void display(linkedListNode*&);
	bool search(int, linkedListNode*&);
	void peekFromIndex(int, linkedListNode*&);
public:
	void run();
	LinkedList();
};

