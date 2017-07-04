// shunxubiao.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include"Slist.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	Slist<int> s1;
	Slist<int> s2(6);
	Slist<int> s3(5,9);
	int gg = s3.back();
	s3.locateValue(5);
	unsigned int a = s3.size();
	unsigned int b = s3.capacity();
	unsigned int c = s3.empty();
	//s3.clear();
	int *d = s3.begin();
	int *e = s3.end();
	int f = s3.front();
	int g = s3.back();

	s3.push_back(20);
	int *h = s3.end();
	s3.push_back(11);
	s3.push_back(26);
	s3.push_back(45);
	int *hh = s3.end();
    
	//s3.pop_back();
	int *j = s3.end();


	s3.insert(66, 2);
	unsigned int k = s3.find(66);

	s3.remove(7);
	unsigned int l = s3.find(20);

	int x = s3.locateValue(20);
	s3.print();
	/*Slist<Slist<int>>a;
	Slist<int>b(3, 4);
	b.print();
	Slist<int>c(5, 3);
	a.push_back(b);*/
	//a.print();
	//a.push_back(c);



	return 0;
}

