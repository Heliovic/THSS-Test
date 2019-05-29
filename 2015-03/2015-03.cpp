// 2015-03.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

/*
航线交叉
有一条河道，河道南北两侧分别有n个城市，0＜n＜100，南北的城市之间有航线相连，但是有的航线是有交叉的，容易产生事故。
现在已知每个城市有且只有一条航线与对岸的某个城市相连，希望减少一些航线来避免事故，请问减少的最小航线数是多少？
例如上图中，需要去掉的航线数是3，分别是1-2，4-4，6-3这三条（其中前面一个数字表示北面的城市号，后一个数字表示南面的城市号）。
输入的第一个数是城市数n，接下来2个数为一组，有n组城市航线对，第一个数字代表北面的城市号，后一个数字代表南面的城市号。
输出为需要减少的最少航线数。
样例输入:
6
1 2
2 1
3 5
4 4
5 6
6 3
样例输出:
3
https://blog.csdn.net/dakao_la

*/
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX_N 128

int nums[MAX_N];
int dp[MAX_N];
int N;

int main()
{
	fill_n(dp, MAX_N, 0);
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		int s, t;
		scanf("%d %d", &s, &t);
		nums[s] = t;
	}

	dp[1] = 1;
	int maxx = -1;

	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (nums[i] >= nums[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
				maxx = max(dp[i], maxx);
			}
		}
	}

	printf("%d", N - maxx);

	return 0;
}
