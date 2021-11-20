#include <iostream>
#include "StackInit.h"
void DeleteStack(Stack*& head)
{
	Stack* del = new Stack;
	del = head;
	while (del->next != nullptr)
	{
		head = head->next;
		delete del;
		del = head;
	}
	delete del;
}

void Push(Stack*& head, int element)
{
	Stack* temp = new Stack;
	temp->element = element;
	temp->next = head;
	head = temp;
}
void Pop(Stack*& head, int& element)
{
	element = head->element;
	Stack* elemPop = new Stack;
	elemPop = head;
	head = head->next;
	delete elemPop;
}
