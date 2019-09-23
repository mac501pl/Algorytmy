#include "Stack.h"

void Stack::push(stackElem*& current_top_of_the_stack, int x) {
	auto* newElem = new stackElem;
	newElem->data = x;
	newElem->next = current_top_of_the_stack;
	current_top_of_the_stack = newElem;
}

int Stack::pop(stackElem*& current_top_of_the_stack) {
	if (current_top_of_the_stack != nullptr) {
		int result = current_top_of_the_stack->data;
		current_top_of_the_stack = current_top_of_the_stack->next;
		return result;
	}
	throw std::runtime_error::runtime_error("Pusty stos");
}

int Stack::peek(stackElem* current_top_of_the_stack) {
	return current_top_of_the_stack->data;
}

bool Stack::isEmpty(stackElem* current_top_of_the_stack) {
	return current_top_of_the_stack == nullptr;
}

void Stack::run() {
	stackElem* myStack = nullptr;

	cout << "Czy stos jest pusty? (spodziewamy sie 1): " << isEmpty(myStack) << "\n";

	cout << "Umieszczam na stosie kilka elementow: ";
	push(myStack, 7);	cout << "(7) ";
	push(myStack, 29);	cout << "(29) ";
	push(myStack, 11);	cout << "(11) ";
	cout << "\n";

	cout << "Czy stos jest pusty? (spodziewamy sie 0): " << isEmpty(myStack) << "\n";

	cout << "Sprawdzam, co jest na wierzchu stosu (spodziewamy sie 11): " << peek(myStack) << "\n";
	cout << "Ponownie sprawdzam, co jest na wierzchu stosu (spodziewamy sie 11): " << peek(myStack) << "\n";

	cout << "Pobieram element z wierzchu stosu (spodziewamy sie 11): " << pop(myStack) << "\n";

	cout << "Umieszczam element na stosie: ";
	push(myStack, 3);	cout << "(3) ";
	cout << "\n";

	cout << "Pobieram kolejne elementy ze stosu (spodziewamy sie 3 29 7): ";
	cout << pop(myStack) << " ";
	cout << pop(myStack) << " ";
	cout << pop(myStack) << " ";
	cout << "\n";

	cout << "Czy stos jest pusty? (spodziewamy sie 1): " << isEmpty(myStack) << "\n";

	cout << "Umieszczam elementy na stosie: ";
	push(myStack, 78);	cout << "(78) ";
	push(myStack, 52);	cout << "(52) ";
	push(myStack, 110);	cout << "(110) ";
	push(myStack, 47);	cout << "(47) ";
	push(myStack, 9);	cout << "(9) ";
	cout << "\n";

	cout << "Pobieram kolejne elementy ze stosu az bedzie pusty (spodziewamy sie 9 47 110 52 78): ";
	while (!isEmpty(myStack)) {
		cout << pop(myStack) << " ";
	}
	cout << "\n";

	cout << "Czy stos jest pusty? (spodziewamy sie 1): " << isEmpty(myStack) << "\n";
	cout << "Pobieram element z pustego stosu: ";
	try {
		cout << pop(myStack) << "\n";
		cout << "Pobranie elementu z pustego stosu nie rzucilo bledu!" << "\n";
	}
	catch (std::runtime_error) {
		cout << "Pobranie elementu z pustego stosu rzucilo blad!" << "\n";
	}
	cout << std::endl;
}