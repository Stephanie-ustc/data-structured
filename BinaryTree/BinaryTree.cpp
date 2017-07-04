// BinaryTree.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include "BSTree.h"
using namespace std;

static int arr[] = { 15, 10, 16, 8, 13, 7,9 };
#define TBL_SIZE(a) ( (sizeof(a)) / (sizeof(a[0])) )

int _tmain(int argc, _TCHAR* argv[])
{
	int i, ilen;
	BSTree<int>* tree = new BSTree<int>();

	cout << "== �������: ";
	ilen = TBL_SIZE(arr);
	for (i = 0; i<ilen; i++)
	{
		cout << arr[i] << " ";
		tree->insert(arr[i]);
	}

	cout << "\n== ǰ�����: ";
	tree->preOrder();

	cout << "\n== �������: ";
	tree->inOrder();

	cout << "\n== �������: ";
	tree->postOrder();
	cout << endl;

	cout << "== ��Сֵ: ";
	cout << tree->minimum() << endl;
	cout << "== ���ֵ: ";
	cout << tree->maximum() << endl;
	cout << "== ������ϸ��Ϣ: " << endl;
	tree->print();

	cout << "\n== ɾ�����ڵ�: " << arr[1];
	tree->remove(arr[1]);

	cout << "\n== �������: ";
	tree->inOrder();
	cout << endl;

	BSTNode<int> *a = NULL;
	a = new BSTNode<int>(8, NULL, NULL, NULL);

	tree->predecessor(a);
	tree->successor(a);

	// ���ٶ�����
	//tree->destroy();

	tree->insert(14);
	cout << "== insert��������ϸ��Ϣ: " << endl;
	tree->print();

	//tree->iterativeSearch(8);
	//(*tree).search(9);
	tree->remove(8);



	return 0;
}

