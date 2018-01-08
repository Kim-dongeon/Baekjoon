#include <stdio.h>

int prime(int n)
{
	if (n == 1)
	{
		return 0;
	}
	for (int i = 2; i < n; i++)
	{
		if (n%i == 0)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	int N = 0,n=0,cnt =0;
	scanf("%d", &N);
	while (N--)
	{
		scanf("%d", &n);
		cnt +=prime(n);
	}
	printf("%d\n", cnt);
}