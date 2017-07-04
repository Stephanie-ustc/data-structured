// DLinkStack_inheritance_DLinkList.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"DoubleLinkStack.h"
#include"DoubleLinkList.h"
#include<iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	DoubleLinkStack s1(5);
	bool a=s1.IsEmpty();
	s1.push(11);
	s1.push(22);
	s1.push(33);

	s1.Sprint();

	s1.pop();

	s1.Sprint();

	s1.get_topE();
	return 0;
}

