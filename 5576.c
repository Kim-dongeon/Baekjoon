#include <stdio.h>

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int main()
{
	int w[10] = { 0, };
	int k[10] = { 0, };
	

	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &w[i]);
	}
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &k[i]);
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = i; j < 10; j++)
		{
			if (w[i] < w[j])
			{
				swap(&w[i], &w[j]);
			}	
			if (k[i] < k[j])
			{
				swap(&k[i], &k[j]);
			}
		}
	}

	printf("%d %d", w[0] + w[1] + w[2], k[0] + k[1] + k[2]);
}