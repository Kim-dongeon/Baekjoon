#include <stdio.h>

int N[3];
int B[2];
int main()
{
	int min = 99999;
	for (int i = 0; i < 3; i++)
	{
		scanf("%d", &N[i]);
	}
	for (int i = 0; i < 2; i++)
	{
		scanf("%d", &B[i]);
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			int temp = N[i] + B[j] - 50;
			if (min > temp)
			{
				min = temp;
			}
		}
	}

	printf("%d", min);
}