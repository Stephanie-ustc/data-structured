#include<iostream>
#include <memory>
using namespace std;

// ����һ��������Ŀ������shared_ptr���Թ���һ����̬���飬��Ҫָ��ɾ����
template<class T>
shared_ptr<T> make_shared_array(size_t size)
{
	//return shared_ptr<T>(new T[size], default_delete<T[]>());// default_delete<T[]>()Ĭ��ɾ����
	//Ҳ�������������ɾ���������������������������ǣ�T��һ����ϵͳ������������
	return shared_ptr<T>(new T[size], [](T* p){delete[] p; }); //ָ��delete[]
}

template <class T>
class Slist
{
public:
	typedef T* Iterator;
	//���캯��
	Slist();
	Slist(unsigned int size);
	Slist(unsigned int size, T initial);
	Slist(const Slist<T>& s);
	//��������
	~Slist();

	unsigned int size();//���ش�С  
	unsigned int capacity() const;//�������� 
	bool empty() const;//�ж��Ƿ�Ϊ�� 
	void clear();//	����������� 
	Iterator begin();//����ָ��ʼλ�õĵ����� 
	Iterator end();//����ָ�����λ�õĵ�����
	T& front();//���ر��ǰ�˶��� 
	T& back();//���ر��ĩβ����
	void push_back(const T& value);//�ڱ��ĩβ���value
	void pop_back();//ɾ����ĩβ����

	void reserve(unsigned int capacity);//�������ô洢�ռ�
	void resize(unsigned int size);//�������ô�С

	void insert(const T& element, unsigned int index);//��ָ��λ�ò���һ��Ԫ��  ����Ԫ�غ�λ�ã��޷���ֵ
	bool remove(unsigned int index );//�Ƴ���index��Ӧ��Ԫ��
	unsigned int find(const T& member);//����ֵΪmember���±�λ��
	T& locateValue(unsigned int index);//�����±�Ϊindex��Ӧ��ֵ
	void print();

	//���������
	T & operator [](unsigned int index);
	Slist<T> & operator = (const Slist<T> &s);
private:
	unsigned int _size;
	unsigned int _capacity;
	unsigned int  Log;
	//T* buffer;
	shared_ptr<T> buffer;
	
};

//���캯��
template <class T>
Slist<T>::Slist()
{
	_size = 0;
	_capacity = 0;
	Log = 0;
	//shared_ptr<T> buffer(new T(_capacity));
	buffer = 0;
}
//���캯��
template <class T>
Slist<T>::Slist(unsigned int size)
{
	_size = size;
	Log = ceil( log((double)size) / log(2.0) );
	_capacity = 1 << Log;
	//buffer = new T[_capacity];
	buffer = make_shared_array<T>(_capacity);
}
//���캯��
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
//���ƹ��캯��
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
//��������
template <class T>
Slist<T>::~Slist()
{
	//delete[] buffer;
	
	cout << "�ͷ��ڴ�" << endl;
}
//description������operator []
template <class T>
T& Slist<T>::operator [](unsigned int index)
{
	return buffer.get()[index];
}
//description������operator =
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
//name��size����
//description�����ض���Ĵ�С
template <class T>
unsigned int Slist<T>::size()
{
	return _size;
}
//name��capacity()
//description�����ض���������С
template <class T>
unsigned int Slist<T>::capacity() const
{
	return _capacity;
}
//name��empty()
//description���ж��Ƿ�Ϊ��
template <class T>
bool Slist<T>::empty() const
{
	return _size == 0;
}
//name��clear()
//description�������
template <class T>
void Slist<T>::clear()
{
	_size = 0;
	_capacity = 0;
	Log = 0;
	buffer = 0;
	//this->~Slist<T>();
}
//name��begin()
//description������ָ��ʼλ�õĵ����� 
template <class T>
typename  Slist<T>::Iterator Slist<T>::begin()
{
	return buffer.get();
}
//name��begin()
//description������ָ�����λ�õĵ����� 
//note����vectorָ��ĩβ����һ��λ�ò�һ��  ����������һ��Ԫ�ص�λ�� 
template <class T>
typename Slist<T>::Iterator Slist<T>::end()
{
	return buffer.get() + (size()-1);
}
//name��front()
//description�����ر��ǰ�˶��� 
template <class T>
T& Slist<T>::front()
{
	return buffer.get()[0];
}
//name��back()
//description�����ر��ĩβ����
template <class T>
T& Slist<T>::back()
{
	return buffer.get()[_size-1];
}
//name��reserve����
//description��//�������ô洢�ռ�
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
//name��resize����
//description���������ô�С
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
//name��push_back����
//description����ĩβλ�ò���
template <class T>
void Slist<T>::push_back(const T& value)
{
	if(_size > _capacity|| _size==_capacity)
	{
		reserve(1 << ++Log);
	}
	buffer.get()[_size++] = value;
}
//name��pop_back()
//description��ɾ����ĩβ����
template <class T>
void Slist<T>::pop_back()
{
	_size--;
}
//name��insert()
//description����ָ��λ�ò���һ��Ԫ��
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
//name��find()
//description�����ҵ�ĳֵ��Ӧ���е�λ��
//input��Ҫ���ҵ�ֵ
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
//name��remove()
//description���Ƴ���index��Ӧ��Ԫ��
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
//name��locateValue()
//description�������±�Ϊindex��Ӧ��ֵ
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
		cout << "��" << i << "λ��Ԫ�أ�" << buffer.get()[i] << endl;
}
