#include"DoubleLinkList.h"
#include<iostream>
using namespace std;

class DoubleLinkStack :public DoubleLinkList<int>
{
public:
	//构造函数
	DoubleLinkStack(int initNodeValue) :DoubleLinkList(initNodeValue){}	
	//判空
	bool isEmpty()
	{
		cout << "判断栈是否为空" << endl;
		IsEmpty();
	}
	//获取栈长
	int getSize()
	{
		cout << "获取栈长" << endl;
		Size();
	}
	//入栈
	void push(int e)
	{
		AddFromTail(e);
	}
	//出栈
	void pop()
	{
		DeleteFromLocal(m_iCount - 1);
	}
	//返回栈顶元素
	void get_topE()
	{
		//cout << "栈顶的元素是：" << endl;
		SearchFromLocal(m_iCount - 1);
	}
	//遍历栈
	void Sprint()
	{
		cout << "遍历栈：" << endl;
		Print(false);
	}

};