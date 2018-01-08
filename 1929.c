#include <stdio.h>

#define MAXN 1000000
int memo[MAXN];

void prime(int n)
{
	memo[1] = 1;
	for (int i = 2; i <=n; i++)
	{
		if (memo[i] > 0)
		{
			continue;
		}

		for (int j = i* 2; j <= n; j += i)
		{
			memo[j] = 1;
		}
	}
}
int main()
{
	int M, N;
	scanf("%d %d", &M, &N);
	prime(N);

	for (int i = M; i <= N; i++)
	{
		if (memo[i] == 0)
		{
			printf("%d\n", i);
		}
	}
}