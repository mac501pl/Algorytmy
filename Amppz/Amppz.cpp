#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include "Sort.h"
#include "BST.h"
#include "LinkedList.h"

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

void bst()
{
	BST bst;
	bst.run();
}

void linkedList()
{
	LinkedList linkedList;
	linkedList.run();
}

int getInput()
{
	int choice;
	std::cin >> choice;
	return choice;
}

void displayMainMenu() {
	cout << "Wybierz program" << "\n";
	cout << "1. Stos" << "\n";
	cout << "2. Kolejka" << "\n";
	cout << "3. Sortowanie" << "\n";
	cout << "4. Drzewo BST" << "\n";
	cout << "5. Lista laczona" << "\n";
	cout << "9. Wyjdz" << "\n";
	cout << "Wybor: ";
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
		case 4:
			bst();
			break;
		case 5:
			linkedList();
			break;
		default:
			break;
		}
	} while (choice != 9);
}
