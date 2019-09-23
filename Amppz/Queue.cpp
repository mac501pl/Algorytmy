#include "Queue.h"

void Queue::add(queueElem*& beginning, queueElem*& end, int x)
{
	auto* newElem = new queueElem;
	newElem->data = x;
	if (beginning != nullptr)
	{
		end->next = newElem;
		end = newElem;
	}
	else
	{
		end = newElem;
		beginning = newElem;
	}
}

int Queue::next(queueElem*& beginning, queueElem*& end)
{
	if (beginning != nullptr)
	{
		int result = beginning->data;
		if (beginning == end)
		{
			end = nullptr;
			beginning = nullptr;
		}
		else
		{
			beginning = beginning->next;
		}
		return result;
	}
		throw std::runtime_error::runtime_error("Blad");
}

int Queue::peek(queueElem* beginning)
{
	return beginning->data;
}

bool Queue::isEmpty(queueElem* beginning)
{
	return beginning == nullptr;
}

void Queue::run()
{
	queueElem* myQueue = nullptr;
	queueElem* endOfMyQueue = nullptr;

	cout << "Czy kolejka jest pusta? (spodziewamy sie 1): " << isEmpty(myQueue) << "\n";

	cout << "Umieszczam w kolejce kilka elementow: ";
	add(myQueue, endOfMyQueue, 7);	cout << "(7) ";
	add(myQueue, endOfMyQueue, 29);	cout << "(29) ";
	add(myQueue, endOfMyQueue, 11);	cout << "(11) ";
	cout << "\n";

	cout << "Czy kolejka jest pusta? (spodziewamy sie 0): " << isEmpty(myQueue) << "\n";

	cout << "Sprawdzam, co jest na poczatku kolejki: (spodziewamy sie 7): " << peek(myQueue) << "\n";
	cout << "Ponownie sprawdzam, co jest na poczatku kolejki: (spodziewamy sie 7): " << peek(myQueue) << "\n";

	cout << "Pobieram element z kolejki: (spodziewamy sie 7): " << next(myQueue, endOfMyQueue) << "\n";

	cout << "Umieszczam element w kolejce: ";
	add(myQueue, endOfMyQueue, 3);	cout << "(3) ";
	cout << "\n";

	cout << "Pobieram kolejne elementy z kolejki (spodziewamy sie 29 11 3): ";
	cout << next(myQueue, endOfMyQueue) << " ";
	cout << next(myQueue, endOfMyQueue) << " ";
	cout << next(myQueue, endOfMyQueue) << " ";
	cout << "\n";

	cout << "Czy kolejka jest pusta? (spodziewamy sie 1): " << isEmpty(myQueue) << "\n";

	cout << "Umieszczam elementy w kolejce: ";
	add(myQueue, endOfMyQueue, 78);		cout << "(78) ";
	add(myQueue, endOfMyQueue, 52);		cout << "(52) ";
	add(myQueue, endOfMyQueue, 110);	cout << "(110) ";
	add(myQueue, endOfMyQueue, 47);		cout << "(47) ";
	add(myQueue, endOfMyQueue, 9);		cout << "(9) ";
	cout << "\n";

	cout << "Pobieram kolejne elementy z kolejki az bedzie pusta: (spodziewamy sie 78 52 110 47 9): ";
	while (!isEmpty(myQueue))
	{
		cout << next(myQueue, endOfMyQueue) << " ";
	}
	cout << "\n";

	cout << "Czy kolejka jest pusta? (spodziewamy sie 1): " << isEmpty(myQueue) << "\n";

	cout << "Pobieram element z pustej kolejki: ";
	try
	{
		cout << next(myQueue, endOfMyQueue) << "\n";
		cout << "Pobranie elementu z pustej kolejki nie rzucilo bledu!" << "\n";
	}
	catch (std::runtime_error)
	{
		cout << "Pobranie elementu z pustej kolejki rzucilo blad!" << "\n";
	}

	cout << std::endl;
}