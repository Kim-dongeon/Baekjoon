#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	if (n % 2 == 1)
	{
		n = (n + 1) / 2;
		printf("%d\n", n*(n + 1));
	}
	else
	{
		n = n / 2;
		printf("%d\n", (n+1)*(n+1));
	}
}