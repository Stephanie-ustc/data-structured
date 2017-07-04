// LinkStack.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include"LinkStack.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	LinkStack<int> s1(00);
	bool a = s1.IsEmpty();
	int b = s1.GetSize();
	s1.Push(11);
	s1.Push(22);
	s1.Push(33);
	s1.Pop();
	int c = s1.PopE();
	int d = s1.GetTop();
	s1.Print();
	return 0;
}

