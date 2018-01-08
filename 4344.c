#include <stdio.h>
#include <stdlib.h>

int main()
{
	int c = 0, N = 0, sum = 0,cnt=0;
	int *p;
	scanf("%d", &c);
	while (c--)
	{
		scanf("%d", &N);
		p = (int*)malloc(sizeof(int)*N);
		for (int i = 0; i < N; i++)
		{
			scanf("%d", &p[i]);
			sum += p[i];
		}
		sum = sum / N;
		for (int i = 0; i < N; i++)
		{
			if (sum < p[i])
			{
				cnt++;
			}
		}
		printf("%.3f%%\n", (float)cnt / N * 100);
		free(p);
		sum = 0;
		cnt = 0;

	}

}