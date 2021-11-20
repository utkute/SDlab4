#include "Ring.h"
int FreeBuff(RingBuffer* buffer)
{
	if (buffer->size == 0)
	{
		return buffer->capacyty;
	}
	else
	{
		int counter = 0;
		int i;
		for (i = buffer->indexInput; i != buffer->indexOutput; i = (i + 1) % buffer->capacyty)
		{
			counter++;
		}
		return counter;
	}
}
int BusyBuff(RingBuffer* buffer)
{
	if (buffer->size == buffer->capacyty)
	{
		return buffer->capacyty;
	}
	else
	{
		int counter = 0;
		int i;
		for (i = buffer->indexOutput; i != buffer->indexInput; i = (i + 1) % buffer->capacyty)
		{
			counter++;
		}
		return counter;
	}
}

void InputRing(RingBuffer* buffer, int element)
{
	if (FreeBuff(buffer) != 0)
	{
		buffer->ringBuffer[buffer->indexInput] = element;
		buffer->size++;
		buffer->indexInput = (buffer->indexInput + 1) % buffer->capacyty;
	}
}
void OutputRing(RingBuffer* buffer, int element)
{
	if (BusyBuff(buffer) != 0)
	{
		element = buffer->ringBuffer[buffer->indexOutput];
		buffer->size--;
		buffer->indexOutput = (buffer->indexOutput + 1) % buffer->capacyty;
	}
}
//void ChangeSizeRing(RingBuffer* buffer)
//{
//	int i;
//	int* temp = new int[buffer->capacyty];
//	for(i = buffer->indexOutput; i != buffer->indexInput; i = (i + 1) % buffer->capacyty)
//	{
//		temp[i] = buffer->ringBuffer[i];
//	}
//	delete[] buffer->ringBuffer;
//	buffer->ringBuffer = temp;
//}