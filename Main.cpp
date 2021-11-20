#include "StackInit.h"
#include "Stack.h"
#include "StackMenu.h"
#include "Ring.h"
#include "RingMenu.h"
#include "QueueMenu.h"
#include "QueueMenuS.h"
using namespace std;
void PrintMenuMain()
{
	cout << endl;
	cout << "1. Stack." << endl;
	cout << "2. Ring Buffer." << endl;
	cout << "3. Queue Ring." << endl;
	cout << "4. Queue Stack." << endl;
	cout << "0. Exit." << endl;
}

int main()
{
	srand(time(0));
	RingBuffer buffer;

	Stack* head = 0;
	RingBuffer queue;
	Stack* queueEnq = 0;
	Stack* queueDeq = 0;
	//	int a;
	//	/*StackInit(head);
	//StackMenu(head);
	//	cin >> a;
	//	InputRing(&buffer, a);
	//	cout << FreeBuff(&buffer);
	//	cout << BusyBuff(&buffer) << endl;
	//	cout << buffer.indexInput;
	buffer.ringBuffer = new int[buffer.capacyty];

		//QueueMenu(&queue);
		//QueueMenuS(queueEnq, queueDeq);
	int variant;
	do
	{
		PrintMenuMain();
		variant = ChoiseVariantRing(5);
		switch (variant)
		{
		case 1:
			StackMenu(head);
			break;
		case 2:
			RingMenu(&buffer);
			break;
		case 3:
			QueueMenu(&queue);
			break;
		case 4:
			QueueMenuS(queueEnq, queueDeq);
			break;
		}

	} while (variant != 0);
}
