#include "Sort.h"

Sort::Sort()
{
	std::cout << "Podaj wielkosc tablicy: ";
	std::cin >> arr_size;
	tab = new int[arr_size];
}

Sort::~Sort()
{
	delete[] tab;
}

void Sort::swap(int& i, int& j)
{
	int temp = j;
	j = i;
	i = temp;
}

clock_t Sort::begin_time_count()
{
	return clock();
}

float Sort::end_time_count(clock_t start_time)
{
	return float(clock() - start_time) / CLOCKS_PER_SEC;
}

void Sort::print_array(int* tab)
{
	if (arr_size <= 10)
	{
		for (int i = 0; i < arr_size; i++)
		{
			std::cout << tab[i] << " ";
		}
	}
	else
	{
		std::cout << "Drukowanie tablicy wylaczone z powodu duzej wielkosci";
	}
	std::cout << "\n";
}

void Sort::bubble_sort(int* tab)
{
	for (int i = 0; i < arr_size; i++)
	{
		for (int j = 0; j < arr_size - i - 1; j++)
		{
			if (tab[j] > tab[j + 1])
			{
				swap(tab[j], tab[j + 1]);
			}
		}
	}
}

void Sort::quick_sort(int* tab, int left, int right)
{
	if (right <= left) { return; }
	int i = left - 1, j = right + 1, pivot = tab[(left + right) / 2];

	while (true)
	{
		while (pivot > tab[++i]);
		while (pivot < tab[--j]);
		if (i <= j)
		{
			swap(tab[i], tab[j]);
		}
		else
		{
			break;
		}
	}
	if (j > left)
	{
		quick_sort(tab, left, j);
	}
	if (i < right)
	{
		quick_sort(tab, i, right);
	}
}

void Sort::run()
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < arr_size; i++)
	{
		tab[i] = rand() % 10 + 1;
	}

	clock_t start_time;
	float time;

	std::cout << "\n";
	std::cout << "Nasza tablica: ";
	print_array(tab);
	std::cout << "Sortowanie babelkowe" << "\n";

	start_time = begin_time_count();
	bubble_sort(tab);
	time = end_time_count(start_time);

	std::cout << "Posortowana tablica (czas: " << time << "): ";
	print_array(tab);
	std::cout << "Mieszanie...";
	std::random_shuffle(&tab[0], &tab[arr_size]);

	std::cout << "\n";
	std::cout << "Nasza tablica: ";
	print_array(tab);
	std::cout << "Sortowanie szybkie" << "\n";

	start_time = begin_time_count();
	quick_sort(tab, 0, arr_size - 1);
	time = end_time_count(start_time);

	std::cout << "Posortowana tablica (czas: " << time << "): ";
	print_array(tab);
	std::cout << "Mieszanie...";
	std::random_shuffle(&tab[0], &tab[arr_size]);



	std::cout << std::endl;
}

