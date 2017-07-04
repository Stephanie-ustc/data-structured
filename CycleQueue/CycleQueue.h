#pragma once
#include <iostream>
#include <string>
#include <exception>
using namespace std;

//�Զ����쳣��
class CycleQueueException : public exception  //ר���ṩ���ⲿʹ�õģ����������ڲ���  
{
public:
	CycleQueueException(string msg) : m_msg(msg) {}
	const char * what() const throw ()    //����
	{
		return m_msg.c_str();
	}
private:
	string m_msg;
};

template<typename T>
class CycleQueue  //˳�������
{
public:
	CycleQueue(int queueSize = 50);     //Ĭ�϶��д�СΪ50�� �����������ͣ� ��С
	~CycleQueue();
public:
	void EnQueue(T e);				    //���      
	void DeQueue();						//����
	int GetSize();					   //��ȡ���г���
	T GetQueueHead();					//��ȡ��ͷ
	void Print();					   //��������
	void ClearQueue();				   //��ն���
private:
	void InitQueue(int queueSize);		//��ʼ������,����ָ�����д�С
	bool IsEmpty();						//�����Ƿ�Ϊ��					
	bool IsFull();						//�����Ƿ���
private:
	T* m_data;							//������������
	int m_front;						//��ͷ
	int m_rear;							//��β
	int m_queueSize;					//���е���󳤶�
	int m_count;
};

template<typename T>
CycleQueue<T>::CycleQueue(int queueSize = 50)
{
	InitQueue(queueSize);
}

template<typename T>
CycleQueue<T>::~CycleQueue()
{

}

//��ʼ������,����ָ�����д�С
template<typename T>
void CycleQueue<T>::InitQueue(int queueSize)
{
	m_data = new T[queueSize];  //�������������С
	m_front = 0;  //��ʼ��ͷָ��0����ʾ������Ԫ��
	m_rear = 0;   //��ʼ��βָ��0����ʾ������Ԫ��
	m_count = 0;
	m_queueSize = queueSize;
}

//�����Ƿ�Ϊ��
template<typename T>
bool CycleQueue<T>::IsEmpty()
{
	return m_count == 0 ? true : false;
}

//�����Ƿ���
template<typename T>
bool CycleQueue<T>::IsFull()
{
	return m_count == m_queueSize ? true : false;
}

//���  
template<typename T>
void CycleQueue<T>::EnQueue(T e)
{
	if (IsFull())
		throw CycleQueueException("������������Ӳ���ʧ��.");
	else
	{//�������û��������ѭ��������ĵ�һ��a[0]�������,�ѿռ�������
		m_data[m_rear % m_queueSize] = e;
		m_rear = ++m_rear % m_queueSize;
		++m_count;
	}
}

//����
template<typename T>
void CycleQueue<T>::DeQueue()
{
	if (IsEmpty())
		throw CycleQueueException("����Ϊ�գ����Ӳ���ʧ��.");
	else
	{     //��ͷָ�������,�Ƶ�������û��������ѭ����a[0]����		
		m_front = ++m_front%m_queueSize;
		--m_count;
	}
}

//��ȡ���г���
template<typename T>
int CycleQueue<T>::GetSize()
{
	return m_count;
}

//��ȡ��ͷ
template<typename T>
T CycleQueue<T>::GetQueueHead()
{
	if (IsEmpty())
		throw CycleQueueException("����Ϊ�գ���ȡ��ͷ����ʧ��");
	else
		return m_data[m_front];
}

//��������
template<typename T>
void CycleQueue<T>::Print()
{
	if (IsEmpty())
		throw CycleQueueException("����Ϊ�գ���������ʧ��");
	else
	{
		if (m_front < m_rear)  //���������ģ�û��ѭ����ʱ��
		{
			for (int i = m_front; i < m_rear; i++)
				cout << m_data[i] << endl;
		}
		else
		{
			for (int i = m_front; i < m_queueSize; i++)  //�ֶα���
				cout << m_data[i] << endl;
			for (int i = 0; i < m_rear; i++)
				cout << m_data[i] << endl;
		}
	}
}

//��ն���
template<typename T>
void CycleQueue<T>::ClearQueue()
{
	if (IsEmpty())
		throw CycleQueueException("����Ϊ�գ���ղ���ʧ��.");
	else
	{
		m_front = 0;//����������ݣ���ӵ�ʱ��ֱ�Ӹ��Ǿͺ�
		m_rear = 0;
		m_count = 0;
	}
}