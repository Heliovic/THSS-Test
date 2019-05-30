// 2018-03.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <queue>
#include <set>

#define MAX_N 128

using namespace std;

int ps[MAX_N];
set<int> st;

int main()
{
	int N, k;

	scanf("%d %d", &N, &k);

	for (int i = 0; i < N; i++)
		scanf("%d", &ps[i]);

	priority_queue<int, vector<int>, greater<int>> q;
	for (int i = 0; i < N; i++)
		q.push(ps[i]);

	int cnt = 0;

	while (true)
	{
		int n = q.top();
		q.pop();
		cnt++;
		if (cnt == k)
		{
			printf("%d", n);
			return 0;
		}

		for (int i = 0; i < N; i++)
		{
			if (st.find(n * ps[i]) == st.end())
			{
				q.push(n * ps[i]);
				st.insert(n * ps[i]);
			}
		}
	}

	return 0;
}
