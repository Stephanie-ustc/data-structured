#include <iostream>
#include <string>
using namespace std;

// ��һ��������Ŀ������shared_ptr���Թ���һ����̬���飬��Ҫָ��ɾ����
/*template<typename T>
shared_ptr<T> make_shared_array(size_t size)
{
	return shared_ptr<T>(new T[size], [](T* p){delete[] p; });
}*/

template<typename T>
class SequenceQueue  //˳�������
{
public:
	SequenceQueue(int queueSize);   //Ĭ�϶��д�С   ���������ͣ� ��С
	~SequenceQueue();
public:
	void EnQueue(T e);				   //���      
	void DeQueue();						//����
	int GetSize();					   //��ȡ���г���
	T GetQueueHead();					//��ȡ��ͷ
	void Print();					   //��������
	void ClearQueue();				   //��ն���

	void InitQueue(int queueSize);		//��ʼ������,����ָ�����д�С
	bool IsEmpty();						//�����Ƿ�Ϊ��					
	bool IsFull();						//�����Ƿ���
private:
	//shared_ptr<T>m_data;
	T* m_data;							//������������
	int m_front;						//��ͷ
	int m_rear;							//��β
	int m_queueSize;					//���е���󳤶�
};

template<typename T>
SequenceQueue<T>::SequenceQueue(int queueSize)
{
	InitQueue(queueSize);
}

template<typename T>
void SequenceQueue<T>::InitQueue(int queueSize)
{
	m_queueSize = queueSize;
	m_data = new T[m_queueSize];
	m_front = 0;
	m_rear = 0;
}

template<typename T>
SequenceQueue<T>::~SequenceQueue()
{
	ClearQueue();
}

template<typename T>
void SequenceQueue<T>::ClearQueue()
{
	if (IsEmpty())
		cout << "�����ѿգ����ʧ��" << endl;
	else
	{
		m_front = 0;
		m_rear = 0;
	}
}
//���
template<typename T>
void SequenceQueue<T>::EnQueue(T e)
{
	if (IsFull())
		cout << "�������������ʧ��" << endl;
	m_data[m_rear] = e;
	m_rear++;
}
//����
template<typename T>
void SequenceQueue<T>::DeQueue()
{
	if (IsEmpty())
		cout << "�����ѿգ�����ʧ��" << endl;
	++m_front;
}

template<typename T>
int SequenceQueue<T>::GetSize()
{
	return m_rear - m_front;
}

template<typename T>
T SequenceQueue<T>::GetQueueHead()
{
	if (IsEmpty())
		cout << "�ӿգ���ȡ��ͷʧ��"<< endl;
	return m_data[m_front];
}

template<typename T>
void SequenceQueue<T>::Print()
{
	if (IsEmpty())
		cout << "�ӿգ�����ʧ��" << endl;
	cout << "����Ԫ������Ϊ��";
	for (int i = m_front; i <m_rear; i++)
	{
		//cout << "��" << i << "��Ԫ��Ϊ��" << m_data[i] << endl;
		cout << m_data[i]<<" ";
	}
}

template<typename T>
bool SequenceQueue<T>::IsEmpty()
{
	return m_front == m_rear;
}

template<typename T>
bool SequenceQueue<T>::IsFull()
{
	return m_rear == m_queueSize;
}