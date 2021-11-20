#include "StackInit.h"
#include "Stack.h"
#include <ctime>
#include <iostream>
void StackInit(Stack*& head)
{
	int i;
	int element;
	for (i = 1; i < 6; i++)
	{
		element = rand() % 100 - 50;
		Push(head, element);
	}
}