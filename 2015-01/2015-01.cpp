// 2015-01.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

/*

病毒感染
一个n＊m的区域内，有k个初试感染患者，患者的初始感染状态为1，未感染的正常人的状态为0。
每过一个单位时间，患者的感染状态加一。
当感染状态为4时，这个患者具备感染他人的能力（感染时间忽略不计），感染的对象为他上下左右的人，已经被感染的人不可再次被感染；
当感染状态为5时，病人开始接受治疗，到下一时刻开始感染状态变成0，并且具备抗体，不会再被感染。
请问在整个过程中同时处于感染状态的人最多有多少人？
输入前两个数字为n和m，第三个数字为k，接下来两个数为一组，k组输入分别为初始感染者的位置。其中0＜n＜10，0＜m＜10，0＜k＜n＊m
输出为同时感染最多的人数4，0-＞4，1
样例输入:
3 3 1
2 2
样例输出:
8
其中同时感染的人数变化是1115548844400
https://blog.csdn.net/dakaola

*/
#define _CRT_SECURE_NO_WARNINGS


#include <cstdio>
#include <algorithm>

#define MAX_N 32
#define MAX_M 32

using namespace std;

int matrix[MAX_N][MAX_M];
int M, N, K;

int main()
{
	fill_n(&matrix[0][0], MAX_M * MAX_N, 0);
	scanf("%d %d %d", &N, &M, &K);

	while (K--)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		matrix[x][y] = 1;
		int cnt = 1;
		int max_cnt = 1;

		while (cnt != 0)
		{
			for (int i = 1; i <= N; i++)
			{
				for (int j = 1; j <= M; j++)
				{
					if (matrix[i][j] == 5)
					{
						matrix[i][j] = -1;
						cnt--;
					}
				}
			}

			for (int i = 1; i <= N; i++)
			{
				for (int j = 1; j <= M; j++)
				{
					if (matrix[i][j] >= 1 && matrix[i][j] <= 4)
						matrix[i][j]++;
					
				}
			}

			for (int i = 1; i <= N; i++)
			{
				for (int j = 1; j <= M; j++)
				{
					if (matrix[i][j] >= 4)
					{
						if (i - 1 >= 1 && matrix[i - 1][j] == 0)
						{
							matrix[i - 1][j] = 1;
							cnt++;
						}

						if (j - 1 >= 1 && matrix[i][j - 1] == 0)
						{
							matrix[i][j - 1] = 1;
							cnt++;
						}

						if (i + 1 <= N && matrix[i + 1][j] == 0)
						{
							matrix[i + 1][j] = 1;
							cnt++;
						}

						if (j + 1 <= N && matrix[i][j + 1] == 0)
						{
							matrix[i][j + 1] = 1;
							cnt++;
						}
					}
				}
			}
			max_cnt = max(cnt, max_cnt);
			//printf("%d ", cnt);
		}
		printf("%d\n", max_cnt);
	}
}
