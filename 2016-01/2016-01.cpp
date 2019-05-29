// 2016-01.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*

从控制台输入一个合法数字，打印其立方

例如

输入123456789

输出1881676371789154860897069
---------------------
作者：da_kao_la
来源：CSDN
原文：https://blog.csdn.net/da_kao_la/article/details/82416299
版权声明：本文为博主原创文章，转载请附上博文链接！
*/

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> add(vector<int>& lhs, vector<int>& rhs)
{
	vector<int> res;

	int len = min(lhs.size(), rhs.size());

	int carry = 0;

	for (int i = 0; i < len; i++)
	{
		int t = lhs[i] + rhs[i] + carry;
		res.push_back(t % 10);
		carry = t / 10;
	}

	if (lhs.size() == rhs.size())
	{
		if (carry)
			res.push_back(carry);
	}
	else if (lhs.size() < rhs.size())
	{
		for (int i = len; i < rhs.size(); i++)
		{
			int t = rhs[i] + carry;
			res.push_back(t % 10);
			carry = t / 10;
		}
	}
	else
	{
		for (int i = len; i < lhs.size(); i++)
		{
			int t = lhs[i] + carry;
			res.push_back(t % 10);
			carry = t / 10;
		}
	}

	return res;
}

vector<int> mul(vector<int> lhs, vector<int> rhs)
{
	vector<int> res;
	for (int i = 0; i < rhs.size(); i++)
	{
		vector<int> tmp;
		int carry = 0;
		int digit = rhs[i];
		for (int j = 0; j < lhs.size(); j++)
		{
			int t = lhs[j] * digit + carry;
			tmp.push_back(t % 10);
			carry = t / 10;
		}
		if (carry)
			tmp.push_back(carry);
		for (int j = 0; j < i; j++)
			tmp.insert(tmp.begin(), 0);
		res = add(res, tmp);
	}

	return res;
}

int main()
{
	vector<int> num;
	char ch;

	while ((ch = getchar()) != '\n')
		num.push_back(ch - '0');

	reverse(num.begin(), num.end());

	vector<int> res = mul(mul(num, num), num);
	for (int i = res.size() - 1; i >= 0; i--)
		printf("%d", res[i]);
	return 0;
}
