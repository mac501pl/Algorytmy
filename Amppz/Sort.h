#pragma once

#include <iostream>
#include <time.h>
#include <algorithm>
#include <string>
#include <random>

class Sort
{
	int arr_size;
	int* tab;

	clock_t begin_time_count();
	float end_time_count(clock_t);

	void swap(int&, int&);
	void print_array(int*);

	void bubble_sort();
	void merge(int*, int, int, int);
	void merge_sort(int, int);
	void insertion_sort();
	void quick_sort(int, int);
public:
	void run();
	Sort();
	~Sort();
};

