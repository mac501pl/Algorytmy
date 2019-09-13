#pragma once
#include <stdexcept>
#include <iostream>

struct stackElem {
	int data;
	stackElem* next;
};

class Stack
{
	void push(stackElem*& /*current_top_of_the_stack*/, int /*x*/);
	int pop(stackElem*& /*current_top_of_the_stack*/);
	int peek(stackElem* /*current_top_of_the_stack*/);
	bool isEmpty(stackElem* /*current_top_of_the_stack*/);
public:
	void run();
};
