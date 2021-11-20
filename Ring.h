#pragma once
struct RingBuffer
{
	int *ringBuffer;
	int indexInput = 0;
	int indexOutput = 0;
	int size=0;
	int capacyty=8;
};
int FreeBuff(RingBuffer* buffer);
int BusyBuff(RingBuffer* buffer);
void InputRing(RingBuffer* buffer, int element);
void OutputRing(RingBuffer* buffer, int element);