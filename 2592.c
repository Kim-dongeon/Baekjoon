#include <stdio.h>

int main()
{
	int n = 10;
	int num = 0;
	int sum = 0;
	char a[100] = { 0, };
	int tmp = 0;
	int least = 0;
	while (n--)
	{
		scanf("%d", &num);
		sum += num;
		a[num / 10]++;
	}

	printf("%d\n", sum / 10);
	for (int i = 0; i < 100; i++)
	{
		if (tmp < a[i])
		{
			tmp = a[i];
			least = i*10;
		}
	}
	printf("%d\n", least);
}