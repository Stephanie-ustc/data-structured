//˳"'��ջ��//
//2017.1.24--wd//
#include <iostream>
using namespace std;

template<class T>
class SequenceStack   
{
public:
	SequenceStack(int newstackSize);
	~SequenceStack();
public:
	bool IsEmpty();       //ջ�Ƿ�Ϊ��
	bool IsFull();        //ջ�Ƿ�����
	int GetSize();        //��ȡ��ǰջ�ĳ���
	void Print();         //����ջ
	void reserve(int newsize);
	void Push(T e);       //��ջ
	void Pop();           //��ջ(������ջ��Ԫ��)
	T PopE();             //��ջ(����ջ��Ԫ��)
	T GetTop();           //��ȡջ��Ԫ��
	
	void ClearStack();    //���ջ
	
	
private:
	T* m_data;			  //ջ������
	int m_top;			  //ջ��ָʾ
	int m_stackSize;      //ջ��С
	//int m_capacity;       //ջ����
	//int  Log;
};

//���캯��
template <class T>
SequenceStack<T>::SequenceStack(int newstackSize)
{
	m_stackSize = newstackSize;
	//Log = ceil(log((double)m_stackSize) / log(2.0));
	//m_capacity = 1 << Log;
	m_data = new T[m_stackSize];
	memset(m_data,0,sizeof(m_data));//ע�⣺memsetֻ�ܳ�ʼ��Ϊ0�����ڶ�������ֻ����0
	m_top = -1;
}

//��������
template <class T>
SequenceStack<T>::~SequenceStack()
{
	delete[] m_data;
	m_top = -1;
	m_stackSize = 0;
	cout << "\n�ڴ����ͷ�\n" << endl;
}
//ջ�Ƿ�Ϊ�� ��ջ�շ���true�����򷵻�false
template <class T>
bool SequenceStack<T>::IsEmpty()
{
	return m_top == -1;
}
//ջ�Ƿ�����
template <class T>
bool SequenceStack<T>::IsFull()
{
	return m_top == m_stackSize-1;//ע��ջΪ1ʱm_topΪ0
}

//��ȡ��ǰջ�ĳ���
template <class T>
int SequenceStack<T>::GetSize()
{
	return m_top+1;
}
//���� ����ȳ� ��ջ���������
template <class T>
void SequenceStack<T>::Print()
{
	if (IsEmpty())
	{
		cout << "ջ�� ����ʧ��Ŷ" << endl;
		return;
	}		
	cout << "��ջ�����������" << endl;
	while (m_top + 1)
	{
		cout << "��" << m_top << "λ�õ�Ԫ��Ϊ��" << m_data[m_top] << endl;
		m_top--;
	}
	return;
}
//�������ô洢�ռ�
template <class T>
void SequenceStack<T>::reserve(int newsize)
{
	m_stackSize = newsize;
	T* new_data = new T[m_stackSize];
	for (unsigned int i = 0; i < m_stackSize; i++)
		new_data[i] = m_data[i];
	delete [] m_data;
	m_data = new_data;	
}

//��ջ
template <class T>
void SequenceStack<T>::Push(T e)
{
	if (IsFull())
	{
		cout << "ջ��" << endl;
		reserve(m_stackSize);//����  ����һ����������ʵ��Ӧ���� ���ǳ�������ʱ��Ϳռ����� ����(this->m_stackSize)*2 ��(this->m_stackSize)+10
	}
	m_data[++m_top] = e;		
}
//��ջ(������ջ��Ԫ��)
template <class T>
void SequenceStack<T>::Pop()
{
	if (IsEmpty())   //���ջΪ�գ���ʲôҲ����
	{
		cout << "ջΪ�գ���ջ����ʧ�ܡ�" << endl;
		return;
	}
	m_top--;
}

//��ջ(����ջ��Ԫ��)
template <class T>
T SequenceStack<T>::PopE()
{
	if (IsEmpty())
	{
		cout << "ջΪ�գ���ջ����ʧ�ܡ�" << endl;
		return -1;
	}
	return m_data[m_top--];
}

//��ȡջ��Ԫ��
template <class T>
T SequenceStack<T>::GetTop()
{
	if (IsEmpty())
	{
		cout << "ջΪ�գ�����ʧ��" << endl;
		return -1;
	}
	return m_data[m_top];
}
//���ջ
template <class T>
void SequenceStack<T>::ClearStack()
{
	if (IsEmpty())
	{
		cout << "ջΪ�գ�����ʧ��" << endl;
	}
	m_top = -1;
}

