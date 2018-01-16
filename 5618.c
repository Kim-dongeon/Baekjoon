#include <stdio.h>

int main()
{
	int N;
	scanf("%d", &N);
	if (N == 2)
	{
		int a = 0, b = 0;
		scanf("%d %d", &a, &b);
		for (int i = 1; i < a && i < b; i++)
		{
			if (a%i == 0 && b%i == 0)
			{
				printf("%d\n", i);
			}
		}
	}
	else
	{
		int a = 0, b = 0,c=0;
		scanf("%d %d %d", &a, &b, &c);
		for (int i = 1; i < a && i < b && i<c; i++)
		{			
			if (a%i == 0 && b%i == 0 && c%i ==0)
			{
				printf("%d\n", i);
			}
		}
	}
}