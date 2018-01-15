#include <stdio.h>

#define MAXN 100
#define MAXM 10000

int memo[MAXN][MAXM];
long long  dp[10001];

int coin(int money,int n,int bills[])
{
	int t = 0, cnt = 0;
	if (memo[n][money] != 0)
	{
		return memo[n][money];
	}
	if (n==1 || money ==0 )
	{
		if (money % bills[0] == 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	t= money / bills[n - 1];

	for (int i = 0; i <= t; i++)
	{		
		cnt += coin(money - bills[n - 1] * i, n - 1, bills);
		memo[n][money] = cnt;
	}
	return cnt;
}

void d(int money, int num[],int n)
{
	dp[0] = 1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = num[i]; j <= money; j++)
		{			
			dp[j] += dp[j - num[i]];
			if (dp[j] > 2000000000 && i == n )
			{
				printf("!!! %d %d %d\n",i,j,dp[j]);
			}
		}
	}
	printf("%d", dp[money]);
}
int main()
{
	int n, k;
	int num[101] = { 0, };	
	
	scanf("%d %d", &n, &k);

	/*for (int i = 1; i <= n; i++)
	{
		scanf("%d", &num[i]);
	}
	
	d(k,num,n);*/

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
	}
	printf("%d\n", coin(k, n, num));
}


