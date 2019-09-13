#pragma once

#include <stdexcept>
#include <iostream>

struct queueElem {
	int data;
	queueElem* next;
};

class Queue
{
	void add(queueElem*&, queueElem*&, int);
	int next(queueElem*&, queueElem*&);
	int peek(queueElem*);
	bool isEmpty(queueElem*);
public:
	void run();
};

