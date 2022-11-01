#pragma once

class AVL
{
public:
	class node
	{
		int key;
		int height;
		node* left;
		node* right;
		node(int key)
		{
			this->key = key;
			height = 1;
			left = nullptr;
			right = nullptr;
		}
	};

	node* root = nullptr;
	int n;

	void insert(int x);
	void remove(int x);
	node* search(int x);
	void print(int x);

private:



};

