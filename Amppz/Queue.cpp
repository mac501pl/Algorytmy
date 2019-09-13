#include "Queue.h"

void Queue::add(queueElem*& beginning, queueElem*& end, int x)
{
	queueElem* newElem = new queueElem;
	newElem->data = x;
	if (beginning)
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
	if (beginning)
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
	else
	{
		throw std::runtime_error::runtime_error("Blad");
	}
}

int Queue::peek(queueElem* beginning)
{
	return beginning->data;
}

bool Queue::isEmpty(queueElem* beginning)
{
	if (!beginning)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Queue::run()
{
	queueElem* myQueue = nullptr;
	queueElem* endOfMyQueue = nullptr;

	std::cout << "Czy kolejka jest pusta? (spodziewamy sie 1): " << isEmpty(myQueue) << "\n";

	std::cout << "Umieszczam w kolejce kilka elementow: ";
	add(myQueue, endOfMyQueue, 7);	std::cout << "(7) ";
	add(myQueue, endOfMyQueue, 29);	std::cout << "(29) ";
	add(myQueue, endOfMyQueue, 11);	std::cout << "(11) ";
	std::cout << "\n";

	std::cout << "Czy kolejka jest pusta? (spodziewamy sie 0): " << isEmpty(myQueue) << "\n";

	std::cout << "Sprawdzam, co jest na poczatku kolejki: (spodziewamy sie 7): " << peek(myQueue) << "\n";
	std::cout << "Ponownie sprawdzam, co jest na poczatku kolejki: (spodziewamy sie 7): " << peek(myQueue) << "\n";

	std::cout << "Pobieram element z kolejki: (spodziewamy sie 7): " << next(myQueue, endOfMyQueue) << "\n";

	std::cout << "Umieszczam element w kolejce: ";
	add(myQueue, endOfMyQueue, 3);	std::cout << "(3) ";
	std::cout << "\n";

	std::cout << "Pobieram kolejne elementy z kolejki (spodziewamy sie 29 11 3): ";
	std::cout << next(myQueue, endOfMyQueue) << " ";
	std::cout << next(myQueue, endOfMyQueue) << " ";
	std::cout << next(myQueue, endOfMyQueue) << " ";
	std::cout << "\n";

	std::cout << "Czy kolejka jest pusta? (spodziewamy sie 1): " << isEmpty(myQueue) << "\n";

	std::cout << "Umieszczam elementy w kolejce: ";
	add(myQueue, endOfMyQueue, 78);		std::cout << "(78) ";
	add(myQueue, endOfMyQueue, 52);		std::cout << "(52) ";
	add(myQueue, endOfMyQueue, 110);	std::cout << "(110) ";
	add(myQueue, endOfMyQueue, 47);		std::cout << "(47) ";
	add(myQueue, endOfMyQueue, 9);		std::cout << "(9) ";
	std::cout << "\n";

	std::cout << "Pobieram kolejne elementy z kolejki az bedzie pusta: (spodziewamy sie 78 52 110 47 9): ";
	while (!isEmpty(myQueue))
	{
		std::cout << next(myQueue, endOfMyQueue) << " ";
	}
	std::cout << "\n";

	std::cout << "Czy kolejka jest pusta? (spodziewamy sie 1): " << isEmpty(myQueue) << "\n";

	std::cout << "Pobieram element z pustej kolejki: ";
	try
	{
		std::cout << next(myQueue, endOfMyQueue) << "\n";
		std::cout << "Pobranie elementu z pustej kolejki nie rzucilo bledu!" << "\n";
	}
	catch (std::runtime_error)
	{
		std::cout << "Pobranie elementu z pustej kolejki rzucilo blad!" << "\n";
	}

	std::cout << std::endl;
}