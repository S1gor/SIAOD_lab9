#include <iostream>
#include "AVL.h"

using namespace std;

/*Имеется файл записей с некоторым ключевым полем. Построить в оперативной памяти
идеально сбалансированное бинарное дерево поиска и обеспечить поиск указанных записей.*/

int main()
{
	AVL a;

	char filename[] = "1.txt";
	int numberValues = 8;
	int numberSearchValues = 3;

	a.readFile(filename, numberValues, numberSearchValues);

	return 0;
}