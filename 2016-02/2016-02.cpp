// 2016-02.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

/*

从控制台输入n+1 行，前n 行每行3 个整数，形如“A B d”，表示从节点A 到节点B 距离为d（双向）。
第n+1 行形如“A B”，表示求A 到B 的最短距离。输出此最短距离。

例如：

1 42 3
42 789 4
1 789 9
1 789

输出

7

BFS、动态规划、剪枝、图
---------------------
作者：da_kao_la
来源：CSDN
原文：https://blog.csdn.net/da_kao_la/article/details/82425671
版权声明：本文为博主原创文章，转载请附上博文链接！
*/

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <climits>

#define MAX_N 10240

using namespace std;

struct edge
{
	int s, t, d;
};

struct prio_node
{
	int s, d;
};

struct cmp
{
	bool operator () (const prio_node& lhs, const prio_node& rhs) const
	{
		return lhs.d > rhs.d;
	}
};

vector<edge> edges;
vector<int> graph[MAX_N];

int dis[MAX_N];
bool vis[MAX_N];

int A, B;

void add_edge(int s, int t, int d)
{
	edge e;
	e.s = s;
	e.t = t;
	e.d = d;
	edges.push_back(e);
	graph[e.s].push_back(edges.size() - 1);
	swap(e.s, e.t);
	edges.push_back(e);
	graph[e.s].push_back(edges.size() - 1);
}

void dijkstra(int u)
{
	fill_n(dis, MAX_N, INT_MAX);
	fill_n(vis, MAX_N, false);

	priority_queue < prio_node, vector<prio_node>, cmp> q;
	prio_node n;
	n.s = u;
	n.d = 0;

	q.push(n);

	dis[u] = 0;

	while (!q.empty())
	{
		n = q.top();
		q.pop();

		if (vis[n.s])
			continue;
		vis[n.s] = true;

		for (int i = 0; i < graph[n.s].size(); i++)
		{
			edge e = edges[graph[n.s][i]];

			if (dis[e.t] > dis[n.s] + e.d)
			{
				dis[e.t] = dis[n.s] + e.d;
				prio_node t;
				t.s = e.t;
				t.d = dis[e.t];
				q.push(t);
			}
		}
	}
}

int main()
{
	int s, t, d;

	while (scanf("%d %d %d", &s, &t, &d) == 3)
		add_edge(s, t, d);

	A = s;
	B = t;

	dijkstra(A);

	printf("%d", dis[B]);

	return 0;
}
