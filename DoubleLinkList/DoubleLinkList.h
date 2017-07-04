#pragma once
#include <iostream>
#include <string>
#include <exception>
using namespace std;

//�Զ����쳣��
class DoubleLinkListException : public exception  //ר���ṩ���ⲿʹ�õģ����������ڲ���  
{
public:
	DoubleLinkListException(string msg) : m_msg(msg) {}
	const char * what() const throw () { return m_msg.c_str(); }//����
private:
	string m_msg;
};

template<typename T>
class DoubleLinkList   //˫��������
{
private:
	class Node    //�ڵ���
	{
	public:		  //��ʼ������һ���ڵ�
		Node(T d, Node* p = NULL, Node* n = NULL) : data(d), pre(p), next(n) {}
	private:
		T data;
		Node* pre;  //ǰ���ڵ�
		Node* next; //��̽ڵ�
		friend class DoubleLinkList;
	};
public:
	DoubleLinkList(T initNodeValue = 0);
	~DoubleLinkList();
public:
	bool IsEmpty();							//�жϱ��Ƿ�Ϊ��
	int Size();								//��ȡԪ�ظ���
	void AddFromHead(T e);		            //������ݣ�ͷ��ӣ�
	void AddFromTail(T e);		            //������ݣ�β��ӣ�
	void Insert(int local, T e);	        //�������ݣ�ָ��λ�ã�
	void DeleteFromLocal(int local);		//ɾ������ ��ָ��λ�ã�
	void DeleteFromElement(T e);			//ɾ������ ��ָ��Ԫ�أ�
	int SearchFromElmemt(T e);				//����ָ��Ԫ�ز��ң�����λ��
	T SearchFromLocal(int local);			//����λ�ò���ָ��Ԫ��  
	void Reverse();							//��ת��
	void Print(bool bReverse = false);		//����Ԫ��(������������Ҳ���Ե��ű���) ע��true���� false����
	void CopyList(DoubleLinkList<T>& sl);	//���Ʊ�
	void Rewrite(int local, T e);			//�޸�Ԫ��
	void ClearLinkList();                   //�������
	Node* GetNode(int local);               //��ȡָ��λ�õĽڵ�
	void SortByAsc();                       //��������
	void SortByDesc();                      //��������
	Node* GetTailNode();                    //��ȡ���һ���ڵ�
	void MergeList(DoubleLinkList<T>& sl);   //�ϲ�����(����)����ı�ԭ��
	void MergeListOrder(DoubleLinkList<T>& sl, bool bAsc = true); //�ϲ�����(����)
	void MergeListNoChange(DoubleLinkList<T>& sl); //�ϲ�����(����)������ı�ԭ��
	void MergeListNoChangeOrder(DoubleLinkList<T>& sl, bool bAsc = true); //�ϲ�����(����),����ı�ԭ��
private:
	int GetLocal(T e);						//����Ԫ��λ��
	void SelectSort(bool bAsc = true);      //ѡ������
	void InitList();                        //��ʼ������
	void SwapNodeData(Node* node1, Node* node2); //���������ڵ������
private:
	Node* m_head;   //ͷ�ڵ�
	Node* m_tail;   //β�ڵ�(���ֻ��ָ�����һ���ڵ㣬���������һ���ڵ�ָ��β�ڵ�)
	int m_iCount;      //�����С
	T m_initNodeValue; //��ʼ���ڵ��ֵ,���û������������򵱳�ʼ��string��ʱ��ʵ������ʱ������
};

//�вι���
template<typename T>
DoubleLinkList<T>::DoubleLinkList(T initNodeValue)
{
	m_initNodeValue = initNodeValue;
	InitList();    //��ʼ������
}

template<typename T>
DoubleLinkList<T>::~DoubleLinkList()
{
	delete m_head;                   //ɾ��ͷ�ڵ�  
	m_head = NULL;
	delete m_tail;                   //ɾ��βָ��
	m_tail = NULL;
}

