#include <iostream>
#include "AVL.h"

using namespace std;

/*Имеется файл записей с некоторым ключевым полем. Построить в оперативной памяти
идеально сбалансированное бинарное дерево поиска и обеспечить поиск указанных записей.*/

int main()
{
	AVL a;

	char filename[] = "1.txt";

	a.readFile(filename, 8, 3);
	a.print();

	for (int i = 0; i < 3; i++)
		a.search(a.s[i]);

	return 0;
}