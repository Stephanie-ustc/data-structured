/*实现路径的寻找思路：
1：设定寻找的方向，可以使用一个判断语句；判断起始位置周围哪个地方有路就将该位置的坐标加入到栈中，并将该位置标记(将改位置值改为2, 既将走过的位置标记为2)
2：判断该位置周围是否还有路，若没有则退栈即退回到上一个位置；并将该位置做下另一个标记(将该位置值改为3, 既将退栈位置值用3标记)
3：重复1, 2步骤直到达到出口*/

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