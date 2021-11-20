#include"RingMenu.h"
using namespace std;
void CoutRing(RingBuffer* buffer)
{
	int i;
	if (BusyBuff(buffer) == 0)
	{
		cout << "Buffer is empty";
	}
	else if (buffer->indexInput == buffer->indexOutput)
	{
		cout << buffer->ringBuffer[buffer->indexOutput];
		for (i = buffer->indexOutput+1; i != buffer->indexInput; i = (i + 1) % buffer->capacyty)
		{
			cout << buffer->ringBuffer[i] << " ";
		}
	}
	else
	{
		for (i = buffer->indexOutput; i != buffer->indexInput; i = (i + 1) % buffer->capacyty)
		{
			cout << buffer->ringBuffer[i] << " ";
		}
	}
	cout << endl;
}
int ChoiseVariantRing(int count)
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
void PrintMenuRing()
{
	cout << endl;
	cout << "1. Free slots." << endl;
	cout << "2. Busy slots." << endl;
	cout << "3. Input element." << endl;
	cout << "4. Output element." << endl;
	cout << "0. Exit." << endl;
}
void RingMenu(RingBuffer* buffer)
{
	cout << "Enter buffer capacity";
	cin >> buffer->capacyty;
	int variant;
	int element;
	do
	{
		CoutRing(buffer);
		PrintMenuRing();
		variant = ChoiseVariantRing(5);
		switch (variant)
		{
		case 3:
			system("cls");
			if (FreeBuff(buffer) == 0)
			{
				cout << "Buffer is full" << endl;
			}
			else
			{
				CoutRing(buffer);
				cout << "Input element: ";
				cin >> element;
				InputRing(buffer, element);
			}
			break;
		case 2:
			system("cls");
			CoutRing(buffer);
			cout << "Number of busy slots: " << BusyBuff(buffer) << endl;
			system("pause");
			system("cls");
			break;
		case 1:
			system("cls");
			CoutRing(buffer);
			cout << "Number of free slots: " << FreeBuff(buffer) << endl;
			system("pause");
			system("cls");
			break;
		case 4:
			system("cls");
			if (BusyBuff(buffer) == 0)
			{
				cout << "Buffer is empty" << endl;
			}
			else
			{
				CoutRing(buffer);
				OutputRing(buffer, element);
			}
			break;
		}

	} while (variant != 0);
}
