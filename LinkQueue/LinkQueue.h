#pragma once
#include <iostream>
#include <string>
#include <exception>
using namespace std;

//自定义异常类
class LinkQueueException : public exception  //专门提供给外部使用的，不能做成内部类  
{
public:
	LinkQueueException(string msg) : m_msg(msg) {}
	const char * what() const throw ()    //重载
	{
		return m_msg.c_str();
	}
private:
	string m_msg;
};

//链队列
template<typename T>
class LinkQueue
{
public:
	LinkQueue();            //无参构造
	LinkQueue(T initValue); //有惨构造
	~LinkQueue();
	void EnQueue(T e);		//入队  
	void DeQueue();			//出队
	int GetSize();			//获取队列长度
	T GetQueueHead();		//获取队头
	void Print();           //遍历队列
	void ClearQueue();      //清空队列
private:
	void InitQueue();		//初始化队列
	bool IsEmpty();			//队列是否为空

private:  //把Node作为内部类，不让外部访问
	class Node        //节点类
	{
	public:
		Node(T d, Node* n = nullptr) : data(d), next(n) {}
	private:
		T data;
		Node* next;
		friend class LinkQueue;   //如果成员变量声明为私有，那么只有声明友元类才能访问
	};
private:
	Node* m_front; //头节点，指向队首
	Node* m_rear;  //尾节点，指向队尾
	int m_count;		  //队列大小
	T m_initVlaue="0";    //初始化节点的值
};

//构造函数
template <typename T>
LinkQueue<T>::LinkQueue()
{
	InitQueue();
}
//初始化
template <typename T>
void LinkQueue<T>::InitQueue()
{
	m_front = new Node(m_initVlaue);
	m_rear = new Node(m_initVlaue);
	m_count = 0;
}
//有参构造函数
template <typename T>
void LinkQueue<T>::LinkQueue(T initValue)
{
	m_initVlaue = initValue;
	InitQueue();
}
//析构函数
template <typename T>
LinkQueue<T>::~LinkQueue()
{
	ClearQueue();
}
//清空队列
template <typename T>
void LinkQueue<T>::ClearQueue()
{
	delete m_front;
	m_front = nullptr;
	delete m_rear;
	m_rear = nullptr;
}
//入队
template <typename T>
void LinkQueue<T>::EnQueue(T e)
{
	Node* node = new Node(m_initValue);
	node->data = e;
	if (IsEmpty())
		m_rear->next = node;
	else
		m_rear->next->next = node;
	m_rear->next = node;
	node->next = nullptr;
	++m_count;
}
//出队
template <typename T>
void LinkQueue<T>::DeQueue()
{
	if (IsEmpty())
	{
		//cout << "队空，出队失败" << endl;
		throw LinkQueueException("队空，出队失败");
	}
	Node* temp = m_front->next;
	m_front->next = temp->next;
	deleta temp;
	--m_count;
}
//获取队列长度
template <typename T>
T LinkQueue<T>::GetSize()
{
	return m_count;
}

template <typename T>
T LinkQueue<T>::GetQueueHead()
{
	if (IsEmpty())
		throw LinkQueueException("队空，无法获得头节点");

}