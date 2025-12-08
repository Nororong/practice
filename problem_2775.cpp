#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int tc;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++)
	{
		int k, n;
		scanf("%d", &k);
		scanf("%d", &n);
		int arr[15][15];
		for (int i = 0; i < 15; i++)
		{
			for (int j = 1; j <= 14; j++)
			{
				arr[i][j] = 0;
			}
		}
		for (int i = 1; i <= 14; i++)
		{
			arr[0][i] = i;
		}
		for (int i = 1; i < 15; i++)
		{
			for (int j = 1; j < 15; j++)
			{
				for (int l = 0; l < j; l++)
					arr[i][j] += arr[i - 1][j - l];
			}
		}
		printf("%d\n", arr[k][n]);
	}
	return 0;
}