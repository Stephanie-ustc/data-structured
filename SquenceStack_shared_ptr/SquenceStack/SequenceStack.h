//顺序栈类//
//2017.1.24--wd//
#include <iostream>
#include <memory>
using namespace std;

// 定一个函数，目的是让shared_ptr可以管理一个动态数组，需要指定删除器
template<class T>
shared_ptr<T> make_shared_array(size_t size)
{
	return shared_ptr<T>(new T[size], default_delete<T[]>());// default_delete<T[]>()默认删除器
	//也可以用下面这个删除器，建议用下面的这个，理由是，T不一定是系统基本变凉类型
	//return shared_ptr<T>(new T[size], [](T* p){delete[] p; }); //指定delete[]
}

template<class T>
class SequenceStack   
{
public:
	SequenceStack(int newstackSize);
	~SequenceStack();
public:
	bool IsEmpty();       //栈是否为空
	bool IsFull();        //栈是否满了
	int GetSize();        //获取当前栈的长度
	void Print();         //遍历栈
	void reserve(int newsize);
	void Push(T e);       //入栈
	void Pop();           //出栈(不返回栈顶元素)
	T PopE();             //出栈(返回栈顶元素)
	T GetTop();           //获取栈顶元素
	
	void ClearStack();    //清空栈
	
private:
	shared_ptr<T> m_data;
	//T* m_data;			  //栈数据区
	int m_top;			  //栈顶指示
	int m_stackSize;      //栈大小
	//int m_capacity;       //栈容量
	//int  Log;
};

//构造函数
template <class T>
SequenceStack<T>::SequenceStack(int newstackSize)
{
	m_stackSize = newstackSize;
	m_data = make_shared_array<T>(m_stackSize);
	//m_data = new T[m_stackSize];
	//memset(m_data,0,sizeof(m_data));//注意：memset只能初始化为0，即第二个参数只能是0，有疑问
	m_top = -1;
}

//析构函数
template <class T>
SequenceStack<T>::~SequenceStack()
{
	//delete[] m_data;
	m_top = -1;
	m_stackSize = 0;
	//cout << "\n已经完成内存释放！\n" << endl;
}
//栈是否为空 若栈空返回true，否则返回false
template <class T>
bool SequenceStack<T>::IsEmpty()
{
	return m_top == -1;
}
//栈是否了满
template <class T>
bool SequenceStack<T>::IsFull()
{
	return m_top == m_stackSize-1;//注：栈为1时m_top为0
}

//获取当前栈的长度
template <class T>
int SequenceStack<T>::GetSize()
{
	return m_top+1;
}
//遍历 后进先出 从栈顶依次输出
template <class T>
void SequenceStack<T>::Print()
{
	if (IsEmpty())
	{
		cout << "栈空 遍历失败哦" << endl;
		return;
	}		
	cout << "从栈顶依次输出：" << endl;
	while (m_top + 1)
	{
		cout << "第" << m_top << "位置的元素为：" << m_data.get()[m_top] << endl;
		m_top--;
	}
	return;
}
//重新设置存储空间
template <class T>
void SequenceStack<T>::reserve(int newsize)
{
	m_stackSize = newsize;
	shared_ptr<T> new_data = make_shared_array<T>(m_stackSize);
	//T* new_data = new T[m_stackSize];
	for (unsigned int i = 0; i < m_stackSize; i++)
		new_data.get()[i] = m_data.get()[i];
	//delete [] m_data;
	m_data = new_data;	
}

//入栈
template <class T>
void SequenceStack<T>::Push(T e)
{
	if (IsFull())
	{
		cout << "栈满" << endl;
		reserve(++m_stackSize);
		//reserve((this->m_stackSize)++);//扩容  扩大一个，觉得在实际应用中 考虑程序运行时间和空间消耗 可以(this->m_stackSize)*2 或(this->m_stackSize)+10
	}
	m_data.get()[++m_top] = e;		
}
//出栈(不返回栈顶元素)
template <class T>
void SequenceStack<T>::Pop()
{
	if (IsEmpty())   //如果栈为空，就什么也不做
	{
		cout << "栈为空，出栈操作失败。" << endl;
		return;
	}
	m_top--;
}

//出栈(返回栈顶元素)
template <class T>
T SequenceStack<T>::PopE()
{
	if (IsEmpty())
	{
		cout << "栈为空，出栈操作失败。" << endl;
		return -1;
	}
	return m_data.get()[m_top--];
}

//获取栈顶元素
template <class T>
T SequenceStack<T>::GetTop()
{
	if (IsEmpty())
	{
		cout << "栈为空，操作失败" << endl;
		return -1;
	}
	return m_data.get()[m_top];
}
//清空栈
template <class T>
void SequenceStack<T>::ClearStack()
{
	if (IsEmpty())
	{
		cout << "栈为空，操作失败" << endl;
	}
	m_top = -1;
}