//��ʼ������
template<typename T>
void DoubleLinkList<T>::InitList()
{
	m_iCount = 0;
	m_head = new Node(m_initNodeValue);//����ͷ�ڵ�
	m_tail = new Node(m_initNodeValue);//����β�ڵ�
}

//�жϱ��Ƿ�Ϊ��
template<typename T>
bool DoubleLinkList<T>::IsEmpty()
{
	return m_iCount ? false : true;
}

//��ȡԪ�ظ���
template<typename T>
int DoubleLinkList<T>::Size()
{
	return m_iCount;
}

//������ݣ�ͷ��ӣ�
template<typename T>
void DoubleLinkList<T>::AddFromHead(T e)
{
	cout << "ͷ���Ԫ�أ�"<< e<<endl;
	Node* node = new Node(e);
	if (IsEmpty())				//�������Ϊ�գ���һ����ӵ�ʱ�򣬾���βָ��ָ���һ����ӵĽڵ�
	{
		m_tail->next = node;        //���� head->NULL,��������˸�node1,��node1->NULL,head->node1,�Ȱ�����������
		node->next = m_head->next;  //Ȼ��node1->head
		m_head->next = node;
		node->pre = m_head;
	}
	else
	{
		node->next = m_head->next;     //���� head->node1,��������˸�node2,��node2->node1,head->node2,�Ȱ�����������
		m_head->next = node;           //Ȼ��node1 -> node2,node2->head
		node->next->pre = node;
		node->pre = m_head;
	}
	++m_iCount;
}
//������ݣ�β��ӣ�
template<typename T>
void DoubleLinkList<T>::AddFromTail(T e)
{
	cout << "β���Ԫ�أ�" << e << endl;
	Node* node = new Node(e);
	if (IsEmpty())
		AddFromHead(e);   //����ǵ�һ����ӣ������AddFromHead����
	else
	{
		m_tail->next->next = node;  //tail.next��ʾ���һ���ڵ㣬���������˼�ǣ������һ���ڵ�ָ����������Ľڵ�
		node->pre = m_tail->next;   //��������Ľڵ��ǰ��ָ��ԭ�������һ���ڵ�
		m_tail->next = node;        //�޸�tail��ָ��
		++m_iCount;
	}
}

//�������ݣ�ָ��λ�ã�
template<typename T>
void DoubleLinkList<T>::Insert(int local, T e)
{
	cout << "�ڵ�"<<local<<"λ�ò���Ԫ��" << e << endl;
	Node* node = new Node(e);
	if (local < m_iCount && local >= 0)
	{
		Node* cur = m_head;   //ע�⣬����ǧ������m_head->next,��Ϊ�����ǰ����Ϊ�ղ����λ��
		//��0�����ֱ��ִ��cur->next������ʽ�������ÿ�ָ������	
		for (int i = 0; i < local; i++, cur = cur->next); //������local���λ��
		node->next = cur->next;			//�ڸ�λ�ò���
		cur->next = node;
		node->next->pre = node;
		node->pre = cur;
		++m_iCount;
	}
	else if (local == m_iCount)//����ǲ���β����ֱ�ӵ���AddFromTail��������
		AddFromTail(e);
}

//����Ԫ��λ��
template<typename T>
int DoubleLinkList<T>::GetLocal(T e)
{	
	Node* cur = m_head->next;
	for (int i = 0; i < m_iCount; i++, cur = cur->next)
	if (cur->data == e)
	{
		cout << "Ԫ��" << e << "λ�ڵ�" << i << "λ��" << endl;
		return i;
	}		
	return -1;
}

