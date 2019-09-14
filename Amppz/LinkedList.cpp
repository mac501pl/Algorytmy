#include "LinkedList.h"

LinkedList::LinkedList() = default;

void LinkedList::insertToTheBeginning(int x, linkedListNode*& head)
{
	auto* newElem = new linkedListNode;
	newElem->data = x;
	newElem->next = nullptr;
	if (!isEmpty(head))
	{
		newElem->next = head;
	}
	head = newElem;
}

void LinkedList::removeFromTheBeginning(linkedListNode*& head)
{
	if (isEmpty(head))
	{
		throw std::runtime_error::runtime_error("Pusta lista");
	}
	head = head->next;
}

void LinkedList::insertToIndex(int index, int x, linkedListNode*& head)
{
	if (index < 0 || index > size(head))
	{
		throw std::out_of_range::out_of_range("Niepoprawny indeks");
	}
	if (index == 0)
	{
		insertToTheBeginning(x, head);
		return;
	}
	auto* newElem = new linkedListNode;
	newElem->data = x;
	newElem->next = nullptr;
	auto* temp = head;
	for (int i = 0; i < index - 1; i++)
	{
		temp = temp->next;
	}
	newElem->next = temp->next;
	temp->next = newElem;
}

void LinkedList::removeFromIndex(int index, linkedListNode*& head)
{
	if (index < 0 || index > size(head))
	{
		throw std::out_of_range::out_of_range("Niepoprawny indeks");
	}
	if (index == 0)
	{
		removeFromTheBeginning(head);
		return;
	}
	auto* temp = head;
	for (int i = 0; i < index - 1; i++)
	{
		temp = temp->next;
	}
	temp->next = temp->next->next;
}

void LinkedList::print(linkedListNode* temp)
{
	while (!isEmpty(temp))
	{
		std::cout << temp->data << " ";
		temp = temp->next;
	}
	std::cout << "\n";
}

bool LinkedList::search(int x, linkedListNode* head)
{
	while (!isEmpty(head))
	{
		if (head->data == x)
		{
			return true;
		}
		head = head->next;
	}
	return false;
}

int LinkedList::peekFromIndex(int index, linkedListNode* head)
{
	if (index < 0 || index > size(head))
	{
		throw std::out_of_range::out_of_range("Niepoprawny indeks");
	}
	for (int i = 0; i < index; i++)
	{
		head = head->next;
	}
	return head->data;
}

bool LinkedList::isEmpty(linkedListNode* node)
{
	return node == nullptr;
}

int LinkedList::size(linkedListNode* head)
{
	int size = 0;
	for (auto* temp = head; temp != nullptr; temp = temp->next, size++)
	{
		;
	}
	return size;
}

void LinkedList::run()
{
	// w mojej implementacji glowa listy tez ma wartosc, poprawniej by bylo gdyby nie miala
	// nie gwarantuje ze wszystko tu jest poprawnie bo nie mialem materialu referencyjnego

	linkedListNode* myList = nullptr;

	// TODO 

	std::cout << std::endl;
}
