// 2018-02.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

/*
在一个上凸函数上均匀采样得到{f(i)|i=1,2…N},有M次询问，每次询问输入两个整数a,b,求{f(i)-a*i-b|i=1,2…N}的最大值。 
输入：第一行,N和M,其中N,M<5e5
然后N行，按顺序输入f(i) 
然后M行，每行两个整数 a,b
---------------------
作者：da_kao_la
来源：CSDN
原文：https://blog.csdn.net/da_kao_la/article/details/82460671
版权声明：本文为博主原创文章，转载请附上博文链接！
*/

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <climits>
#include <algorithm>

#define MAX_N 502400

int f[MAX_N];
int N, M;
int a, b;

using namespace std;

int solve(int lp, int rp)
{
	if (rp - lp <= 4)
	{
		int maxx = INT_MIN;
		for (int i = lp; i <= rp; i++)
			maxx = max(maxx, f[i] - (a * i + b));
		return maxx;
	}

	int s = (double)lp * 2 / 3 + (double)rp * 1 / 3;
	int t = (double)lp * 1 / 3 + (double)rp * 2 / 3;
	if (f[s] - (a * s + b) < f[t] - (a * t + b))
		return solve(s, rp);
	else
		return solve(lp, t);
}

int main()
{
	freopen("1802.txt", "r", stdin);
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
		scanf("%d", &f[i]);

	while (M--)
	{
		scanf("%d %d", &a, &b);

		printf("%d\n", solve(1, N));

	}

	return 0;
}
