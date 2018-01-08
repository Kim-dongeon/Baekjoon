#include <stdio.h>

#define MAXN 200
long long f[MAXN];

long long fibo(int n)
{
	f[1] = f[2] = 1;
	for (int i = 3; i <= n; i++)
	{
		f[i] = f[i - 2] + f[i - 1];
	}
	return f[n];
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	printf("%lld\n",fibo(n));
}