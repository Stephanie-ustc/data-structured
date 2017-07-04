//������ һ��ͷ���һ��β���
#pragma once
#include <iostream>
#include <string>
#include <exception>
using namespace std;

//�Զ����쳣��
class LinkListException : public exception  //ר���ṩ���ⲿʹ�õģ����������ڲ���  
{
public:
	LinkListException(string msg) : m_msg(msg) {}
	const char * what() const throw () { return m_msg.c_str(); }//����
private:
	string m_msg;
};

template<typename T>
class LinkList    //������
{
private://��Node��Ϊ�ڲ��࣬�����ⲿ����
	class Node    //�ڵ���
	{
	public://��ʼ������һ���ڵ�
		Node(T d, Node* n = nullptr) : data(d), next(n) {}
	private:
		T data;
		Node* next;
		friend class LinkList;
	};
public:
	LinkList(T initNode = 0);
	~LinkList();
public:
	bool IsEmpty();							//�жϱ��Ƿ�Ϊ��
	int Size();								//��ȡԪ�ظ���
	void AddFromHead(T e);		//������ݣ�ͷ��ӣ�
	void AddFromTail(T e);		//������ݣ�β��ӣ�
	void Insert(int local, T e);	//�������ݣ�ָ��λ�ã�ע����localλ��β�����
	void DeleteFromLocal(int local);		//ɾ������ ��ָ��λ�ã�
	void DeleteFromElement(T e);			//ɾ������ ��ָ��Ԫ�أ�
	int SearchFromElmemt(T e);				//����ָ��Ԫ�ز��ң�����λ��
	T SearchFromLocal(int local);			//����λ�ò���ָ��Ԫ��  
	void Reverse1();						//��ת����1
	void Reverse2();						//��ת����2
	void Print();							//����Ԫ��
	void CopyList(LinkList<T>& sl);			//���Ʊ�
	void Rewrite(int local, T e);			//�޸�Ԫ��
	void ClearLinkList();                   //�������
	Node* GetNode(int local);            //��ȡָ��λ�õĽڵ�
	void SortByAsc();                       //��������
	void SortByDesc();                      //��������
private:
	int GetLocal(T e);						//����Ԫ��λ�� ע���±��0��ʼ
	void InitList(T initNodeValue);                        //��ʼ������
	void SelectSort(bool bAsc = true);             //ѡ������
private:
	Node* m_head;	   //ͷ�ڵ�
	Node* m_tail;      //βָ��
	int m_iCount;      //�����С
	T m_initNodeValue; //��ʼ���ڵ��ֵ,���û������������򵱳�ʼ��string��ʱ��ʵ������ʱ������
};

template<typename T>
LinkList<T>::LinkList(T initNodeValue)
{
	InitList(initNodeValue);
}

template<typename T>
LinkList<T>::~LinkList()
{
	delete m_head;                   //ɾ��ͷ�ڵ�  
	delete m_tail;
}

//��ʼ������
template<typename T>
void LinkList<T>::InitList(T initNodeValue)
{
	m_iCount = 0;
	m_initNodeValue = initNodeValue;
	m_head = new Node(m_initNodeValue);//����ͷ�ڵ�
	m_tail = new Node(m_initNodeValue);
}

//�жϱ��Ƿ�Ϊ��
template<typename T>
bool LinkList<T>::IsEmpty()
{
	return m_iCount ? false : true;
}

//��ȡԪ�ظ���
template<typename T>
int LinkList<T>::Size()
{
	return m_iCount;
}
//������ݣ�ͷ��ӣ�
template<typename T>
void LinkList<T>::AddFromHead(T e)
{
	Node* node = new Node(e);
	if (IsEmpty())//�������Ϊ�գ���һ����ӵ�ʱ�򣬾���βָ��ָ���һ����ӵĽڵ�
		m_tail->next = node;
	node->next = m_head->next;
	m_head->next = node;
	++m_iCount;
}

//������ݣ�β��ӣ�
template<typename T>
void LinkList<T>::AddFromTail(T e)
{
	if (IsEmpty())
		AddFromHead(e);
	else
	{
		Node* node = new Node(e);
		m_tail->next->next = node;//�����һ���ڵ�ָ����������Ľڵ�??? 
		m_tail->next = node;	  //�޸�tail��ָ��
		++m_iCount;
	}
}

//�������ݣ�ָ��λ�ã�
template<typename T>
void LinkList<T>::Insert(int local, T e)
{
	if (local < m_iCount && local >= 0)
	{
		Node* cur = m_head;   //ע�⣬����ǧ������m_head->next,��Ϊ�����ǰ����Ϊ�ղ����λ��
		//��0�����ֱ��ִ��cur->next������ʽ�������ÿ�ָ������
		Node* node = new Node(e);
		for (int i = 0; i < local; i++, cur = cur->next); //������local���λ��,��ѭ����
		node->next = cur->next;
		cur->next = node;       //����Ĳ����ͺ�ͷ���һ��,���Ǹı�ָ��
		++m_iCount;
	}
	else if (local == m_iCount)//����ǲ���β����ֱ�ӵ���AddFromTail��������
		AddFromTail(e);
}

//����Ԫ��λ��
template<typename T>
int LinkList<T>::GetLocal(T e)
{
	Node* cur = m_head->next;	
	for (int i = 0; i < m_iCount; i++, cur = cur->next)
		if (cur->data == e)
			return i;
	return -1;
}

