#pragma once
#include <iostream>
#include <string>
#include <exception>
using namespace std;

//�Զ����쳣��
class CycleLinkListException : public exception  //ר���ṩ���ⲿʹ�õģ����������ڲ���  
{
public:
	CycleLinkListException(string msg) : m_msg(msg) {}
	const char * what() const throw () { return m_msg.c_str(); }//����
private:
	string m_msg;
};

template<typename T>
class CycleLinkList   //ѭ��������
{
private:
	class Node    //�ڵ���
	{
	public:		  //��ʼ������һ���ڵ�
		Node(T d, Node* n = NULL) : data(d), next(n) {}
	public:
		T data;
		Node* next;
	};
public:
	CycleLinkList(T initNodeValue = 0);
	~CycleLinkList();
public:
	bool IsEmpty();							//�жϱ��Ƿ�Ϊ��
	int Size();								//��ȡԪ�ظ���
	void AddFromHead(T e);		//������ݣ�ͷ��ӣ�
	void AddFromTail(T e);		//������ݣ�β��ӣ�
	void Insert(int local, T e);	//�������ݣ�ָ��λ�ã�
	void DeleteFromLocal(int local);		//ɾ������ ��ָ��λ�ã�
	void DeleteFromElement(T e);			//ɾ������ ��ָ��Ԫ�أ�
	int SearchFromElmemt(T e);				//����ָ��Ԫ�ز��ң�����λ��
	T SearchFromLocal(int local);			//����λ�ò���ָ��Ԫ��  
	void Reverse1();						//��ת����1
	void Reverse2();						//��ת����2
	void Print();							//����Ԫ��
	void CopyList(CycleLinkList<T>& sl);	//���Ʊ�
	void Rewrite(int local, T e);			//�޸�Ԫ��
	void ClearLinkList();                   //�������
	Node* GetNode(int local);            //��ȡָ��λ�õĽڵ�
	void SortByAsc();                       //��������
	void SortByDesc();                      //��������
	Node* GetTailNode();                 //��ȡ���һ���ڵ�
	void MergeList(CycleLinkList<T>& sl);   //�ϲ�����(����)����ı�ԭ��
	void MergeListOrder(CycleLinkList<T>& sl, bool bAsc = true); //�ϲ�����(����)
	void MergeListNoChange(CycleLinkList<T>& sl); //�ϲ�����(����)������ı�ԭ��
	void MergeListNoChangeOrder(CycleLinkList<T>& sl, bool bAsc = true); //�ϲ�����(����),����ı�ԭ��
private:
	int GetLocal(T e);						//����Ԫ��λ��
	void SelectSort(bool bAsc = true);      //ѡ������
	void InitList();                        //��ʼ������
private:
	Node* m_head;   //ͷ�ڵ�
	Node* m_tail;   //β�ڵ�(���ֻ��ָ�����һ���ڵ㣬���������һ���ڵ�ָ��β�ڵ�)
	int m_iCount;      //�����С
	T m_initNodeValue; //��ʼ���ڵ��ֵ,���û������������򵱳�ʼ��string��ʱ��ʵ������ʱ������
};

template<typename T>
CycleLinkList<T>::CycleLinkList(T initNodeValue)
{
	m_initNodeValue = initNodeValue;
	InitList();    //��ʼ������
}

template<typename T>
CycleLinkList<T>::~CycleLinkList()
{
	delete m_head;                   //ɾ��ͷ�ڵ�  
	delete m_tail;                   //ɾ��βָ��
}

//��ʼ������
template<typename T>
void CycleLinkList<T>::InitList()
{
	m_iCount = 0;
	m_head = new Node(m_initNodeValue);//����ͷ�ڵ�
	m_tail = new Node(m_initNodeValue);//����β�ڵ�
	m_head->next = m_head;                //��ʼ����ʱ���Լ�ָ���Լ�
}

//�жϱ��Ƿ�Ϊ��
template<typename T>
bool CycleLinkList<T>::IsEmpty()
{
	return m_iCount ? false : true;
}

//��ȡԪ�ظ���
template<typename T>
int CycleLinkList<T>::Size()
{
	return m_iCount;
}

//������ݣ�ͷ��ӣ�
template<typename T>
void CycleLinkList<T>::AddFromHead(T e)
{
	Node* node = new Node(e);
	if (IsEmpty()) //�������Ϊ�գ���βָ��ָ���һ����ӽ����Ľڵ�
		m_tail->next = node;
	node->next = m_head->next;
	m_head->next = node;
	++m_iCount;
}

