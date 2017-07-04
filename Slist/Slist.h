#include<iostream>
#include <memory>
using namespace std;

// 定义一个函数，目的是让shared_ptr可以管理一个动态数组，需要指定删除器
template<class T>
shared_ptr<T> make_shared_array(size_t size)
{
	//return shared_ptr<T>(new T[size], default_delete<T[]>());// default_delete<T[]>()默认删除器
	//也可以用下面这个删除器，建议用下面的这个，理由是，T不一定是系统基本变凉类型
	return shared_ptr<T>(new T[size], [](T* p){delete[] p; }); //指定delete[]
}

template <class T>
class Slist
{
public:
	typedef T* Iterator;
	//构造函数
	Slist();
	Slist(unsigned int size);
	Slist(unsigned int size, T initial);
	Slist(const Slist<T>& s);
	//析构函数
	~Slist();

	unsigned int size();//返回大小  
	unsigned int capacity() const;//返回容量 
	bool empty() const;//判断是否为空 
	void clear();//	清除所有数据 
	Iterator begin();//返回指向开始位置的迭代器 
	Iterator end();//返回指向结束位置的迭代器
	T& front();//返回表的前端对象 
	T& back();//返回表的末尾对象
	void push_back(const T& value);//在表的末尾添加value
	void pop_back();//删除表末尾对象

	void reserve(unsigned int capacity);//重新设置存储空间
	void resize(unsigned int size);//重新设置大小

	void insert(const T& element, unsigned int index);//在指定位置插入一个元素  输入元素和位置，无返回值
	bool remove(unsigned int index );//移除第index对应的元素
	unsigned int find(const T& member);//查找值为member的下标位置
	T& locateValue(unsigned int index);//查找下标为index对应的值
	void print();

	//重载运算符
	T & operator [](unsigned int index);
	Slist<T> & operator = (const Slist<T> &s);
private:
	unsigned int _size;
	unsigned int _capacity;
	unsigned int  Log;
	//T* buffer;
	shared_ptr<T> buffer;
	
};

