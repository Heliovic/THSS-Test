// 2017-01.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

/*
Problem Description

读入两个不超过25位的火星正整数A和B，计算A+B。需要注意的是：在火星上，整数不是单一进制的，第n位的进制就是第n个素数。
例如：地球上的10进制数2，在火星上记为“1,0”，因为火星个位数是2进制的；
地球上的10进制数38，在火星上记为“1,1,1,0”，因为火星个位数是2进制的，十位数是3进制的，百位数是5进制的，千位数是7进制的……

Input

测试输入包含若干测试用例，每个测试用例占一行，包含两个火星正整数A和B，火星整数的相邻两位数用逗号分隔，A和B之间有一个空格间隔。
当A或B为0时输入结束，相应的结果不要输出。

Output

对每个测试用例输出1行，即火星表示法的A+B的值。

Sample Input

1,0 2,1

4,2,0 1,2,0

1 10,6,4,2,1

0 0

Sample Output

1,0,1

1,1,1,0

1,0,0,0,0,0

---------------------
作者：da_kao_la
来源：CSDN
原文：https://blog.csdn.net/da_kao_la/article/details/82354850
版权声明：本文为博主原创文章，转载请附上博文链接！
*/

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX_LEN 102400

using namespace std;

int primes[MAX_LEN];
vector<int> ps;
vector<int> weight;

int mars2earth(vector<int> lhs)
{
	int res = 0;
	for (int i = 0; i < lhs.size(); i++)
		res += weight[i] * lhs[i];
	return res;
}

vector<int> addd(vector<int> lhs, vector<int> rhs)
{
	int lint = mars2earth(lhs);
	int rint = mars2earth(rhs);
	int add = lint + rint;

	vector<int> res;

	int ptr;

	for (ptr = 0; weight[ptr] <= add; ptr++);
	ptr--;

	while (ptr >= 0)
	{
		res.push_back(add / weight[ptr]);
		add -= res[res.size() - 1] * weight[ptr];
		ptr--;
	}
	//reverse(res.begin(), res.end());
	return res;
}

void e_primes()
{
	fill_n(primes, MAX_LEN, true);

	primes[0] = primes[1] = false;

	for (int i = 2; i < MAX_LEN; i++)
	{
		if (primes[i])
		{
			ps.push_back(i);
			for (int j = i + i; j < MAX_LEN; j += i)
				primes[j] = false;
		}
	}
	weight.push_back(1);

	for (int i = 0; i < ps.size(); i++)
		weight.push_back(weight[i] * ps[i]);
}

int main()
{
	e_primes();
	while (true)
	{
		char ch;
		vector<int> lhs;
		vector<int> rhs;
		int tmp = 0;
		while (((ch = getchar()) != ' ') && (ch != '\n'))
		{
			if (ch == ',')
			{
				lhs.push_back(tmp);
				tmp = 0;
			}
			else
			{
				tmp *= 10;
				tmp += (ch - '0');
			}
		}
		lhs.push_back(tmp);
		tmp = 0;
		while (((ch = getchar()) != ' ') && (ch != '\n'))
		{
			if (ch == ',')
			{
				rhs.push_back(tmp);
				tmp = 0;
			}
			else
			{
				tmp *= 10;
				tmp += (ch - '0');
			}
		}
		rhs.push_back(tmp);
		reverse(lhs.begin(), lhs.end());
		reverse(rhs.begin(), rhs.end());
		if (lhs.size() == 1 && lhs[0] == 0 && rhs.size() == 1 && rhs[0] == 0)
			return 0;
		vector<int> res = addd(lhs, rhs);
		int ptr = 0;
		while (ptr < res.size() && res[ptr] == 0)
			ptr++;
		if (ptr == res.size())
			printf("0\n");
		else
			while (ptr < res.size())
			{
				printf("%d", res[ptr]);
				if (ptr == res.size() - 1)
					printf("\n");
				else
					printf(",");
				ptr++;
			}
	}

	return 0;
}
