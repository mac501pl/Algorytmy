#include "Stack.h"

void Stack::push(elem* current_top_of_the_stack, int x) {
	elem* newElem = new elem;
	newElem->data = x;
	newElem->next = current_top_of_the_stack;
	current_top_of_the_stack = newElem;
}

int Stack::pop(elem* current_top_of_the_stack) {
	if (current_top_of_the_stack) {
		int result = current_top_of_the_stack->data;
		current_top_of_the_stack = current_top_of_the_stack->next;
		return result;
	}
	throw std::runtime_error::runtime_error("Blad");
}

int Stack::peek(elem* current_top_of_the_stack) {
	return current_top_of_the_stack->data;
}

bool Stack::isEmpty(elem* current_top_of_the_stack) {
	if (!current_top_of_the_stack)
		return true;
	else
		return false;
}

void Stack::run() {
	elem* myStack = nullptr;

	std::cout << "Czy stos jest pusty? (spodziewamy sie 1): " << isEmpty(myStack) << "\n";

	std::cout << "Umieszczam na stosie kilka elementow: ";
	push(myStack, 7);	std::cout << "(7) ";
	push(myStack, 29);	std::cout << "(29) ";
	push(myStack, 11);	std::cout << "(11) ";
	std::cout << "\n";

	std::cout << "Czy stos jest pusty? (spodziewamy sie 0): " << isEmpty(myStack) << "\n";

	std::cout << "Sprawdzam, co jest na wierzchu stosu (spodziewamy sie 11): " << peek(myStack) << "\n";
	std::cout << "Ponownie sprawdzam, co jest na wierzchu stosu (spodziewamy sie 11): " << peek(myStack) << "\n";

	std::cout << "Pobieram element z wierzchu stosu (spodziewamy sie 11): " << pop(myStack) << "\n";

	std::cout << "Umieszczam element na stosie: ";
	push(myStack, 3);	std::cout << "(3) ";
	std::cout << "\n";

	std::cout << "Pobieram kolejne elementy ze stosu (spodziewamy sie 3 29 7): ";
	std::cout << pop(myStack) << " ";
	std::cout << pop(myStack) << " ";
	std::cout << pop(myStack) << " ";
	std::cout << "\n";

	std::cout << "Czy stos jest pusty? (spodziewamy sie 1): " << isEmpty(myStack) << "\n";

	std::cout << "Umieszczam elementy na stosie: ";
	push(myStack, 78);	std::cout << "(78) ";
	push(myStack, 52);	std::cout << "(52) ";
	push(myStack, 110);	std::cout << "(110) ";
	push(myStack, 47);	std::cout << "(47) ";
	push(myStack, 9);	std::cout << "(9) ";
	std::cout << "\n";

	std::cout << "Pobieram kolejne elementy ze stosu az bedzie pusty (spodziewamy sie 9 47 110 52 78): ";
	while (!isEmpty(myStack)) {
		std::cout << pop(myStack) << " ";
	}
	std::cout << "\n";

	std::cout << "Czy stos jest pusty? (spodziewamy sie 1): " << isEmpty(myStack) << "\n";
	std::cout << "Pobieram element z pustego stosu: ";
	try {
		std::cout << pop(myStack) << "\n";
		std::cout << "Pobranie elementu z pustego stosu nie rzucilo bledu!" << "\n";
	}
	catch (std::runtime_error) {
		std::cout << "Pobranie elementu z pustego stosu rzucilo blad!" << "\n";
	}
	std::cout << std::endl;
}