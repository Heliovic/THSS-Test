// 2018-04.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

/*
编号为1到N的N个城市间有M条铁路，通过每条铁路花费时间T_i,为了减少从城市1到N的时间，现在决定将其中一条铁路改建成高铁。
改建后通过该条铁路的时间将减半（向下取整数），求改建哪条铁路可以使得改建后从城市1到城市N的时间最短 
输入：第一行N和M 
接下来M行，每行A_i, B_i, T_i分别是第i条铁路的起点和终点，以及时间 
输出：改建的铁路编号以及改建后从1到N的时间 
注意：铁路是双向的，保证解唯一 
80%数据N,M<5000,100%数据N,M<1000000

---------------------
作者：da_kao_la
来源：CSDN
原文：https://blog.csdn.net/da_kao_la/article/details/82468781
版权声明：本文为博主原创文章，转载请附上博文链接！
*/

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>

#define MAX_N 1024000

using namespace std;

struct edge
{
	int s, t, d;
};

struct prio_node
{
	int s, d;
	bool operator < (const prio_node& rhs) const
	{
		return d > rhs.d;
	}
};

int N, M;
vector<edge> edges;
vector<int> graph[MAX_N];

bool vis[MAX_N];
int dis[MAX_N];

void add_edge(int s, int t, int d)
{
	edge e;
	e.s = s;
	e.t = t;
	e.d = d;
	edges.push_back(e);
	graph[s].push_back(edges.size() - 1);
	swap(e.s, e.t);
	edges.push_back(e);
	graph[t].push_back(edges.size() - 1);
}

void dijkstra(int u)
{
	fill_n(dis, MAX_N, INT_MAX);
	fill_n(vis, MAX_N, false);
	dis[u] = 0;

	priority_queue<prio_node> q;
	prio_node n;
	n.s = u;
	n.d = 0;
	q.push(n);

	while (!q.empty())
	{
		prio_node p = q.top();
		q.pop();

		if (vis[p.s])
			continue;
		vis[p.s] = true;

		for (int i = 0; i < graph[p.s].size(); i++)
		{
			edge e = edges[graph[p.s][i]];
			if (dis[e.t] > dis[e.s] + e.d)
			{
				dis[e.t] = dis[e.s] + e.d;
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
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++)
	{
		int s, t, d;
		scanf("%d %d %d", &s, &t, &d);
		add_edge(s, t, d);
	}

	int ans_t = INT_MAX;
	int ans_e = -1;

	for (int i = 0; i < edges.size(); i++)
	{
		int bk = edges[i].d;
		edges[i].d /= 2;
		dijkstra(1);
		if (dis[N] < ans_t)
		{
			ans_t = dis[N];
			ans_e = i;
		}
		edges[i].d = bk;
	}

	printf("%d %d", ans_e, ans_t);

	return 0;
}