//ɾ������ ��ָ��λ�ã�
template<typename T>
void LinkList<T>::DeleteFromLocal(int local)
{
	if (local < m_iCount && local >= 0) //��ɾ����λ�úϷ���ʱ��Ž���ɾ������
	{
		Node* pre = m_head;
		Node* cur = m_head->next;
		for (int i = 0; i < local; i++, cur = cur->next, pre = pre->next);  //������ָ��λ��
		Node* temp = cur;
		pre->next = temp->next;  //����:pre->cur->next,����ֱ����pre->next��Ȼ���ͷŵ�cur
		if (pre->next == NULL)  //�����ɾ�����һ��Ԫ�أ�����Ҫ�޸�βָ��
			m_tail->next = pre;//???
		delete cur;
		--m_iCount;
	}
}

//ɾ������ ��ָ��Ԫ�أ�
template<typename T>
void LinkList<T>::DeleteFromElement(T e) 
{
	int local = GetLocal(e);
	DeleteFromLocal(local);
}

//����ָ��Ԫ�ز��ң�����λ��
template<typename T>
int LinkList<T>::SearchFromElmemt(T e)
{
	return GetLocal(e);
}

//����ָ��λ�õ�Ԫ��
template<typename T>
T LinkList<T>::SearchFromLocal(int local)
{
	Node* node = GetNode(local);
	if (node)
		return node->data;
	else
		throw LinkListException("���ҵ�λ�ò����ڣ�����ʧ��.");
}
//��ת��(����1������ʱ�任ȡ�ռ䣬�ٶȺ�����ʱ�临�Ӷ�Ϊ0(n^2))
template<typename T>
void LinkList<T>::Reverse1()
{
	T temp;
	for (int i = 0; i < m_iCount / 2; i++)
	{
		Node* node1 = GetNode(i);                //��ȡ�ڵ�
		Node* node2 = GetNode(m_iCount - i - 1);
		temp = node1->data;                         //���������ǧ��𽻻��ڵ�
		node1->data = node2->data;
		node2->data = temp;
	}
}

//��ת��(����2�������ռ任ȡʱ�䣬�ٶȺܿ죬ʱ�临�Ӷ�Ϊ0(n))
template<typename T>
void LinkList<T>::Reverse2()
{
	Node* tHead = new Node(m_initNodeValue);     //��ʱͷ�ڵ�
	Node* cur = m_head->next;
	for (int i = 0; i < m_iCount; i++)
	{
		Node* node = new Node(cur->data);     //�����µĽڵ�
		node->next = tHead->next;			  //�������ͷ��ӣ������󣬾ͻ��Զ���ת������         
		tHead->next = node;
		cur = cur->next;
	}
	memcpy(m_head, tHead, sizeof(Node));   //��Ϊͷ����Ѿ�����ת�ˣ�����ֱ�Ӹ��Ƶ�ԭ���������м���
	delete tHead;
}

//����Ԫ��
template<typename T>
void LinkList<T>::Print()
{
	cout << "������Ԫ�طֱ��ǣ�"<< endl;
	Node* cur = m_head;
	while (cur = cur->next)
		cout << cur->data << endl;
}

//���Ʊ�
template<typename T>
void LinkList<T>::CopyList(LinkList<T>& sl)
{
	Node* cur = m_head->next;
	for (int i = 0; i < m_iCount; i++, cur = cur->next)
		sl.AddFromTail(cur->data);
}

//�޸�Ԫ��
template<typename T>
void LinkList<T>::Rewrite(int local, T e)
{
	Node* node = GetNode(local);
	if (node)
		node->data = e;
}

//�������
template<typename T> 
void LinkList<T>::ClearLinkList()
{
	Node* cur = m_head->next;
	for (int i = 0; i < m_iCount; i++)
	{
		Node* temp;
		temp = cur;         //����ǰһ���ڵ�ĵ�ַ 
		cur = cur->next;    //��ǰ������һ���ڵ�
		delete temp;        //�ͷ�ǰһ���ڵ�Ŀռ�
	}
	m_head->next = NULL;       //�����ͷ�ڵ�ָ��NULL
	m_tail->next = NULL;
}


/*
*    GetNode��������ķ���ֵҪע�⣬һ��Ҫ�������ָ�ʽд
*    C++ģ���һ�����ԣ������������Ʋ�����Ϊ����ʹ�ã�������ǰ����� typename�ؼ���
*    �������ƣ�����ģ�����Ͳ���<T>
*    �������ƣ����С�::������
*    ����Nodeǰ��һ��Ҫ��::��<T>ǰ��һ��Ҫ��typename�ؼ���
*/
//��ȡָ��λ�õĽڵ�
template<typename T>
typename LinkList<T>::Node* LinkList<T>::GetNode(int local)
{
	if (local < m_iCount && local >= 0)//����ȡ��λ�úϷ���ʱ��Ž��л�ȡ����
	{
		Node* cur = m_head->next;
		for (int i = 0; i < local; i++, cur = cur->next);
		return cur;
	}
	else
		return NULL;
}

//��������
template<typename T>
void LinkList<T>::SortByAsc()
{
	SelectSort();
}

//��������
template<typename T>
void LinkList<T>::SortByDesc()
{
	SelectSort(false);
}

// ѡ������
template<typename T>
void LinkList<T>::SelectSort(bool bAsc)
{
	for (int i = 0; i < m_iCount; i++)
	{
		Node* node1 = GetNode(i);
		for (int j = i + 1; j<m_iCount; j++)
		{
			Node* node2 = GetNode(j);
			T temp;
			if (bAsc)   //����
			{
				if (node1->data > node2->data)
				{
					temp = node1->data;
					node1->data = node2->data;
					node2->data = temp;
				}
			}
			else        //����
			{
				if (node1->data < node2->data)
				{
					temp = node1->data;
					node1->data = node2->data;
					node2->data = temp;
				}
			}
		}
	}
}