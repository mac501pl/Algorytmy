#pragma once

#include <stdexcept>
#include <iostream>

using std::cout;

struct queueElem {
	int data;
	queueElem* next;
};

class Queue
{
	void add(queueElem*& /*beginning*/, queueElem*& /*end*/, int /*x*/);
	int next(queueElem*& /*beginning*/, queueElem*& /*end*/);
	int peek(queueElem* /*beginning*/);
	bool isEmpty(queueElem* /*beginning*/);
public:
	void run();
};

