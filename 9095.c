#include <stdio.h>

int partition(int n)
{
	int cnt = 0;
	static int memo[3] = { 1,2,4 };
	if (n == 3)
	{
		return 4;
	}
	else if (n == 2)
	{
		return 2;
	}
	else if (n == 1)
	{
		return 1;
	}
	for (int i = 1; i <4; i++)
	{		
		if (n - i > 0)
		{
			cnt += partition(n - i);
		}
		
	}

	return cnt;

}
int main()
{
	int T = 0;
	int n = 0;
	

	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		printf("%d\n",partition(n));
	}
}