#pragma once

#include <iostream>
#include <time.h>
#include <algorithm>
#include <string>

class Sort
{
	int arr_size;
	int* tab;

	clock_t begin_time_count();
	float end_time_count(clock_t);

	void swap(int&, int&);
	void print_array(int*);

	void bubble_sort(int*);
	void merge_sort(int*);
	void insertion_sort(int*);
	void quick_sort(int*, int, int);
public:
	void run();
	Sort();
	~Sort();
};

