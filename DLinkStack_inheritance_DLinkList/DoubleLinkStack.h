#include"DoubleLinkList.h"
#include<iostream>
using namespace std;

class DoubleLinkStack :public DoubleLinkList<int>
{
public:
	//���캯��
	DoubleLinkStack(int initNodeValue) :DoubleLinkList(initNodeValue){}	
	//�п�
	bool isEmpty()
	{
		cout << "�ж�ջ�Ƿ�Ϊ��" << endl;
		IsEmpty();
	}
	//��ȡջ��
	int getSize()
	{
		cout << "��ȡջ��" << endl;
		Size();
	}
	//��ջ
	void push(int e)
	{
		AddFromTail(e);
	}
	//��ջ
	void pop()
	{
		DeleteFromLocal(m_iCount - 1);
	}
	//����ջ��Ԫ��
	void get_topE()
	{
		//cout << "ջ����Ԫ���ǣ�" << endl;
		SearchFromLocal(m_iCount - 1);
	}
	//����ջ
	void Sprint()
	{
		cout << "����ջ��" << endl;
		Print(false);
	}

};