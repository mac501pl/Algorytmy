#pragma once
#include <stdexcept>
#include <iostream>

class Stack
{
	struct elem {
		int data;
		elem* next;
	};

	void push(elem*, int);
	int pop(elem*);
	int peek(elem*);
	bool isEmpty(elem*);
public:
	void run();
};
