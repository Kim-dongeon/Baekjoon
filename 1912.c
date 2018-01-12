#include <stdio.h>

#define MAX(X,Y) ((X)>(Y)?(X):(Y))
int a[100000];
int dp[100000];
void c1(int a[],int n)
{
	dp[0] = a[0];
	for (int i = 1; i < n; i++)
	{
		dp[i] = MAX(dp[i - 1] + a[i], a[i]);
	}
}

void c2(int a[], int n)
{
	int max = -1000;
	for (int i = 0; i < n; i++)
	{
		if (max < dp[i])
		{
			max = dp[i];
		}
	}
	printf("%d", max);
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	c1(a, n);
	c2(a, n);
}