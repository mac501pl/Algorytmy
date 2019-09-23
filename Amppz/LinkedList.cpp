#include "LinkedList.h"

LinkedList::LinkedList() = default;

void LinkedList::insertToTheBeginning(const int x, linkedListNode*& head) const
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

void LinkedList::removeFromTheBeginning(linkedListNode*& head) const
{
	if (isEmpty(head))
	{
		throw std::runtime_error::runtime_error("Pusta lista");
	}
	auto* old = head;
	head = head->next;
	delete old;
}

void LinkedList::insertToIndex(const int index, const int x, linkedListNode*& head) const
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

void LinkedList::removeFromIndex(const int index, linkedListNode*& head) const
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
	auto* old = temp->next;
	temp->next = temp->next->next;
	delete old;
}

void LinkedList::print(const linkedListNode* temp) const
{
	while (!isEmpty(temp))
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
}

bool LinkedList::search(const int x, const linkedListNode* head) const
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

int LinkedList::peekFromIndex(const int index, const linkedListNode* head) const
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

bool LinkedList::isEmpty(const linkedListNode* node) const
{
	return node == nullptr;
}

int LinkedList::size(const linkedListNode* head) const
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

	cout << "Czy lista jest pusta? (spodziewamy sie 1): " << isEmpty(myList) << "\n";

	cout << "Umieszczam kilka elementow na poczatek listy: ";
	insertToTheBeginning(7, myList);	cout << "(7) ";
	insertToTheBeginning(29, myList);	cout << "(29) ";
	insertToTheBeginning(11, myList);	cout << "(11) ";
	cout << "\n";

	cout << "Czy lista jest pusta? (spodziewamy sie 0): " << isEmpty(myList) << "\n";

	cout << "Sprawdzam, co jest na wierzchu listy (spodziewamy sie 11): " << peekFromIndex(0, myList) << "\n";
	cout << "Teraz, sprawdzam, co jest na drugiej pozycji (spodziewamy sie 29): " << peekFromIndex(1, myList) << "\n";

	cout << "Umieszczam elemnt na 2 pozycji listy: ";
	insertToIndex(1, 33, myList);	cout << "(33)";
	cout << "\n";

	cout << "Sprawdzam jak wyglada cala lista (spodziewamy sie 11 33 29 7): ";
	print(myList);
	cout << "\n";

	cout << "Sprawdzam wielkosc listy (spodziewamy sie 4): " << size(myList);
	cout << "\n";

	cout << "Usuwam poczatek listy";
	removeFromTheBeginning(myList);
	cout << "\n";

	cout << "Ponownie sprawdzam jak wyglada cala lista (spodziewamy sie 33 29 7): ";
	print(myList);
	cout << "\n";

	cout << "Czy lista jest pusta? (spodziewamy sie 0): " << isEmpty(myList) << "\n";

	cout << "Czy w liscie znajduje sie wartosc 7? (spodziewamy sie 1): " << search(7, myList) << "\n";
	cout << "Czy w liscie znajduje sie wartosc 15? (spodziewamy sie 0): " << search(15, myList) << "\n";

	cout << "Usuwam 3 pozycje z listy";
	removeFromIndex(2, myList);
	cout << "\n";

	cout << "Sprawdzam jak wyglada cala lista (spodziewamy sie 33 29): ";
	print(myList);
	cout << "\n";

	cout << "Sprawdzam wielkosc listy (spodziewamy sie 2): " << size(myList) << "\n";

	cout << "Usuwam liste az bedzie pusta";
	while (!isEmpty(myList))
	{
		removeFromTheBeginning(myList);
	}
	cout << "\n";

	cout << "Czy lista jest pusta? (spodziewamy sie 1): " << isEmpty(myList) << "\n";

	cout << "Dodaje element na poczatek listy: ";
	insertToIndex(0, 17, myList);	cout << "(17)";
	cout << "\n";

	cout << "Sprawdzam jak wyglada lista (spodziewamy sie 17): ";
	print(myList);
	cout << "\n";

	cout << "Usuwam element z poczatku listy";
	removeFromIndex(0, myList);
	cout << "\n";

	cout << "Czy lista jest pusta? (spodziewamy sie 1): " << isEmpty(myList) << "\n";

	cout << "Usuwam element z pustej listy: ";
	try
	{
		removeFromTheBeginning(myList);
		cout << "Usuwanie elementu z pustej listy nie rzucilo bledu!";
		cout << "\n";
	}
	catch (std::runtime_error)
	{
		cout << "Usuwanie elementu z pustej listy rzucilo blad!";
		cout << "\n";
	}

	cout << "Wrzucam element na 99 pozycje listy: ";
	try
	{
		insertToIndex(99, 11, myList);	cout << "(11)";
		cout << "\n";
	}
	catch (std::out_of_range)
	{
		cout << "Wrzucanie elementu na indeks wiekszy od wielkosci listy rzucio blad!";
		cout << "\n";
	}

	cout << std::endl;
}
