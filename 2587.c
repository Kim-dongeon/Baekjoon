#include <stdio.h>

int main()
{
	int n = 5,sum=0;
	int num[5] = { 0, };
	int i = 0;
	while (n--)
	{
		scanf("%d", &num[i]);
		sum += num[i];
		i++;
	}
	for (int j = 0; j < 5; j++)
	{
		for (int x = j+1; x < 5; x++)
		{
			if (num[j] > num[x])
			{
				int tmp = num[j];
				num[j] = num[x];
				num[x] = tmp;
			}
		}
	}
	printf("%d\n", sum / 5);
	printf("%d", num[2]);

}