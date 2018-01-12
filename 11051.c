#include <stdio.h>

int dp[1000][1000];
void c(int n, int k)
{
	dp[1][1] = 1;
	for (int i = 1; i <= n; i++)
	{
		dp[i][0] = 1;
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j])%10007;
		}
	}
	printf("%d", dp[n][k]);
}
int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	c(N, K);
}