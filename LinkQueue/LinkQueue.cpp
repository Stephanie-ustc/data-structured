// LinkQueue.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include"LinkQueue.h"
#include<string>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	string s1("wd");
	LinkQueue<string> queue;
	queue.EnQueue(s1);
	queue.EnQueue("ustc");
	queue.EnQueue("ahu");
	queue.Print();
	queue.DeQueue();
	queue.Print();
	string a=queue.GetQueueHead();

	return 0;
}

