// SquenceStack.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include"SequenceStack.h"

int _tmain(int argc, _TCHAR* argv[])
{
	SequenceStack<int> s1(1);
	
	s1.reserve(2);
	s1.Push(22);
	s1.Push(33);
	s1.Push(44);
	s1.Push(55);
	//s1.Pop();
	//int a = s1.PopE();
	//int b = s1.GetTop();
	//s1.ClearStack();
	s1.Print();
	//s1.DestroyStack();
	//s1.~SequenceStack();
	//s1.Print();
	return 0;
}