//������ݣ�β��ӣ�
template<typename T>
void CycleLinkList<T>::AddFromTail(T e)
{
	if (IsEmpty())                      //�������Ϊ����ֱ�ӵ���AddFromHead��������һ��������ÿ�ָ��
		AddFromHead(e);
	else
	{
		Node* node = new Node(e);
		m_tail->next->next = node;          //ֱ�Ӱ��µĽڵ��������ĩβ
		node->next = m_head;				//���һ���ڵ�ָ��head
		m_tail->next = node;				//tailָ�����һ���ڵ�
		++m_iCount;
	}
}

//�������ݣ�ָ��λ�ã�
template<typename T>
void CycleLinkList<T>::Insert(int local, T e)
{
	if (local < m_iCount && local >= 0)
	{
		Node* node = new Node(e);
		Node* cur = m_head;   //ע�⣬����ǧ������m_head->next,��Ϊ�����ǰ����Ϊ�ղ����λ��
		//��0�����ֱ��ִ��cur->next������ʽ�������ÿ�ָ������	
		for (int i = 0; i < local; i++, cur = cur->next); //������local���λ��
		node->next = cur->next;
		cur->next = node;       //����Ĳ����ͺ�ͷ���һ��,���Ǹı�ָ��
		++m_iCount;
	}
	else if (local == m_iCount)//����ǲ���β����ֱ�ӵ���AddFromTail��������
		AddFromTail(e);

}

//����Ԫ��λ��
template<typename T>
int CycleLinkList<T>::GetLocal(T e)
{
	Node* cur = m_head->next;
	for (int i = 0; i < m_iCount; i++, cur = cur->next)
	if (cur->data == e)
		return i;
	return -1;
}

//ɾ������ ��ָ��λ�ã�
template<typename T>
void CycleLinkList<T>::DeleteFromLocal(int local)
{
	if (local < m_iCount && local >= 0) //��ɾ����λ�úϷ���ʱ��Ž���ɾ������
	{
		Node* pre = m_head;
		Node* cur = m_head->next;
		for (int i = 0; i < local; i++, cur = cur->next, pre = pre->next);  //������ָ��λ��
		Node* temp = cur;
		pre->next = temp->next;  //����:pre->cur->next,����ֱ����pre->next��Ȼ���ͷŵ�cur
		delete cur;
		--m_iCount;
	}
	else
		throw CycleLinkListException("ɾ����λ�ò����ڣ�ɾ������ʧ��.");
}

//ɾ������ ��ָ��Ԫ�أ�
template<typename T>
void CycleLinkList<T>::DeleteFromElement(T e)
{
	int local = GetLocal(e);
	DeleteFromLocal(local);
}

//����ָ��Ԫ�ز��ң�����λ��
template<typename T>
int CycleLinkList<T>::SearchFromElmemt(T e)
{
	return GetLocal(e);
}

//����λ�ò���ָ��Ԫ��
template<typename T>
T CycleLinkList<T>::SearchFromLocal(int local)
{
	if (local < m_iCount && local >= 0)//��������λ�úϷ���ʱ��Ž�����������
	{
		Node* cur = m_head->next;
		for (int i = 0; i < local; i++, cur = cur->next);
		return cur->data;
	}
	else
		throw CycleLinkListException("���ҵ�λ�ò����ڣ����Ҳ���ʧ��.");
}

//��ת��(����1������ʱ�任ȡ�ռ䣬�ٶȺ�����ʱ�临�Ӷ�Ϊ0(n^2))
template<typename T>
void CycleLinkList<T>::Reverse1()
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
void CycleLinkList<T>::Reverse2()
{
	Node* tHead = new Node(m_initNodeValue);     //��ʱͷ�ڵ�
	Node* tTail = new Node(m_initNodeValue);     //��ʱβ�ڵ�
	tHead->next = tHead;
	Node* cur = m_head->next;
	for (int i = 0; i < m_iCount; i++)
	{
		Node* node = new Node(cur->data);
		if (i == 0)
		{
			tTail->next = node;               //һ��ʼ����tTailָ�����һ���ڵ�
			node->next = tHead;               //���һ���ڵ�ָ��ͷ�ڵ�
		}
		node->next = tHead->next;			  //�������ͷ��ӣ������󣬾ͻ��Զ���ת������         
		tHead->next = node;
		cur = cur->next;
	}
	m_head = tHead;   //��Ϊͷ����Ѿ�����ת�ˣ�����ֱ�Ӱ�ͷ�ڵ��β�ڵ�ĵ�ַ��ֵ����Ա��������
	m_tail = tTail;   //ע�⣬һ��Ҫͷβͬʱ��ֵ����Ȼ���ǵ�ָ������ˡ�
}

