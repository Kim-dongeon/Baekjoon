#include <stdio.h>

#define MAXN 200
long long fibo(int n)
{
	static long long memo[MAXN];

	if (memo[n] > 0) return memo[n];
	if (n == 0)
	{
		return memo[n] = 0;
	}
	if (n == 1 || n == 2)
	{
		return memo[n] = 1;
	}

	return memo[n] = fibo(n - 1) + fibo(n - 2);
}
int main()
{
	int n;
	scanf("%d", &n);
	printf("%lld\n", fibo(n));
}