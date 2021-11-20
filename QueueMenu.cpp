#include "QueueMenu.h"
#include <iostream>
using namespace std;
void QueueInit(RingBuffer* queue)
{
	int i;
	int element;
	cin >> queue->capacyty;
	queue->ringBuffer = new int[queue->capacyty];
	for (i = 0; i < 4; i++)
	{
		element = rand() % 100 - 50;
		InputRing(queue, element);
	}
}

int ChoiseVariantQueue(int count)
{
	int variant;
	cout << "Choose variant: ";
	cin >> variant;
	while (variant < 0 or variant>3)
	{
		cout << "Incorrect input. Try again. " << endl;
		cout << "Choose variant: ";
		cin >> variant;
	}
	return variant;
}

void PrintMenuQueue()
{
	cout << endl;
	cout << "1. Enqueue." << endl;
	cout << "2. Dequeue." << endl;
	cout << "3. Delete." << endl;
	cout << "0. Exit." << endl;
}
void QueueMenu(RingBuffer* queue)
{
	cout << "Input capacity: ";
	QueueInit(queue);
	int variant;
	int element=0;
	do
	{ 
		CoutRing(queue);
		PrintMenuQueue();
		variant = ChoiseVariantQueue(3);
		switch (variant)
		{
		case 1:
			system("cls");
			if (FreeBuff(queue) == 0)
			{
				cout << "Buffer is full" << endl;
			}
			else
			{
				CoutRing(queue);
				cout << "Input element: ";
				cin >> element;
				InputRing(queue, element);
			}
			break;
		case 2:
			system("cls");
			if (BusyBuff(queue) == 0)
			{
				cout << "Buffer is empty" << endl;
			}
			else
			{
				CoutRing(queue);
				OutputRing(queue, element);
			}
			break;
		case 3:
			delete[] queue->ringBuffer;
			system("cls");
			cout << "Queue deleted" << endl;
			break;
		default:
			break;
		}

	} while (variant != 0 && variant!=3);
}