#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include "Sort.h"

void stack() {
	Stack stack;
	stack.run();
}

void queue() {
	Queue queue;
	queue.run();
}

void sort()
{
	Sort sort;
	sort.run();
}

int getInput()
{
	int choice;
	std::cin >> choice;
	return choice;
}

void displayMainMenu() {
	std::cout << "Wybierz program" << "\n";
	std::cout << "1. Stos" << "\n";
	std::cout << "2. Kolejka" << "\n";
	std::cout << "3. Sortowanie" << "\n";
	std::cout << "9. Wyjdz" << "\n";
	std::cout << "Wybor: ";
}

int main()
{
	int choice;
	do {
		displayMainMenu();
		choice = getInput();
		switch (choice)
		{
		case 1:
			stack();
			break;
		case 2:
			queue();
			break;
		case 3:
			sort();
			break;
		default:
			break;
		}
	} while (choice != 9);
}