//����Ԫ��
template<typename T>
void CycleLinkList<T>::Print()
{
	Node* cur = m_head;
	int i = 0;
	while ((i++ != m_iCount) && (cur = cur->next) != m_head) //��ֹ�ϲ������б��ϲ��ı��ɵ�����������ѭ��
		cout << cur->data << endl;
}

//���Ʊ�
template<typename T>
void CycleLinkList<T>::CopyList(CycleLinkList<T>& sl)
{
	Node* cur = m_head->next;
	for (int i = 0; i < m_iCount; i++, cur = cur->next)
		sl.AddFromTail(cur->data);
}

//�޸�Ԫ��
template<typename T>
void CycleLinkList<T>::Rewrite(int local, T e)
{
	if (local < m_iCount && local >= 0)
	{
		Node* cur = m_head->next;
		for (int i = 0; i < local; i++, cur = cur->next);
		cur->data = e;
	}
	else
		throw CycleLinkListException("�޸ĵ�λ�ò����ڣ��޸Ĳ���ʧ��.");
}

//�������
template<typename T>
void CycleLinkList<T>::ClearLinkList()
{
	Node* cur = m_head->next;
	for (int i = 0; i < m_iCount; i++)
	{
		Node* temp;
		temp = cur;         //����ǰһ���ڵ�ĵ�ַ 
		cur = cur->next;    //��ǰ������һ���ڵ�
		delete temp;        //�ͷ�ǰһ���ڵ�Ŀռ�
	}
	m_iCount = 0;
	m_head->next = m_head;
	m_tail->next = NULL;
}

//��ȡָ��λ�õĽڵ�
template<typename T>
typename CycleLinkList<T>::Node* CycleLinkList<T>::GetNode(int local)
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
void CycleLinkList<T>::SortByAsc()
{
	SelectSort();
}

//��������
template<typename T>
void CycleLinkList<T>::SortByDesc()
{
	SelectSort(false);
}

//ѡ������
template<typename T>
void CycleLinkList<T>::SelectSort(bool bAsc)
{
	for (int i = 0; i < m_iCount; i++)
	{
		Node* node1 = GetNode(i);
		for (int j = i + 1; j < m_iCount; j++)
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

//��ȡ���һ���ڵ�
template<typename T>
typename CycleLinkList<T>::Node* CycleLinkList<T>::GetTailNode()
{
	return m_tail->next;
}

//�ϲ�����  ,��Ҫע����ǣ��ϲ���ԭ���ı�ͻᱻ�ı䡣
template<typename T>
void CycleLinkList<T>::MergeList(CycleLinkList<T>& sl)
{
	this->m_tail->next->next = sl.m_head->next;     //��1�����һ���ڵ�ָ���2�ĵ�һ���ڵ�
	this->m_tail->next = sl.m_tail->next;           //��1��βָ��ָ���������һ��Ԫ�� 
	sl.m_tail->next->next = this->m_head;			//��2�����һ���ڵ�ָ���1��head�ڵ�
	this->m_iCount += sl.m_iCount;                  //��Ҫ��Ԫ�ظ���������
}

//�ϲ�����(����)
template<typename T>
void CycleLinkList<T>::MergeListOrder(CycleLinkList<T>& sl, bool bAsc)
{
	MergeList(sl);
	SelectSort(bAsc);
}

//�ϲ�����(����)������ı�ԭ��
template<typename T>
void CycleLinkList<T>::MergeListNoChange(CycleLinkList<T>& sl)
{
	CycleLinkList<T> list(m_initNodeValue);
	sl.CopyList(list);            //��������,�����Ͳ���ı�ԭ��
	MergeList(list);
}

//�ϲ�����(����),����ı�ԭ��
template<typename T>
void CycleLinkList<T>::MergeListNoChangeOrder(CycleLinkList<T>& sl, bool bAsc = true)
{
	CycleLinkList<T> list(m_initNodeValue);
	sl.CopyList(list);            //��������,�����Ͳ���ı�ԭ��
	MergeListOrder(list, bAsc);
}