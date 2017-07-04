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

	bool IsEmpty();//栈是否为空
	int GetSize();//获取栈得长度
	void Push(T e);//入栈
	void Pop();//出栈（不返回栈顶得元素）
	T PopE();//出栈（返回栈顶得元素）
	T GetTop();//获取栈顶元素*/
	void Print();//遍历栈
	void ClearStack();//清空栈
	void InitStack();//初始化栈

private:
	Node* m_top;//栈顶指针
	int m_count;//栈得大小
	T m_initvalue;//节点得初始值
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
		m_top->next = node;//修改m_top指向
	}
	m_count++;
}

template<class T>
void LinkStack<T>::Print()
{
	Node* cur = m_top->next; 
	if (IsEmpty())
	{
		cout << "栈为空" << endl;
		return;
	}
	else
	{
		cout << "从栈顶依次输出：" << endl;
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
		cout << "栈空 出栈失败" << endl;
		return;
	}
	else
	{
		Node* temp = m_top->next;//保存将要出栈的元素（其实就是链表中删除元素的步骤）
		m_top->next = temp->pre;
		--m_count;
		delete temp;    //释放节点
	}	
}
template<class T>
T LinkStack<T>::PopE()
{
	if (IsEmpty())
	{
		cout << "栈空 出栈失败" << endl;
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
		cout << "栈空 栈顶无元素" << endl;
		return -1;
	}
	return m_top->next->data;
}