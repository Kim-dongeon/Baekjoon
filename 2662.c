#include <stdio.h>

#define MAXN 21
#define MAXM 301

int r[MAXN][MAXM];
int dp[MAXN][MAXM];
int invest[MAXN][MAXM];
int bills[MAXN];

int cal_dp(int company, int money)
{
	int temp = 0, max = -1;
	for (int i = 0; i <= money; i++)
	{
		dp[0][i] = r[0][i];
	}
	for (int i = 1; i <= money; i++)
	{
		invest[0][i] = 1;
	}

	for (int i = 1; i < company; i++)
	{
		for (int j = 1; j <= money; j++)
		{
			max = -1;
			for (int k = 0; k <= j; k++)
			{
				temp = dp[i - 1][k] + r[i][j - k];
				if (max < temp)
				{
					max = temp;
					invest[i][j] = j-k;
				}
			}
			dp[i][j] = max;
		}
	}

	
}
int main()
{
	int money, company, t = 0,next=0;
	scanf("%d %d", &money, &company);

	for (int i = 0; i < company; i++)
	{
		r[i][0] = 0;
	}
	for (int i = 1; i <= money; i++)
	{
		scanf("%d", &t);
		for (int j = 0; j < company; j++)
		{
			scanf("%d", &r[j][i]);
		}
	}
	cal_dp(company, money);
	
	printf("%d\n", dp[company - 1][money]);

	next = money;
	for (int i = company - 1; i >= 1; i--)
	{
		bills[i] = invest[i][next];
		next -= invest[i][next];
	}
	bills[0] = next;
	for (int i = 0; i < company; i++)
	{
		printf("%d ", bills[i]);
	}
}