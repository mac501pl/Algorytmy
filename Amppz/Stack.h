#pragma once
#include <stdexcept>
#include <iostream>

struct stackElem {
	int data;
	stackElem* next;
};

class Stack
{
	void push(stackElem*&, int);
	int pop(stackElem*&);
	int peek(stackElem*);
	bool isEmpty(stackElem*);
public:
	void run();
};
