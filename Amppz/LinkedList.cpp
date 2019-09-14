#include "LinkedList.h"

LinkedList::LinkedList() = default;

void LinkedList::insertToTheBeginning(int x, linkedListNode*& beginning)
{
	auto* newElem = new linkedListNode;
	newElem->data = x;
	newElem->next = nullptr;
	if (!isEmpty(beginning))
	{
		newElem->next = beginning;
	}
	beginning = newElem;
}

void LinkedList::removeFromTheBeginning(linkedListNode*& beginning)	//jak zwolnic pamiec?
{
	beginning = beginning->next;
}

void LinkedList::insertToIndex(int index, int x, linkedListNode*& beginning)	// 0 - poczatek
{
	if (index < 0 || index > size(beginning))
	{
		throw std::out_of_range::out_of_range("Niepoprawny indeks");
	}
	auto* newElem = new linkedListNode;
	auto* temp = beginning;
	newElem->data = x;
	for (int i = 0; i < index; i++)
	{
		temp = temp->next;
	}
	newElem->next = temp->next;
	temp->next = newElem;
	delete temp;
}

void LinkedList::removeFromIndex(int index, linkedListNode*& beginning)
{
	if (index < 0 || index > size(beginning))
	{
		throw std::out_of_range::out_of_range("Niepoprawny indeks");
	}
	if (index == 0)
	{
		removeFromTheBeginning(beginning);
		return;
	}
	if (index == size(beginning))
	{
		// TODO
		return;
	}

	auto* temp = beginning;
	for (int i = 0; i < index - 1; i++)
	{
		temp = temp->next;
	}
	temp->next = temp->next->next;
}

void LinkedList::print(linkedListNode* temp)
{
	while (temp)
	{
		std::cout << temp->data << " ";
		temp = temp->next;
	}
	std::cout << "\n";
}

bool LinkedList::search(int x, linkedListNode*& beginning)
{
	return true;
}

int LinkedList::peekFromIndex(int index, linkedListNode* beginning)
{
	if (index < 0 || index > size(beginning))
	{
		throw std::out_of_range::out_of_range("Niepoprawny indeks");
	}
	for (int i = 0; i < index; i++)
	{
		beginning = beginning->next;
	}
	return beginning->data;
}

bool LinkedList::isEmpty(linkedListNode* node)
{
	return node == nullptr;
}

int LinkedList::size(linkedListNode* head)
{
	int size = 0;
	for (auto* temp = head; temp; temp = temp->next, size++);
	return size;
}

void LinkedList::run()
{
	// w mojej implementacji glowa listy tez ma wartosc, poprawniej by bylo gdyby nie miala
	// to ogolnie moze byc zle XD
	// i w ogole nie czyszcze pamieci wiec to tez nieladnie

	linkedListNode* myList = nullptr;
	insertToTheBeginning(5, myList);
	insertToTheBeginning(4, myList);
	insertToTheBeginning(3, myList);
	insertToTheBeginning(2, myList);
	insertToTheBeginning(1, myList);
	print(myList);
	std::cout << peekFromIndex(4, myList) << "\n";
	std::cout << peekFromIndex(3, myList) << "\n";
	std::cout << peekFromIndex(2, myList) << "\n";
	std::cout << peekFromIndex(1, myList) << "\n";
	std::cout << peekFromIndex(0, myList) << "\n";
	std::cout << std::endl;
}
