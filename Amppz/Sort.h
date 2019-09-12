#pragma once

#include <iostream>
#include <time.h>
#include <algorithm>
#include <string>
#include <random>
#include <chrono>

using namespace std::chrono;

class Sort
{
	int arr_size;
	int* tab;

	time_point<steady_clock> begin_time_count();
	int end_time_count(time_point<steady_clock>);

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

