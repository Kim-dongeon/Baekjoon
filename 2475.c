#include <stdio.h>
#include <math.h>
int main()
{
	int sum = 0;
	int n = 0;

	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &n);
		sum += pow(n, 2);
	}
	printf("%d", sum%10);
}