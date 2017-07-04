#include <iostream>
#include <string>
using namespace std;

// 定一个函数，目的是让shared_ptr可以管理一个动态数组，需要指定删除器
/*template<typename T>
shared_ptr<T> make_shared_array(size_t size)
{
	return shared_ptr<T>(new T[size], [](T* p){delete[] p; });
}*/

template<typename T>
class SequenceQueue  //顺序队列类
{
public:
	SequenceQueue(int queueSize);   //默认队列大小   （数据类型） 大小
	~SequenceQueue();
public:
	void EnQueue(T e);				   //入队      
	void DeQueue();						//出队
	int GetSize();					   //获取队列长度
	T GetQueueHead();					//获取队头
	void Print();					   //遍历队列
	void ClearQueue();				   //清空队列

	void InitQueue(int queueSize);		//初始化队列,并且指定队列大小
	bool IsEmpty();						//队列是否为空					
	bool IsFull();						//队列是否满
private:
	//shared_ptr<T>m_data;
	T* m_data;							//队列数据区域
	int m_front;						//队头
	int m_rear;							//队尾
	int m_queueSize;					//队列的最大长度
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
		cout << "队列已空，清空失败" << endl;
	else
	{
		m_front = 0;
		m_rear = 0;
	}
}
//入队
template<typename T>
void SequenceQueue<T>::EnQueue(T e)
{
	if (IsFull())
		cout << "队列已满，入队失败" << endl;
	m_data[m_rear] = e;
	m_rear++;
}
//出队
template<typename T>
void SequenceQueue<T>::DeQueue()
{
	if (IsEmpty())
		cout << "队列已空，出队失败" << endl;
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
		cout << "队空，获取队头失败"<< endl;
	return m_data[m_front];
}

template<typename T>
void SequenceQueue<T>::Print()
{
	if (IsEmpty())
		cout << "队空，遍历失败" << endl;
	cout << "队列元素依次为：";
	for (int i = m_front; i <m_rear; i++)
	{
		//cout << "第" << i << "个元素为：" << m_data[i] << endl;
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