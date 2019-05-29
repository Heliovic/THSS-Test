// 2017-02.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

/*
被遗漏的数字（30 分）
Problem Description
小明写了一个函数，将1-n 的数随机排列组成一个字符串，每个数字使用且仅使用一次。但是小明在写的时候粗心了，导致生成的字符串丢失了其中一个数字。帮助小明找出这个数字

Input
测试输入包含若干测试用例，每个测试用例占两行，第一行是n（2<=n<=200），第二行是一个字符串。

Output
对每个测试用例输出1 行，输出缺漏的数字

Sample Input
5
1234
20
12345678910111314151617181920

Sample Output
5
12
---------------------
作者：da_kao_la
来源：CSDN
原文：https://blog.csdn.net/da_kao_la/article/details/82381617
版权声明：本文为博主原创文章，转载请附上博文链接！
*/

#include <iostream>
#include <string>
#include <set>
#include <sstream>

using namespace std;

string str;
set<int> st;
int N, ans;
bool findd = false;

void dfs(int off)
{
	if (findd)
		return;
	if (off == str.size())
	{
		int cnt = 0;
		int ret;
		for (int i = 1; i <= N; i++)
		{
			if (st.find(i) == st.end())
			{
				cnt++;
				ret = i;
			}
		}

		if (cnt == 1)
			ans = ret;
		return;
	}
	int k = 1;
	string s = str.substr(off, k);
	stringstream ss;
	ss << s;
	int t;
	ss >> t;

	while (t <= N)
	{
		if (st.find(t) != st.end())
			goto TT1;
		st.insert(t);
		dfs(off + k);
		st.erase(t);
TT1:
		k++;
		if (off + k > str.size())
			return;
		s = str.substr(off, k);
		ss.str("");
		ss.clear();
		ss << s;
		ss >> t;
	}
}

int main()
{
	while (cin >> N)
	{
		findd = false;
		st.clear();
		cin >> str;
		dfs(0);
		printf("%d", ans);
	}
	return 0;
}
