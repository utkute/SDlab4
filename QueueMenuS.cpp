#include "QueueMenuS.h"
using namespace std;
void CoutQueueStack(Stack*& queueEnq, Stack*& queueDeq)
{
	int k;
	int i = 0;
	Stack* couter = 0;
	if (queueDeq != nullptr)
	{
		couter = queueDeq;
		while (couter->next != nullptr)
		{
			cout << couter->element << " ";
			couter = couter->next;
		}
		cout << couter->element << " ";
	}
	if (queueEnq != nullptr)
	{
		couter = queueEnq;
		while (couter->next != nullptr)
		{
			couter = couter->next;
			i++;
		}
		while (i != 0)
		{
			couter = queueEnq;
			for (k = 0; k < i; k++)
			{
				couter = couter->next;
			}
			cout << couter->element << " ";
			i--;
		}
		cout << queueEnq->element << " ";
	}
	cout << endl;
}
void SwichStack(Stack*& queueEnq, Stack*& queueDeq)
{
	int element;
	while (queueEnq->next != nullptr)
	{
		Pop(queueEnq, element);
		Push(queueDeq, element);
	}
	Pop(queueEnq, element);
	Push(queueDeq, element);
}
void QueueMenuS(Stack*& queueEnq, Stack*& queueDeq)
{
	StackInit(queueEnq);
	int variant;
	int element = 0;
	do
	{
		CoutQueueStack(queueEnq, queueDeq);
		PrintMenuQueue();
		variant = ChoiseVariantQueue(3);
		switch (variant)
		{
		case 1:
			system("cls");
			CoutQueueStack(queueEnq, queueDeq);
			cout << "Enter element: ";
			cin >> element;
			Push(queueEnq, element);
			break;
		case 2:
			system("cls");
			CoutQueueStack(queueEnq, queueDeq);
			if (queueDeq == 0)
			{
				SwichStack(queueEnq, queueDeq);
			}
			Pop(queueDeq, element);
			break;
		case 3:
			system("cls");
			DeleteStack(queueEnq);
			DeleteStack(queueDeq);
			cout << "Queue deleted" << endl;
			break;
		default:
			break;
		}

	} while (variant != 0 && variant != 3);
}
