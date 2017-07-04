#pragma once
#include <iostream>
#include <string>
#include <exception>
using namespace std;

//�Զ����쳣��
class LinkQueueException : public exception  //ר���ṩ���ⲿʹ�õģ����������ڲ���  
{
public:
	LinkQueueException(string msg) : m_msg(msg) {}
	const char * what() const throw ()    //����
	{
		return m_msg.c_str();
	}
private:
	string m_msg;
};

//������
template<typename T>
class LinkQueue
{
public:
	LinkQueue();            //�޲ι���
	LinkQueue(T initValue); //�вҹ���
	~LinkQueue();
	void EnQueue(T e);		//���  
	void DeQueue();			//����
	int GetSize();			//��ȡ���г���
	T GetQueueHead();		//��ȡ��ͷ
	void Print();           //��������
	void ClearQueue();      //��ն���
private:
	void InitQueue();		//��ʼ������
	bool IsEmpty();			//�����Ƿ�Ϊ��

private:  //��Node��Ϊ�ڲ��࣬�����ⲿ����
	class Node        //�ڵ���
	{
	public:
		Node(T d, Node* n = nullptr) : data(d), next(n) {}
	private:
		T data;
		Node* next;
		friend class LinkQueue;   //�����Ա��������Ϊ˽�У���ôֻ��������Ԫ����ܷ���
	};
private:
	Node* m_front; //ͷ�ڵ㣬ָ�����
	Node* m_rear;  //β�ڵ㣬ָ���β
	int m_count;		  //���д�С
	T m_initVlaue="0";    //��ʼ���ڵ��ֵ
};

//���캯��
template <typename T>
LinkQueue<T>::LinkQueue()
{
	InitQueue();
}
//��ʼ��
template <typename T>
void LinkQueue<T>::InitQueue()
{
	m_front = new Node(m_initVlaue);
	m_rear = new Node(m_initVlaue);
	m_count = 0;
}
//�вι��캯��
template <typename T>
void LinkQueue<T>::LinkQueue(T initValue)
{
	m_initVlaue = initValue;
	InitQueue();
}
//��������
template <typename T>
LinkQueue<T>::~LinkQueue()
{
	ClearQueue();
}
//��ն���
template <typename T>
void LinkQueue<T>::ClearQueue()
{
	delete m_front;
	m_front = nullptr;
	delete m_rear;
	m_rear = nullptr;
}
//���
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
//����
template <typename T>
void LinkQueue<T>::DeQueue()
{
	if (IsEmpty())
	{
		//cout << "�ӿգ�����ʧ��" << endl;
		throw LinkQueueException("�ӿգ�����ʧ��");
	}
	Node* temp = m_front->next;
	m_front->next = temp->next;
	deleta temp;
	--m_count;
}
//��ȡ���г���
template <typename T>
T LinkQueue<T>::GetSize()
{
	return m_count;
}

template <typename T>
T LinkQueue<T>::GetQueueHead()
{
	if (IsEmpty())
		throw LinkQueueException("�ӿգ��޷����ͷ�ڵ�");

}