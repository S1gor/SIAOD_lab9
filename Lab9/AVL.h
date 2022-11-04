#pragma once

class AVL
{
public:
	class node
	{
	public:
		int key;
		int height;
		node* left;
		node* right;
		node(int key) : key(key), height(1), left(nullptr), right(nullptr)
		{}
	};

	node* root = nullptr;
	int n;

	void insert(int x);
	void remove(int x);
	node* search(int x);
	void print();

private:
	int height(node* head);

	node* rightRotation(node* head);
	node* leftRotation(node* head);

	void printUntil(node* head);
	node* insertUntil(node* head, int x);
	node* removeUntil(node* head, int x);
	node* searchUntil(node* head, int x);
};