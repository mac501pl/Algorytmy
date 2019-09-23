#pragma once

#include <iostream>
#include <ctime>
#include <algorithm>
#include <string>
#include <random>
#include <chrono>

using std::cout;
using namespace std::chrono;

class Sort
{
	int arr_size;
	int* tab;

	time_point<steady_clock> begin_time_count();
	int end_time_count(time_point<steady_clock> /*start_time*/);

	void swap(int& /*i*/, int& /*j*/);
	void print_array(int* /*tab*/);

	void bubble_sort();
	void merge(int* /*arr*/, int /*l*/, int /*m*/, int /*r*/);
	void merge_sort(int /*p*/, int /*r*/);
	void insertion_sort();
	void quick_sort(int /*left*/, int /*right*/);
public:
	void run();
	Sort();
	~Sort();
};

