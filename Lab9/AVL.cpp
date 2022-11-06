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

void AVL::search(int x)
{
	if (searchUntil(root, x)) cout << "There is a number " << x << endl;
	else cout << "There is no number " << x << endl;
}

void AVL::print()
{
	printUntil(root);
	cout << endl;
}

void AVL::readFile(const char* filename, int numberValues, int numberSearchValues)
{
	FILE* file;
	if (fopen_s(&file, filename, "r") != NULL)
	{
		cout << "Couldn't open the file " << filename << endl;
		exit(1);
	}

	int mas[100];
	for (int i = 0; i < numberValues; i++)
	{
		fscanf_s(file, "%d", &mas[i]);
		insert(mas[i]);
	}
	print();
	for (int i = 0; i < numberSearchValues; i++)
	{
		fscanf_s(file, "%d", &mas[i]);
		search(mas[i]);
	}

	fclose(file);
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
	cout << head->data << " ";
	printUntil(head->right);
}

AVL::node* AVL::insertUntil(node* head, int x)
{
	if (head == NULL)
	{
		head = new node;
		head->data = x;
		head->height = 0;
		head->left = head->right = NULL;
		return head;
	}
	if (x < head->data)				head->left = insertUntil(head->left, x);
	else if (x > head->data)		head->right = insertUntil(head->right, x);
	head->height = height(head->left) > height(head->right) ? 1 + height(head->left) : 1 + height(head->right);
	
	int balance = height(head->left) - height(head->right);
	if (balance > 1)
	{
		if (x < head->left->data) return rightRotation(head);
		else
		{
			head->left = leftRotation(head->left);
			return rightRotation(head);
		}
	}
	else if (balance < -1)
	{
		if (x > head->right->data)	return leftRotation(head);
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
	if (head == NULL)			return 0;
	if (x < head->data)			head->left = removeUntil(head->left, x);
	else if (x > head->data)	head->right = removeUntil(head->right, x);
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
			head->data = r->data;
			head->right = removeUntil(head->right, r->data);
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
	int k = head->data;
	if (k == x)		return head;
	if (k > x)		return searchUntil(head->left, x);
	if (k < x)		return searchUntil(head->right, x);
}