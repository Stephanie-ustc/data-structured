// SquenceStack.cpp : �������̨Ӧ�ó������ڵ㡣
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

	/*********����һ���Ǹ���ʮ�������������ֵ��k������*********/
	int i = 0;
	int k = 8;
	SequenceStack<int> s(10);
	cout << "������һ���Ǹ���ʮ��������" ;
	cin >> i;
	if (i < 0)
	{
		cout << "������������Ϲ���" << endl;
		return -1;
	}
	while (i)
	{
		s.Push(i % k);
		i = i / k;
	}
	cout << "��ֵ��" << k << "������Ϊ��" ;
	while (!s.IsEmpty())
	{
		int tmp = s.PopE();
		cout << tmp;
	}


	/************����ƥ��************/
	/*1. ����ƥ������ֿ����ԣ�

		������������Դ�����ȷ
		�������Ŷ���������
		�������Ŷ���������
		����������ƥ����ȷ

	  2.  �㷨˼�룺
		˳��ɨ���������ʽ������Ϊһ���ַ��������������������͵�������ʱ���ø����Ž�ջ��
		��ɨ�赽ĳһ�����͵�������ʱ���Ƚϵ�ǰջ��Ԫ���Ƿ���֮ƥ�䣬��ƥ�䣬��ջ�����жϣ�
		����ǰջ��Ԫ���뵱ǰɨ������Ų�ƥ�䣬������������Դ�����ȷ��
		���ַ�����ǰΪĳ�����͵������Ŷ���ջ�Ѿ��գ��������Ŷ��������ţ�
		�ַ���ѭ��ɨ�����ʱ������ջ�ǿգ�����ջ����ĳ�����͵������ţ�����˵�������Ŷ��������ţ�
		�������������ȷ��*/

	/*SequenceStack<int> stack(10);
	string s;
	cout << "������һϵ�����ű��ʽ��";
	cin >> s;
	int i;
	int length = s.length();
	for (i = 0; i < length; i++)
	{
		if (s[i] == '(' || s[i] == '{' || s[i] == '[')
			stack.Push(s[i]);
		else if (s[i] == ')'&&!stack.IsEmpty() && stack.PopE() == '(')
			cout << "()ƥ��ɹ�" << endl;
		else if (s[i] == ')'&&!stack.IsEmpty() && stack.PopE() != '(')
			cout << "���Ų�ƥ��" << endl;
		else if (s[i] == '}'&&!stack.IsEmpty() && stack.PopE() == '{')
			cout << "{}ƥ��ɹ�" << endl;
		else if (s[i] == ')'&&!stack.IsEmpty() && stack.PopE() != '{')
			cout << "���Ų�ƥ��" << endl;
		else if (s[i] == ']'&&!stack.IsEmpty() && stack.PopE() == '[')
			cout << "[]ƥ��ɹ�" << endl;
		else if (s[i] == ']'&&!stack.IsEmpty() && stack.PopE() != '[')
			cout << "���Ų�ƥ��" << endl;
		else if ((s[i] == ')' || s[i] == '}' || s[i] == ']') && stack.IsEmpty())
			cout << "�����Ŷ���������" << endl;
	}
	if (i == length && stack.IsEmpty())
		cout << "����ƥ��" << endl;
	else if (!stack.IsEmpty())
		cout << "�����Ŷ���������" << endl;*/






	/********�Թ�**********/
	/*MazeSolveMethod solve;
	solve.findPath(1, 1);
	solve.printPath();*/
	

	return 0;
}

