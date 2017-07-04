// SquenceStack.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
//#include"SequenceStack.h"
#include"MazeSolveMethod.h"
#include<string>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	/*SequenceStack<int> s1(1);
	
	//s1.reserve(2);
	s1.Push(22);
	s1.Push(33);
	s1.Push(44);
	s1.Push(55);
	//s1.Pop();
	//int a = s1.PopE();
	//int b = s1.GetTop();
	//s1.ClearStack();
	s1.Print();
	
	//s1.~SequenceStack();
	//s1.Print();*/

	/*********输入一个非负的十进制数，输出等值的k进制数*********/
	int i = 0;
	int k = 8;
	SequenceStack<int> s(10);
	cout << "请输入一个非负的十进制数：" ;
	cin >> i;
	if (i < 0)
	{
		cout << "输入的数不符合规则" << endl;
		return -1;
	}
	while (i)
	{
		s.Push(i % k);
		i = i / k;
	}
	cout << "等值的" << k << "进制数为：" ;
	while (!s.IsEmpty())
	{
		int tmp = s.PopE();
		cout << tmp;
	}


	/************括号匹配************/
	/*1. 括号匹配的四种可能性：

		①左右括号配对次序不正确
		②右括号多于左括号
		③左括号多于右括号
		④左右括号匹配正确

	  2.  算法思想：
		顺序扫描算数表达式（表现为一个字符串），当遇到三种类型的左括号时候让该括号进栈；
		当扫描到某一种类型的右括号时，比较当前栈顶元素是否与之匹配，若匹配，退栈继续判断；
		若当前栈顶元素与当前扫描的括号不匹配，则左右括号配对次序不正确；
		若字符串当前为某种类型的右括号而堆栈已经空，则右括号多于左括号；
		字符串循环扫描结束时，若堆栈非空（即堆栈尚有某种类型的左括号），则说明左括号多于右括号；
		否则，括号配对正确。*/

	/*SequenceStack<int> stack(10);
	string s;
	cout << "请输入一系列括号表达式：";
	cin >> s;
	int i;
	int length = s.length();
	for (i = 0; i < length; i++)
	{
		if (s[i] == '(' || s[i] == '{' || s[i] == '[')
			stack.Push(s[i]);
		else if (s[i] == ')'&&!stack.IsEmpty() && stack.PopE() == '(')
			cout << "()匹配成功" << endl;
		else if (s[i] == ')'&&!stack.IsEmpty() && stack.PopE() != '(')
			cout << "括号不匹配" << endl;
		else if (s[i] == '}'&&!stack.IsEmpty() && stack.PopE() == '{')
			cout << "{}匹配成功" << endl;
		else if (s[i] == ')'&&!stack.IsEmpty() && stack.PopE() != '{')
			cout << "括号不匹配" << endl;
		else if (s[i] == ']'&&!stack.IsEmpty() && stack.PopE() == '[')
			cout << "[]匹配成功" << endl;
		else if (s[i] == ']'&&!stack.IsEmpty() && stack.PopE() != '[')
			cout << "括号不匹配" << endl;
		else if ((s[i] == ')' || s[i] == '}' || s[i] == ']') && stack.IsEmpty())
			cout << "右括号多于左括号" << endl;
	}
	if (i == length && stack.IsEmpty())
		cout << "完美匹配" << endl;
	else if (!stack.IsEmpty())
		cout << "左括号多于右括号" << endl;*/






	/********迷宫**********/
	/*MazeSolveMethod solve;
	solve.findPath(1, 1);
	solve.printPath();*/
	

	return 0;
}

