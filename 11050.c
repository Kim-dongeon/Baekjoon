#include <stdio.h>

#define MAXN 20

int combination(int n, int k)
{
	int cnt = 0;
	static int memo[MAXN][MAXN];

	if (memo[n][k] > 0)
	{
		return memo[n][k];
	}

	if (k == 0 || n == k)
	{
		return memo[n][k] = 1;
	}

	return  memo[n][k] = combination(n - 1, k - 1) + combination(n - 1, k);
}
int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	printf("%d\n", combination(n, k));
}