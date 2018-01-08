#include <stdio.h>

int main()
{
	int n = 7;
	int num = 0;
	int sum = 0;
	int least = 999;
	while (n--)
	{
		scanf("%d", &num);
		if (num % 2 == 1)
		{
			sum += num;
			if (least > num)
			{
				least = num;
			}
		}
	}
	if (sum == 0)
	{
		printf("-1");
	}
	else
	{
		printf("%d\n%d", sum, least);
	}
}