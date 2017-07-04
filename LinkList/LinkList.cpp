// LinkList.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"LinkList.h"
#include<iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	string str = "h";
	string str1 = "world";
	string str2 = "hello";
	string str3 = "haha";
	string str4 = "heihei";
	string str5 = "句号";
	LinkList<string> list1(str);
	LinkList<string> list2(str5);
	
	bool a = list1.IsEmpty();
	int b = list1.Size();
	list1.AddFromHead(str1);
	list1.AddFromHead(str2);
	list1.AddFromTail(str3);
	list1.AddFromTail(str4);
	list1.Insert(3, str5);
	list1.DeleteFromLocal(3);
	list1.DeleteFromElement(str4);
	int c = list1.SearchFromElmemt(str2);
	string d = list1.SearchFromLocal(2);
	list1.Reverse1();
	list1.Reverse2();
	list1.Print();
	list2.CopyList(list1);
	return 0;
}

