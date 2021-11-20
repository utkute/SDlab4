#include "StackMenu.h"
using namespace std;
void CoutStack(Stack*& head)
{
	int i = 0;
	int counter;
	string str;
	vector<int> ur;
	Stack* temp = new Stack;
	temp = head;
	while (temp->next != nullptr)
	{
		ur.push_back(temp->element);
		temp = temp->next;
	}
	temp = head;
	ur.push_back(temp->element);
	while (temp->next != nullptr)
	{
		str += to_string(ur[i]);
		str += " ";
		i++;
		temp = temp->next;
	}
	str += to_string(ur[i]);
	counter = str.length();
	for (i = 0; i < counter; i++)
	{
		cout << "-";
	}
	cout << endl;
	temp = head;
	while (temp->next != nullptr)
	{
		cout << temp->element << " ";
		temp = temp->next;
	}
	cout << temp->element << "|" << endl;
	for (i = 0; i < counter; i++)
	{
		cout << "-";
	}
	cout << endl;
}

int ChoiseVariant(int count)
{
	int variant;
	cout << "Choose variant: ";
	cin >> variant;
	while (variant < 0 or variant>4)
	{
		cout << "Incorrect input. Try again. " << endl;
		cout << "Choose variant: ";
		cin >> variant;
	}
	return variant;
}

void PrintMenuStack()
{
	cout << endl;
	cout << "1. Push." << endl;
	cout << "2. Pop." << endl;
	cout << "3. Delete." << endl;
	cout << "0. Exit." << endl;
}
void StackMenu(Stack*& head)
{
	StackInit(head);
	int variant;
	int element;
	do
	{
		CoutStack(head);
		PrintMenuStack();
		variant = ChoiseVariant(3);
		switch (variant)
		{
		case 1:
			system("cls");
			CoutStack(head);
			cout << "Input element: ";
			cin >> element;
			Push(head, element);
			break;
		case 2:
			system("cls");
			CoutStack(head);
			Pop(head, element);
			break;
		case 3:
			system("cls");
			CoutStack(head);
			DeleteStack(head);
			break;
		default:
			break;
		}

	} while (variant != 0);
}
