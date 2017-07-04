#pragma once
#include<iostream>
using namespace std;

template<class T>
class LinkStack
{
private:
	class Node
	{
	public:
		Node(T d, Node* n = nullptr, Node* p=nullptr) :data(d), next(n), pre(p){}
	private:
		T data;
		Node* next;
		Node* pre;
		friend class LinkStack;
	};
public:
	LinkStack(T initvalue);
	~LinkStack();

	bool IsEmpty();//ջ�Ƿ�Ϊ��
	int GetSize();//��ȡջ�ó���
	void Push(T e);//��ջ
	void Pop();//��ջ��������ջ����Ԫ�أ�
	T PopE();//��ջ������ջ����Ԫ�أ�
	T GetTop();//��ȡջ��Ԫ��*/
	void Print();//����ջ
	void ClearStack();//���ջ
	void InitStack();//��ʼ��ջ

private:
	Node* m_top;//ջ��ָ��
	int m_count;//ջ�ô�С
	T m_initvalue;//�ڵ�ó�ʼֵ
};

template<class T>
LinkStack<T>::LinkStack(T initvalue)
{
	m_initvalue = initvalue;
	InitStack();
}

template<class T>
void LinkStack<T>::InitStack()
{
	m_count = 0;
	m_top = new Node(m_initvalue);
}

template<class T>
LinkStack<T>::~LinkStack()
{
	ClearStack();
}
template<class T>
void LinkStack<T>::ClearStack()
{
	m_count = 0;
	delete m_top;
}
template<class T>
bool LinkStack<T>::IsEmpty()
{
	return m_count == 0;
}
template<class T>
int LinkStack<T>::GetSize()
{
	return m_count;
}
template<class T>
void LinkStack<T>::Push(T e)
{
	Node* node = new Node(e);
	if (IsEmpty())
	{
		m_top->next = node;
		node->pre = m_top;
	}

	else
	{
		m_top->next->next = node;
		node->pre = m_top->next;
		m_top->next = node;//�޸�m_topָ��
	}
	m_count++;
}

template<class T>
void LinkStack<T>::Print()
{
	Node* cur = m_top->next; 
	if (IsEmpty())
	{
		cout << "ջΪ��" << endl;
		return;
	}
	else
	{
		cout << "��ջ�����������" << endl;
		for (int i = 0; i < m_count; i++)
		{
			cout << cur->data << endl;
			cur = cur->pre;
		}
	}
}

template<class T>
void LinkStack<T>::Pop()
{
	if (IsEmpty())
	{
		cout << "ջ�� ��ջʧ��" << endl;
		return;
	}
	else
	{
		Node* temp = m_top->next;//���潫Ҫ��ջ��Ԫ�أ���ʵ����������ɾ��Ԫ�صĲ��裩
		m_top->next = temp->pre;
		--m_count;
		delete temp;    //�ͷŽڵ�
	}	
}
template<class T>
T LinkStack<T>::PopE()
{
	if (IsEmpty())
	{
		cout << "ջ�� ��ջʧ��" << endl;
		return -1;
	}
	else
	{
		Node* temp = m_top->next;
		T d = temp->data;
		m_top->next = temp->pre;
		--m_count;
		delete temp; 
		return d;
	}
}
template<class T>
T LinkStack<T>::GetTop()
{
	if (IsEmpty())
	{
		cout << "ջ�� ջ����Ԫ��" << endl;
		return -1;
	}
	return m_top->next->data;
}