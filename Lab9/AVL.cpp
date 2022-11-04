#include "AVL.h"
#include <iostream>

using namespace std;

void AVL::insert(int x)
{
	root = insertUntil(root, x);
}

void AVL::remove(int x)
{
	root = removeUntil(root, x);
}

AVL::node* AVL::search(int x)
{
	return searchUntil(root, x);
}

void AVL::print()
{
	printUntil(root);
	cout << endl;
}

int AVL::height(node* head)
{
	if (head == NULL) return 0;
	return head->height;
}

AVL::node* AVL::rightRotation(node* head)
{
	node* new_head = head->left;
	head->left = new_head->right;
	new_head->right = head;
	head->height = height(head->left) > height(head->right) ? 1 + height(head->left) : 1 + height(head->right);
	new_head->height = height(new_head->left) > height(new_head->right) ? 1 + height(new_head->left) : 1 + height(new_head->right);
	return new_head;
}

AVL::node* AVL::leftRotation(node* head)
{
	node* new_head = head->right;
	head->right = new_head->left;
	new_head->left = head;
	head->height = height(head->left) > height(head->right) ? 1 + height(head->left) : 1 + height(head->right);
	new_head->height = height(new_head->left) > height(new_head->right) ? 1 + height(new_head->left) : 1 + height(new_head->right);
	return new_head;
}

void AVL::printUntil(node* head)
{
	if (head == NULL)	return;
	printUntil(head->left);
	cout << head->key << " ";
	printUntil(head->right);
}

AVL::node* AVL::insertUntil(node* head, int x)
{
	if (head == NULL)
	{
		n++;
		node* tmp = new node(x);
		return tmp;
	}
	if (x < head->key)			head->left = insertUntil(head->left, x);
	else if (x > head->key)		head->right = insertUntil(head->right, x);
	head->height = height(head->left) > height(head->right) ? 1 + height(head->left) : 1 + height(head->right);
	
	int balance = height(head->left) - height(head->right);
	if (balance > 1)
	{
		if (x < head->left->key) return rightRotation(head);
		else
		{
			head->left = leftRotation(head->left);
			return rightRotation(head);
		}
	}
	else if (balance < -1)
	{
		if (x > head->right->key)	return leftRotation(head);
		else
		{
			head->right = rightRotation(head->right);
			return leftRotation(head);
		}
	}
	return head;
}

AVL::node* AVL::removeUntil(node* head, int x)
{
	if (head == NULL)		return NULL;
	if (x < head->key)		head->left = removeUntil(head->left, x);
	else if (x > head->key)	head->right = removeUntil(head->right, x);
	else
	{
		node* r = head->right;
		if (head->right == NULL)
		{
			node* l = head->left;
			delete(head);
			head = l;
		}
		else if (head->left == NULL)
		{
			delete(head);
			head = r;
		}
		else
		{
			while (r->left != NULL) r = r->left;
			head->key = r->key;
			head->right = removeUntil(head->right, r->key);
		}
	}

	if (head == NULL)	return head;
	head->height = height(head->left) > height(head->right) ? 1 + height(head->left) : 1 + height(head->right);
	
	int balance = height(head->left) - height(head->right);
	if (balance > 1)
	{
		if (height(head->left) >= height(head->right))	return rightRotation(head);
		else
		{
			head->left = leftRotation(head->left);
			return rightRotation(head);
		}
	}
	else if (balance < -1)
	{
		if (height(head->right) >= height(head->left))	return leftRotation(head);
		else
		{
			head->right = rightRotation(head->right);
			return leftRotation(head);
		}
	}
	return head;
}

AVL::node* AVL::searchUntil(node* head, int x)
{
	if (head == NULL)	return NULL;
	int k = head->key;
	if (k == x)		return head;
	if (k > x)		return searchUntil(head->left, x);
	if (k < x)		return searchUntil(head->right, x);
}