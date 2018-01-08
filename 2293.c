#include <stdio.h>

#define MAXN 50000

int coin(int money,int n,int bills[])
{
	static int  memo[MAXN];

	int t = 0, cnt = 0;;

	if (n==1)
	{
		if (money % bills[0] == 0)
		{
			return memo[money] = 1;
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
	}
	return cnt;
}
int main()
{
	int n, k;
	int num[100] = { 0, };
	scanf("%d %d", &n, &k);
	
	for(int i=0;i<n;i++)
	{
		scanf("%d", &num[i]);
	}

	printf("%d",coin(k, n, num));
}