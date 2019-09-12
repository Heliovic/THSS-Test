// 2019-01.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

/*输入两个长度不超过200的正整数A,B，求A和B的乘积。保证输入的正整数不会以0开头，要求输出的正整数也不能以0开头*/

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <algorithm>
#include <cstring>

#define MAX_LEN 256

using namespace std;

struct bign
{
	int len;
	int digits[MAX_LEN];
	bign() { fill_n(digits, MAX_LEN, 0); len = 0; }
	void scan()
	{
		char buf[MAX_LEN];
		scanf("%s", buf);
		int l = strlen(buf);
		for (int i = 0; i < l; i++)
			digits[i] = buf[i] - '0';

		len = l;

		reverse(digits, digits + len);
	}

	void print()
	{
		for (int i = len - 1; i >= 0; i--)
			printf("%d", digits[i]);
	}
};

bign add(const bign& b1, const bign& b2)
{
	bign res;

	int carry = 0;

	for (int i = 0; i < b1.len || i < b2.len; i++)
	{
		int t = b1.digits[i] + b2.digits[i] + carry;
		res.digits[i] = t % 10;
		carry = t / 10;
		res.len = i + 1;
	}

	if (carry)
		res.digits[res.len++] = carry;
	return res;
}

bign mul(const bign& b1, const bign& b2)
{
	bign res;
	res.len = 1;
	res.digits[0] = 0;

	int offset = 0;

	for (int i = 0; i < b1.len; i++)
	{
		bign tmp;
		int carry = 0;

		for (int j = 0; j < b2.len; j++)
		{
			int t = b1.digits[i] * b2.digits[j] + carry;
			tmp.digits[j + offset] = t % 10;
			carry = t / 10;
			tmp.len = j + offset + 1;
		}

		if (carry)
			tmp.digits[tmp.len++] = carry;
		res = add(res, tmp);
		offset++;
	}

	return res;
}

int main()
{
	bign b1, b2;
	b1.scan();
	b2.scan();

	bign res = add(b1, b2);

	res.print();

	putchar('\n');

	res = mul(b1, b2);

	res.print();

	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
