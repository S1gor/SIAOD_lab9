#include <iostream>
#include "AVL.h"

using namespace std;

/*Имеется файл записей с некоторым ключевым полем. Построить в оперативной памяти
идеально сбалансированное бинарное дерево поиска и обеспечить поиск указанных записей.*/

void readFile(const char* filename, AVL& a, int size)
{
	FILE* file;
	if (fopen_s(&file, filename, "r") != NULL)
	{
		cout << "Couldn't open the file " << filename << endl;
		exit(1);
	}

	int mas[100];
	for (int i = 0; i < size; i++)
	{
		fscanf_s(file, "%d", &mas[i]);
		a.insert(mas[i]);
	}

	fclose(file);
}

int main()
{
	AVL a;

	char filename[] = "1.txt";
	readFile(filename, a, 8);

	a.print();

	return 0;
}