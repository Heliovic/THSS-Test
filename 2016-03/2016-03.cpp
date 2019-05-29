// 2016-03.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

/*

从控制台输入一行，形如“n A1 A2 A3 … An B”。其中n代表操作数总数，A1~An 表示n 个操作数。
B 代表目标数字。在此n 个操作数中以任意顺序插入n-1 个四则运算操作符，不能插入括号，形成的表达式能否得到B？
能——输出1，不能——输出0。操作数和目标数字是整数，整数大小限制在32 位有符号整数范围内。
例如：
4 75 4 18 8 21
输出1 （75 / 4 + 18 / 8 = 21）
---------------------
作者：da_kao_la
来源：CSDN
原文：https://blog.csdn.net/da_kao_la/article/details/82319399
版权声明：本文为博主原创文章，转载请附上博文链接！
*/

#define _CRT_SECURE_NO_WARNINGS

#define ADD (double)(INT_MAX - 3)
#define SUB (double)(INT_MAX - 2)
#define MUL (double)(INT_MAX - 1)
#define DIV (double)(INT_MAX)

#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <climits>
#include <map>

using namespace std;

vector<double> numbers;
vector<double> ops;
map<double, int> prio;
int N, B;
bool flag = false;

double cal()
{
	queue<double> q;
	stack<double> s;

	vector<double> exp;
	
	for (int i = 0; i < ops.size(); i++)
	{
		exp.push_back(numbers[i]);
		exp.push_back(ops[i]);
	}

	exp.push_back(numbers[numbers.size() - 1]);

	for (int i = 0; i < exp.size(); i++)
	{
		if (i % 2)	// ops
		{
			if (s.size() == 0)
				s.push(exp[i]);
			else
			{
				while (!s.empty() && prio[s.top()] >= prio[exp[i]])
				{
					q.push(s.top());
					s.pop();
				}
				s.push(exp[i]);
			}
		}
		else	// exp
		{
			q.push(exp[i]);
		}
	}

	while (!s.empty())
	{
		q.push(s.top());
		s.pop();
	}

	while (!q.empty())
	{
		if (q.front() >= (double)(INT_MAX - 3))
		{
			double rhs = s.top();
			s.pop();
			double lhs = s.top();
			s.pop();

			if (q.front() == ADD)
				s.push(lhs + rhs);
			else if (q.front() == SUB)
				s.push(lhs - rhs);
			else if (q.front() == MUL)
				s.push(lhs * rhs);
			else
				s.push(lhs / rhs);
			q.pop();
		}
		else
		{
			s.push(q.front());
			q.pop();
		}
	}

	return s.top();
}

void dfs(int t)
{
	if (t == N - 1)
	{
		if (cal() == B)
			flag = true;
		return;
	}

	for (double i = (double)(INT_MAX - 3); i <= (double)(INT_MAX); i = i + 1)
	{
		ops.push_back(i);
		dfs(t + 1);
		ops.pop_back();
	}
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		double t;
		scanf("%lf", &t);
		numbers.push_back(t);
	}

	scanf("%d", &B);
	prio[ADD] = prio[SUB] = 0;
	prio[MUL] = prio[DIV] = 1;

	dfs(0);

	printf("%d", flag);

	return 0;
}

