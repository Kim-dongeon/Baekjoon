#include <stdio.h>

int main()
{
	int T = 0, N = 0,num=0,sum=0;

	scanf("%d", &T);

	while (T--)
	{
		scanf("%d", &N);
		while (N--)
		{
			scanf("%d", &num);
			sum += num;
		}
		printf("%d\n", sum);
		sum = 0;
	}
}