#include <stdio.h>

int main()
{
	int a, b, c;
	int max;
	scanf("%d %d %d", &a, &b, &c);
	
	if (a > b && a>c)
	{
		max = a;
	}
	if (b > a && b>c)
	{
		max = b;
	}
	if (c > b && c>a)
	{
		max = c;
	}
	if (a == b && b == c)
	{
		printf("%d\n", 10000 + (a * 1000));
	}
	else if (a == b || a == c || b == c)
	{
		if (a == b || a == c)
		{
			printf("%d\n", 1000 + (a * 100));
		}
		else
		{
			printf("%d\n", 1000 + (b * 100));
		}
	}
	else
	{
		printf("%d\n", max * 100);
	}
	return 0;
}