//ɾ������ ��ָ��λ�ã�
template<typename T>
void DoubleLinkList<T>::DeleteFromLocal(int local)
{
	cout << "ɾ��"<<local<<"λ��Ԫ��" << endl;
	if (local < m_iCount - 1 && local >= 0)   //��Ҫɾ����λ�ú��������²���ɾ��
	{
		Node* cur = m_head;
		for (int i = 0; i < local; i++)
			cur = cur->next;
		Node* temp;
		temp = cur->next;
		cur->next = temp->next;           //ɾ����λ���µ�Ԫ��
		cur->next->pre = cur;
		--m_iCount;
		delete temp;                       //�ͷŵ��ýڵ�
	}
	else if (local == m_iCount - 1)  //ɾ���������һ��Ԫ�صĻ�
	{
		Node* temp = m_tail->next;   //���һ���ڵ�
		m_tail->next = temp->pre;		//ָ�����һ���ڵ��ǰһ���ڵ�
		m_tail->next->next = NULL;      //���һ���ڵ�ָ��NULL
		--m_iCount;
		delete temp;
	}
	else
		throw DoubleLinkListException("ɾ����λ�ò����ڣ�ɾ������ʧ��.");
}

//ɾ������ ��ָ��Ԫ�أ�
template<typename T>
void DoubleLinkList<T>::DeleteFromElement(T e)
{
	int local = GetLocal(e);
	DeleteFromLocal(local);
}

//����ָ��Ԫ�ز��ң�����λ��
template<typename T>
int DoubleLinkList<T>::SearchFromElmemt(T e)
{
	return GetLocal(e);
}

//����λ�ò���ָ��Ԫ��
template<typename T>
T DoubleLinkList<T>::SearchFromLocal(int local)
{
	Node* node = GetNode(local);
	if (node)
		return node->data;
	else
		throw DoubleLinkListException("���ҵ�λ�ò����ڣ����Ҳ���ʧ��.");
}

//��ת��,ʱ�临�Ӷ�Ϊ0(n/2)
template<typename T>
void DoubleLinkList<T>::Reverse()
{
	Node* node1 = m_head->next;
	Node* node2 = m_tail->next;
	while (node1 != node2)
	{
		SwapNodeData(node1, node2);   //���������ǧ��𽻻��ڵ�
		node1 = node1->next;   //����
		node2 = node2->pre;    //��ǰ
		if (node1 == node2->pre) //���Ԫ�ظ�����ż������Ҫ�����һ����������
		{
			SwapNodeData(node1, node2);   //���������ǧ��𽻻��ڵ�
			break;
		}
	}
}
//����Ԫ��
template<typename T>
void DoubleLinkList<T>::Print(bool bReverse)
{
	cout << "˫������Ԫ�طֱ�Ϊ��" ;
	if (bReverse)  //����
	{
		Node* cur = m_tail->next;
		if (!cur) return;
		do
		{
			cout << cur->data ;
		} while ((cur = cur->pre) != m_head);
	}
	else
	{
		Node* cur = m_head;
		while (cur = cur->next)
			cout << cur->data;
	}
}

//���Ʊ�
template<typename T>
void DoubleLinkList<T>::CopyList(DoubleLinkList<T>& sl)
{
	T temp;
	for (int i = 0; i < sl.Size(); i++)
	{
		temp = sl.SearchFromLocal(i);
		(*this).AddFromTail(temp);   
	}
		
}//����sl�ý������һһ��ӵ��±���

//�޸�Ԫ��
template<typename T>
void DoubleLinkList<T>::Rewrite(int local, T e)
{
	Node* node = GetNode(local);
	if (node)
		node->data = e;
}

//�������
template<typename T>
void DoubleLinkList<T>::ClearLinkList()
{
	if (IsEmpty())
		throw DoubleLinkListException("����Ϊ�գ���ղ���ʧ��.");
	Node* cur = m_head->next;
	for (int i = 0; i < m_iCount; i++)
	{
		Node* temp;
		temp = cur;         //����ǰһ���ڵ�ĵ�ַ 
		cur = cur->next;    //��ǰ������һ���ڵ�
		delete temp;         //�ͷ�ǰһ���ڵ�Ŀռ�
	}
	m_head->next = NULL;      //�����ͷ�ڵ�ָ��NULL
	m_tail->next = NULL;
}

