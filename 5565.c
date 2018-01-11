#include <stdio.h>

int main()
{
	int sum = 0, N = 0;
	scanf("%d", &sum);
	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &N);
		sum -= N;
	}
	printf("%d", sum);
}