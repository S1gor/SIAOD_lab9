#include <iostream>
#include "AVL.h"

using namespace std;

/*������� ���� ������� � ��������� �������� �����. ��������� � ����������� ������
�������� ���������������� �������� ������ ������ � ���������� ����� ��������� �������.*/

int main()
{
	AVL a;

	char filename[] = "1.txt";
	int numberValues = 8;
	int numberSearchValues = 3;

	a.readFile(filename, numberValues, numberSearchValues);

	return 0;
}