/*ʵ��·����Ѱ��˼·��
1���趨Ѱ�ҵķ��򣬿���ʹ��һ���ж���䣻�ж���ʼλ����Χ�ĸ��ط���·�ͽ���λ�õ�������뵽ջ�У�������λ�ñ��(����λ��ֵ��Ϊ2, �Ƚ��߹���λ�ñ��Ϊ2)
2���жϸ�λ����Χ�Ƿ���·����û������ջ���˻ص���һ��λ�ã�������λ��������һ�����(����λ��ֵ��Ϊ3, �Ƚ���ջλ��ֵ��3���)
3���ظ�1, 2����ֱ���ﵽ����*/

#include"SequenceStack.h"
#include <iostream>
using namespace std;

class MazeSolveMethod
{
private:
	static int maze[10][10];
	SequenceStack<int> pathstack;
public:
	MazeSolveMethod():pathstack(100){}
	~MazeSolveMethod(){}
	void findPath(int startX,int startY);
	void printPath() const;
};
int MazeSolveMethod::maze[10][10] = {
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 1, 1, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 1, 0, 1, 0, 0, 1 },
	{ 1, 0, 1, 0, 0, 0, 1, 1, 0, 1 },
	{ 1, 0, 1, 0, 0, 0, 1, 1, 1, 1 },
	{ 1, 0, 1, 1, 1, 0, 1, 1, 1, 1 },
	{ 1, 0, 1, 1, 1, 0, 1, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 0, 0, 0, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 0, 0, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
};

void MazeSolveMethod::findPath(int startX, int startY)
{
	int x = startX;
	int y = startY;
	pathstack.Push(x);
	pathstack.Push(y);
	maze[x][y] = 2;

	while (1)
	{
		if (maze[x - 1][y] == 0){ pathstack.Push(--x); pathstack.Push(y); maze[x][y] = 2; }
		else if (maze[x][y - 1] == 0){ pathstack.Push(x); pathstack.Push(--y); maze[x][y] = 2; }
		else if (maze[x][y + 1] == 0){ pathstack.Push(x); pathstack.Push(++y); maze[x][y] = 2; }
		else if (maze[x + 1][y] == 0){ pathstack.Push(++x); pathstack.Push(y); maze[x][y] = 2; }
	    
		if (maze[x - 1][y] != 0 && maze[x + 1][y] != 0 && maze[x][y - 1] != 0 && maze[x][y + 1] != 0)
		{
			if (x >= 8 && y >= 8) break;
			else { maze[x][y] = 3; y = pathstack.PopE(); x = pathstack.PopE(); }
			y = pathstack.GetTop();
			int tmp = pathstack.PopE();
			x = pathstack.GetTop();
			pathstack.Push(tmp);
		}
	}
}

void MazeSolveMethod::printPath() const
{
	cout << "printPath" << endl;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (maze[i][j] == 2)
				cout << "*" << " ";
			else if (maze[i][j] == 3)
				cout << 0 << " ";
			else
				cout << 1 << " ";
		}
		cout << endl;
	}
}