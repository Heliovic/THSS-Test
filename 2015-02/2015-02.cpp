// 2015-02.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

/*
找到算式
给定n个数字，和一个目标数字D，然后在这n个数字中插入n-1个运算符使得获得目标数字D，
如果能够得到目标数字，则输出运算式，如果不能得到结果，就输出大于D的最小结果。
为了简化操作，能够插入的运算符只有加法和乘法，同时不考虑任何优先级的关系，所有式子从左至右进行计算，例如:1＋1＊3＝6。
测试样例不会出现溢出问题，0＜n＜10，每个数字小于1000，结果唯一。
输入前两个数字分别是数字的个数和目标结果，接下来n个数是输入的n个给定数字。样例输入:
4 235
34 12 5 5
样例输出:
34＋12＊5＋5
样例输入:
3 600
9 9 9
样例输出:
729
https://blog.csdn.net/dakaola
*/

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <climits>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX_N 16
#define MUL 1
#define ADD 2

int numbers[MAX_N];
int type[MAX_N];
int ans_type[MAX_N];
int N, target;
bool canbe = false;
int minn = INT_MAX;

void dfs(int t)
{
	if (canbe)
		return;
	if (t == N)
	{
		int res = numbers[1];
		for (int i = 2; i <= N; i++)
		{
			if (type[i - 1] == ADD)
				res += numbers[i];
			else
				res *= numbers[i];
		}

		if (res == target)
		{
			canbe = true;
			memcpy(ans_type, type, sizeof(type));
		}
		else if (res > target)
			minn = min(minn, res);
		return;
	}
	type[t] = ADD;
	dfs(t + 1);
	type[t] = MUL;
	dfs(t + 1);
}

int main()
{
	scanf("%d %d", &N, &target);

	for (int i = 1; i <= N; i++)
		scanf("%d", &numbers[i]);

	dfs(1);

	if (canbe)
	{
		printf("%d", numbers[1]);
		for (int i = 2; i <= N; i++)
		{
			printf("%c%d", ans_type[i - 1] == ADD ? '+' : '*', numbers[i]);
		}
	}
	else
		printf("%d", minn);

	return 0;
}

