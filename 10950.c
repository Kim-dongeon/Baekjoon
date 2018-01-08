#include <stdio.h>

int main()
{
	int a, b,T=0;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d", &a, &b);
		printf("%d\n", a + b);
	}
}