//构造函数
template <class T>
Slist<T>::Slist()
{
	_size = 0;
	_capacity = 0;
	Log = 0;
	//shared_ptr<T> buffer(new T(_capacity));
	buffer = 0;
}
//构造函数
template <class T>
Slist<T>::Slist(unsigned int size)
{
	_size = size;
	Log = ceil( log((double)size) / log(2.0) );
	_capacity = 1 << Log;
	//buffer = new T[_capacity];
	buffer = make_shared_array<T>(_capacity);
}
//构造函数
template <class T>
Slist<T>::Slist(unsigned int size, T initial)
{
	_size = size;
	Log = ceil(log((double)size) / log(2.0));
	_capacity = 1 << Log;
	//delete[] buffer;
	//buffer = new T[_capacity];
	buffer = make_shared_array<T>(_capacity);
	for (unsigned int i = 0; i < size; i++)
		buffer.get()[i] = initial;	
}
//复制构造函数
template <class T>
Slist<T>::Slist(const Slist<T>& s)
{
	_size = s._size;
	_capacity = s._capacity;
	Log = s.Log;
	//delete[] buffer;
	//buffer = new T[_capacity];
	buffer = make_shared_array<T>(_capacity);
	for (unsigned int i = 0; i < size; i++)
		buffer.get()[i] = s.buffer[i];
}
//析构函数
template <class T>
Slist<T>::~Slist()
{
	//delete[] buffer;
	
	cout << "释放内存" << endl;
}
//description：重载operator []
template <class T>
T& Slist<T>::operator [](unsigned int index)
{
	return buffer.get()[index];
}
//description：重载operator =
template <class T>
Slist<T>& Slist<T>::operator = (const Slist<T> &s)
{
	//delete[] buffer;
	_size = s._size;
	_capacity = s._capacity;
	Log = s.Log;
	//buffer = new T[_capacity];
	buffer = make_shared_array<T>(_capacity);
	for (unsigned int i = 0; i < _size; i++)
		buffer.get()[i] = s.buffer[i];
	return *this;
}
//name：size（）
//description：返回对象的大小
template <class T>
unsigned int Slist<T>::size()
{
	return _size;
}
//name：capacity()
//description：返回对象容量大小
template <class T>
unsigned int Slist<T>::capacity() const
{
	return _capacity;
}
//name：empty()
//description：判断是否为空
template <class T>
bool Slist<T>::empty() const
{
	return _size == 0;
}
//name：clear()
//description：清空类
template <class T>
void Slist<T>::clear()
{
	_size = 0;
	_capacity = 0;
	Log = 0;
	buffer = 0;
	//this->~Slist<T>();
}
//name：begin()
//description：返回指向开始位置的迭代器 
template <class T>
typename  Slist<T>::Iterator Slist<T>::begin()
{
	return buffer.get();
}
//name：begin()
//description：返回指向结束位置的迭代器 
//note：与vector指向末尾的下一个位置不一样  这个就是最后一个元素的位置 
template <class T>
typename Slist<T>::Iterator Slist<T>::end()
{
	return buffer.get() + (size()-1);
}
//name：front()
//description：返回表的前端对象 
template <class T>
T& Slist<T>::front()
{
	return buffer.get()[0];
}
//name：back()
//description：返回表的末尾对象
template <class T>
T& Slist<T>::back()
{
	return buffer.get()[_size-1];
}
//name：reserve（）
//description：//重新设置存储空间
template <class T>
void Slist<T>::reserve(unsigned int capacity)
{
	_capacity = capacity;
	//T* newbuffer = new T(_capacity);	
	shared_ptr<T> newbuffer = make_shared_array<T>(_capacity);
	for (unsigned int i = 0; i < _size; i++)
		newbuffer.get()[i] = buffer.get()[i];
	//delete [] buffer;
	buffer = newbuffer;
}
//name：resize（）
//description：重新设置大小
template <class T>
void Slist<T>::resize(unsigned int size)
{
	if (size < _size)
		return;
	//delete[] buffer;
	_size = size;
	Log = ceil(log((double)size) / log(2.0));
	_capacity = 1 << Log;
	//buffer = new T(_capacity);
	buffer = make_shared_array<T>(_capacity);
}
//name：push_back（）
//description：表末尾位置插入
template <class T>
void Slist<T>::push_back(const T& value)
{
	if(_size > _capacity|| _size==_capacity)
	{
		reserve(1 << ++Log);
	}
	buffer.get()[_size++] = value;
}
//name：pop_back()
//description：删除表末尾对象
template <class T>
void Slist<T>::pop_back()
{
	_size--;
}
//name：insert()
//description：在指定位置插入一个元素
template <class T>
void Slist<T>::insert(const T& element, unsigned int index)
{
	if (index > _size)
		return;
	if (_size >= _capacity)
	{
		reserve(1 << ++Log);
	}
	for (unsigned int i = _size; i >= index; i--)
	{
		buffer.get()[i] = buffer.get()[i-1];
	}
	buffer.get()[index-1] = element;
	return;
}
//name：find()
//description：查找的某值对应表中的位置
//input：要查找的值
template <class T>
unsigned int Slist<T>::find(const T& member)
{
	for (unsigned int i = 0; i < _size; i++)
	{
		if(buffer.get()[i] == member)
			return (i+1);
	}
	return -1;
}
//name：remove()
//description：移除第index对应的元素
template <class T>
bool Slist<T>::remove(unsigned int index)
{
	if (index > _size || index < 0)
		return false;
	for (unsigned int i = index; i < _size; i++)
	{
		int z = buffer.get()[i + 1];
		buffer.get()[i-1] = buffer.get()[i];
	}
	return true;

}
//name：locateValue()
//description：查找下标为index对应的值
template <class T>
T& Slist<T>::locateValue(unsigned int index)
{
	if (index<0 || index>_size)
	{
		//cerr << "out of range" << endl;
		//throw runtime_error("out of range");

	}
	return buffer.get()[--index];
}

template <class T>
void Slist<T>::print()
{
	for (int i = 0; i < _size; i++)
		cout << "第" << i << "位置元素：" << buffer.get()[i] << endl;
}
