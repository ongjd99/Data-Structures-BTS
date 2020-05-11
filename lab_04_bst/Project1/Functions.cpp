/*
	Ong, Johnny

	April 25, 2020

	CS 200
	Lab 4
*/

#include "BST.h"

using namespace std;

// Definition function insert (non-recursive) 
void BST::insert(int item)
{
	Node* newNode = new Node;
	newNode->data = item;
	if (root == nullptr)
	{
		root = newNode;
	}
	else
	{
		Node* current = root;
		Node* trailing = nullptr;
		bool searching = true;
		while (current != nullptr && searching)
		{
			trailing = current;
			if (item == current->data)
			{
				cout << "The item to insert is already in the list - "
					<< "duplicates are not allowed." << endl;
				searching = false;
			}
			else if (item < current->data)
			{
				current = current->llink;
			}
			else
			{
				current = current->rlink;
			}
		}
		if (item < trailing->data)
		{
			trailing->llink = newNode;
		}
		else
		{
			trailing->rlink = newNode;
		}
	}
}

// Definition function totalNodes
int BST::totalNodes() const
{
	if (root == nullptr)
	{
		return 0;
	}
	else
	{
		return totalNodes(root);
	}
}

// Definition function totalNodes (recursive)
int BST::totalNodes(const Node* p) const
{
	if (p == nullptr)
	{
		return 0;
	}
	else
	{
		return 1 + totalNodes(p->llink) + totalNodes(p->rlink);
	}
}

// Definition overloaded function preorderTraversal
void BST::preorderTraversal() const
{
	if (root == nullptr)
		cerr << "There is no tree.";
	else
	{
		preorderTraversal(root);
	}
}

// Definition overloaded function preorderTraversal (recursive)
void BST::preorderTraversal(const Node* p) const
{
	if (p != nullptr)
	{
		cout << p->data << " ";
		preorderTraversal(p->llink);
		preorderTraversal(p->rlink);
	}
}

// Definition overloaded function postorderTraversal
void BST::postorderTraversal() const
{
	if (root == nullptr)
		cerr << "There is no tree.";
	else
	{
		postorderTraversal(root);
	}
}

// Definition overloaded function postorderTraversal (recursive)
void BST::postorderTraversal(const Node* p) const
{
	if (p != nullptr)
	{
		postorderTraversal(p->llink);
		postorderTraversal(p->rlink);
		cout << p->data << " ";
	}
}
