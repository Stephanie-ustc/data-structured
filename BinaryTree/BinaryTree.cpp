// BinaryTree.cpp : 定义控制台应用程序的入口点。
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

	cout << "== 依次添加: ";
	ilen = TBL_SIZE(arr);
	for (i = 0; i<ilen; i++)
	{
		cout << arr[i] << " ";
		tree->insert(arr[i]);
	}

	cout << "\n== 前序遍历: ";
	tree->preOrder();

	cout << "\n== 中序遍历: ";
	tree->inOrder();

	cout << "\n== 后序遍历: ";
	tree->postOrder();
	cout << endl;

	cout << "== 最小值: ";
	cout << tree->minimum() << endl;
	cout << "== 最大值: ";
	cout << tree->maximum() << endl;
	cout << "== 树的详细信息: " << endl;
	tree->print();

	cout << "\n== 删除根节点: " << arr[1];
	tree->remove(arr[1]);

	cout << "\n== 中序遍历: ";
	tree->inOrder();
	cout << endl;

	BSTNode<int> *a = NULL;
	a = new BSTNode<int>(8, NULL, NULL, NULL);

	tree->predecessor(a);
	tree->successor(a);

	// 销毁二叉树
	//tree->destroy();

	tree->insert(14);
	cout << "== insert后树的详细信息: " << endl;
	tree->print();

	//tree->iterativeSearch(8);
	//(*tree).search(9);
	tree->remove(8);



	return 0;
}

