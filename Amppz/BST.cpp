#include "BST.h"

BST::BST()
{
	root = nullptr;
	std::cout << "Podaj ilosc elementow drzewa: ";
	std::cin >> tree_size;
}

void BST::insert(int x)
{
	auto* newNode = new bstNode;
	newNode->data = x;
	newNode->left = nullptr;
	newNode->right = nullptr;

	bstNode* current = nullptr;
	bstNode* parent;

	if (root == nullptr)
	{
		root = newNode;
	}
	else
	{
		current = root;
		parent = nullptr;
		while (true)
		{
			parent = current;
			if (x < parent->data)
			{
				current = current->left;
				if (current == nullptr)
				{
					parent->left = newNode;
					return;
				}
			}
			else
			{
				current = current->right;
				if (current == nullptr)
				{
					parent->right = newNode;
					return;
				}
			}
		}
	}
}

bstNode* BST::search(int x)
{
	if (root == nullptr)
	{
		throw std::runtime_error::runtime_error("Puste drzewo");
	}
	bstNode* current = root;

	std::cout << "Przechodze przez elementy: ";

	while (current->data != x)
	{
		if (current != nullptr)
		{
			std::cout << current->data << " ";
		}
		if (x < current->data)
		{
			current = current->left;
		}
		else
		{
			current = current->right;
		}
		if (current == nullptr)
		{
			std::cout << "\n";
			return nullptr;
		}
	}
	std::cout << "\n";
	return current;
}

void BST::pre_order_traversal(bstNode* rootPtr)
{
	if (rootPtr != nullptr)
	{
		std::cout << rootPtr->data << " ";
		pre_order_traversal(rootPtr->left);
		pre_order_traversal(rootPtr->right);
	}
}

void BST::in_order_traversal(bstNode* rootPtr)
{
	if (rootPtr != nullptr)
	{
		in_order_traversal(rootPtr->left);
		std::cout << rootPtr->data << " ";
		in_order_traversal(rootPtr->right);
	}
}

void BST::post_order_traversal(bstNode* rootPtr)
{
	if (rootPtr != nullptr)
	{
		post_order_traversal(rootPtr->left);
		post_order_traversal(rootPtr->right);
		std::cout << rootPtr->data << " ";
	}
}

void BST::run()
{
	std::vector<int> numbers;
	for (int i = 1; i <= tree_size; i++)
	{
		numbers.push_back(i);
	}
	std::random_device rd;
	std::mt19937 generator(rd());
	std::shuffle(numbers.begin(), numbers.end(), generator);

	std::cout << "Wypelniam drzewo liczbami: ";

	for (int number : numbers)
	{
		insert(number);
		std::cout << number << " ";
	}
	std::cout << "\n";

	int i = rand() % tree_size + 1;
	std::cout << "Szukam elementu: " << i << "\n";
	bstNode* temp = search(i);

	if (temp != nullptr)
	{
		std::cout << "Znaleziono element: " << temp->data << "\n";
	}
	else
	{
		std::cout << "Nie znaleziono elementu: " << i << "\n";
	}

	std::cout << "Przejscie po drzewie w kolejnosci preorder: ";
	pre_order_traversal(root);
	std::cout << "\n";

	std::cout << "Przejscie po drzewie w kolejnosci inorder: ";
	in_order_traversal(root);
	std::cout << "\n";

	std::cout << "Przejscie po drzewie w kolejnosci postorder: ";
	post_order_traversal(root);
	std::cout << std::endl;
}