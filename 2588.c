#include <stdio.h>

int main()
{
	int a, b = 0;

	scanf("%d", &a);
	scanf("%d", &b);
	printf("%d\n", (b %100%10)*a);
	printf("%d\n", (b % 100/10)*a);
	printf("%d\n", (b / 100)*a);
	printf("%d\n", b*a);
}