#pragma once
struct Stack
{
	int element;
	Stack* next;
};
void StackInit(Stack*& head);