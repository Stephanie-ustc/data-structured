// DoubleLinkList.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"DoubleLinkList.h"


int _tmain(int argc, _TCHAR* argv[])
{
	DoubleLinkList<int> list1(0);
	DoubleLinkList<int> list2(00);
	bool a = list1.IsEmpty();
	list1.AddFromHead(11);
	list1.AddFromHead(22);
	list1.AddFromHead(33);
	list1.AddFromTail(44);
	list1.Insert(2,99);
	list1.DeleteFromLocal(2);
	int b = list1.SearchFromElmemt(33);
	list1.SearchFromLocal(1);
	list1.Reverse();
	list2.CopyList(list1);
	list1.Rewrite(2,88);
	list1.SortByAsc();
	cout << endl << "list1";
	list1.Print(0);
	cout << endl<< "list2";
	list2.Print(0);
	return 0;
}

