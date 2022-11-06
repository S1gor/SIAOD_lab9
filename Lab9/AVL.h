#pragma once

class AVL
{
public:
	struct node
	{
		int data;
		node* left = nullptr;
		node* right = nullptr;
		int height;
	};

	node* root = nullptr;

	void insert(int x);
	void remove(int x);
	void search(int x);
	void print();

	void readFile(const char* filename, int numberValues, int numberSearchValues);
private:
	int height(node* head);

	node* rightRotation(node* head);
	node* leftRotation(node* head);

	void printUntil(node* head);
	node* insertUntil(node* head, int x);
	node* removeUntil(node* head, int x);
	node* searchUntil(node* head, int x);
};