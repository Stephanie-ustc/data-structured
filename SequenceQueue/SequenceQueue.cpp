// SequenceQueue.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include"SequenceQueue.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	SequenceQueue<int> quence(50);
	quence.EnQueue(11);
	quence.EnQueue(22);
	quence.Print();
	int a=quence.GetSize();
	quence.DeQueue();
	quence.Print();
	int b=quence.GetQueueHead();
	bool c=quence.IsEmpty();
	return 0;
}

