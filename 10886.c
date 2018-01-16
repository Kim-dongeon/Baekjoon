#include <stdio.h>

int main()
{
	int N;
	int a = 0,cute=0;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &a);
		if (a == 1)
		{
			cute++;
		}
		else
		{
			cute--;
		}
	}
	if (cute > 0)
	{
		printf("Junhee is cute!");
	}
	else
	{
		printf("Junhee is not cute!");
	}
}