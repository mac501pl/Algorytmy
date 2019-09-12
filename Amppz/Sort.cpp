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

void Sort::bubble_sort()
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

void Sort::quick_sort(int left, int right)
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
		quick_sort(left, j);
	}
	if (i < right)
	{
		quick_sort(i, right);
	}
}

void Sort::merge(int* arr, int l, int m, int r)
{
	int i, j, k, nl, nr;

	nl = m - l + 1;
	nr = r - m;
	int* larr = new int[nl];
	int* rarr = new int[nr];

	for (i = 0; i < nl; i++)
		larr[i] = arr[l + i];
	for (j = 0; j < nr; j++)
		rarr[j] = arr[m + 1 + j];

	i = 0;
	j = 0;
	k = l;

	while (i < nl && j < nr)
	{
		if (larr[i] <= rarr[j]) {
			arr[k] = larr[i];
			i++;
		}
		else {
			arr[k] = rarr[j];
			j++;
		}
		k++;
	}

	while (i < nl)
	{
		arr[k] = larr[i];
		i++; k++;
	}
	while (j < nr)
	{
		arr[k] = rarr[j];
		j++; k++;
	}

	delete[] larr;
	delete[] rarr;
}

void Sort::merge_sort(int p, int r)
{
	int m;
	if (p < r)
	{
		int m = p + (r - p) / 2;

		merge_sort(p, m);
		merge_sort(m + 1, r);
		merge(tab, p, m, r);
	}
}

void Sort::insertion_sort()
{
	int key, j;
	for (int i = 1; i < arr_size; i++)
	{
		key = tab[i];
		j = i;
		while (j > 0 && tab[j - 1] > key)
		{
			tab[j] = tab[j - 1];
			j--;
		}
		tab[j] = key;
	}
}

void Sort::run()
{
	std::random_device rd;
	std::mt19937 generator(rd());

	srand((unsigned int)time(NULL));
	for (int i = 0; i < arr_size; i++)
	{
		tab[i] = rand() % 100 + 1;
	}

	clock_t start_time;
	float time;

	std::cout << "\n";
	std::cout << "Nasza tablica: ";
	print_array(tab);
	std::cout << "Sortowanie babelkowe" << "\n";

	start_time = begin_time_count();
	bubble_sort();
	time = end_time_count(start_time);

	std::cout << "Posortowana tablica (czas: " << time << "): ";
	print_array(tab);
	std::cout << "Mieszanie...";
	std::shuffle(&tab[0], &tab[arr_size], generator);

	std::cout << "\n";
	std::cout << "Nasza tablica: ";
	print_array(tab);
	std::cout << "Sortowanie szybkie" << "\n";

	start_time = begin_time_count();
	quick_sort(0, arr_size - 1);
	time = end_time_count(start_time);

	std::cout << "Posortowana tablica (czas: " << time << "): ";
	print_array(tab);
	std::cout << "Mieszanie...";
	std::shuffle(&tab[0], &tab[arr_size], generator);

	std::cout << "\n";
	std::cout << "Nasza tablica: ";
	print_array(tab);
	std::cout << "Sortowanie przez wstawianie" << "\n";

	start_time = begin_time_count();
	insertion_sort();
	time = end_time_count(start_time);

	std::cout << "Posortowana tablica (czas: " << time << "): ";
	print_array(tab);

	std::cout << "Mieszanie...";
	std::shuffle(&tab[0], &tab[arr_size], generator);

	std::cout << "\n";
	std::cout << "Nasza tablica: ";
	print_array(tab);
	std::cout << "Sortowanie przez scalanie" << "\n";

	start_time = begin_time_count();
	merge_sort(0, arr_size - 1);
	time = end_time_count(start_time);

	std::cout << "Posortowana tablica (czas: " << time << "): ";
	print_array(tab);



	std::cout << std::endl;
}

