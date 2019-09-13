#include "BST.h"

BST::BST()
{
	root = nullptr;
	std::cout << "Podaj ilosc elementow drzewa: ";
	std::cin >> tree_size;
}

void BST::insert(int x)
{
	bstNode* newNode = new bstNode;
	newNode->data = x;
	newNode->left = nullptr;
	newNode->right = nullptr;

	bstNode* current = nullptr;
	bstNode* parent;

	if (!root)
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
				if (!current)
				{
					parent->left = newNode;
					return;
				}
			}
			else
			{
				current = current->right;
				if (!current)
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
	if (!root)
	{
		throw std::runtime_error::runtime_error("Puste drzewo");
	}
	bstNode* current = root;

	std::cout << "Przechodze przez elementy: ";

	while (current->data != x)
	{
		if (current)
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
		if (!current)
		{
			std::cout << "\n";
			return nullptr;
		}
	}
	std::cout << "\n";
	return current;
}

void BST::pre_order_traversal(bstNode* root)
{
	if (root)
	{
		std::cout << root->data << " ";
		pre_order_traversal(root->left);
		pre_order_traversal(root->right);
	}
}

void BST::in_order_traversal(bstNode* root)
{
	if (root)
	{
		in_order_traversal(root->left);
		std::cout << root->data << " ";
		in_order_traversal(root->right);
	}
}

void BST::post_order_traversal(bstNode* root)
{
	if (root)
	{
		post_order_traversal(root->left);
		post_order_traversal(root->right);
		std::cout << root->data << " ";
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

	for (int i = 0; i < numbers.size(); i++)
	{
		insert(numbers[i]);
		std::cout << numbers[i] << " ";
	}
	std::cout << "\n";

	int i = rand() % tree_size + 1;
	std::cout << "Szukam elementu: " << i << "\n";
	bstNode* temp = search(i);

	if (temp)
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
	std::cout << "\n";
}