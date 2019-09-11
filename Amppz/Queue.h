#pragma once

#include <stdexcept>
#include <iostream>

class Queue
{
	struct elem {
		int data;
		elem* next;
	};

	void add(elem*&, elem*&, int);
	int next(elem*&, elem*&);
	int peek(elem*);
	bool isEmpty(elem*);
public:
	void run();
};