//��ȡָ��λ�õĽڵ�
template<typename T>
typename DoubleLinkList<T>::Node* DoubleLinkList<T>::GetNode(int local)
{
	if (local < m_iCount / 2 && local >= 0)   //���local��ǰ�벿�֣����ǰ������
	{
		Node* cur = m_head->next;
		for (int i = 0; i < local; i++)  //����
			cur = cur->next;
		return cur;
	}
	else if (local >= m_iCount / 2 && local < m_iCount - 1) //���local�ں�벿�֣���Ӻ���ǰ��
	{
		Node* cur = m_tail->next;
		for (int i = 0; i < m_iCount - local - 1; i++)  //����
			cur = cur->pre;
		return cur;
	}
	else if (local == m_iCount - 1)  //����ǲ������һ���ڵ㣬ֱ�ӷ���tailָ��Ľڵ㼴��
		return m_tail->next;
	else
		return NULL;
}
//��������
template<typename T>
void DoubleLinkList<T>::SortByAsc()
{
	SelectSort();
}

//��������
template<typename T>
void DoubleLinkList<T>::SortByDesc()
{
	SelectSort(false);
}

//ѡ������
template<typename T>
void DoubleLinkList<T>::SelectSort(bool bAsc)
{
	for (int i = 0; i < m_iCount; i++)
	{
		Node* node1 = GetNode(i);
		for (int j = i + 1; j < m_iCount; j++)
		{
			Node* node2 = GetNode(j);
			if (bAsc)   //����
			{
				if (node1->data > node2->data)
					SwapNodeData(node1, node2);
			}
			else        //����
			{
				if (node1->data < node2->data)
					SwapNodeData(node1, node2);
			}
		}
	}
}

//���������ڵ������
template<typename T>
void DoubleLinkList<T>::SwapNodeData(Node* node1, Node* node2)
{
	T temp;
	temp = node1->data;
	node1->data = node2->data;
	node2->data = temp;
}

//��ȡ���һ���ڵ�
template<typename T>
typename DoubleLinkList<T>::Node* DoubleLinkList<T>::GetTailNode()
{
	return m_tail->next;
}

//�ϲ�����  ,��Ҫע����ǣ��ϲ���ԭ���ı�ͻᱻ�ı䡣
template<typename T>
void DoubleLinkList<T>::MergeList(DoubleLinkList<T>& sl)
{
	if (IsEmpty())  //���Ŀ�ı�Ϊ��
		this->m_head->next = sl.m_head->next;  //ֱ����ͷ�ڵ�ָ���2�ĵ�һ���ڵ�
	else
	{
		this->m_tail->next->next = sl.m_head->next;     //��1�����һ���ڵ�ָ���2�ĵ�һ���ڵ�
		sl.m_head->next->pre = this->m_tail->next;      //��2�ĵ�һ���ڵ�ָ���1�����һ���ڵ�
	}
	this->m_tail->next = sl.m_tail->next;           //��1��βָ��ָ���������һ��Ԫ�� 
	this->m_iCount += sl.m_iCount;                  //��Ҫ��Ԫ�ظ���������
}

//�ϲ�����(����)
template<typename T>
void DoubleLinkList<T>::MergeListOrder(DoubleLinkList<T>& sl, bool bAsc)
{
	MergeList(sl);
	SelectSort(bAsc);
}

//�ϲ�����(����)������ı�ԭ��
template<typename T>
void DoubleLinkList<T>::MergeListNoChange(DoubleLinkList<T>& sl)
{
	DoubleLinkList<T> list(m_initNodeValue);
	sl.CopyList(list);            //��������,�����Ͳ���ı�ԭ��
	MergeList(list);
}

//�ϲ�����(����),����ı�ԭ��
template<typename T>
void DoubleLinkList<T>::MergeListNoChangeOrder(DoubleLinkList<T>& sl, bool bAsc = true)
{
	DoubleLinkList<T> list(m_initNodeValue);
	sl.CopyList(list);            //��������,�����Ͳ���ı�ԭ��
	MergeListOrder(list, bAsc);
}