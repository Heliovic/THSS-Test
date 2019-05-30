// 2018-01.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

/*
输入只有一行，包含两个整数a,b，要求输出[a,b]内所有的回文数，a,b<10^6
*/

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstring>

using namespace std;

int A, B;

int main()
{
	scanf("%d %d", &A, &B);

	char buf[128];

	for (int i = A; i <= B; i++)
	{
		sprintf(buf, "%d", i);
		int len = strlen(buf);

		bool flag = true;

		for (int i = 0; i <= len / 2 && flag; i++)
			if (buf[i] != buf[len - 1 - i])
				flag = false;
		if (flag)
			printf("%d\n", i);
	}

	return 0;
}
