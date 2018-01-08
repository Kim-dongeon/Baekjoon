#include <stdio.h>

int fac(int n)
{
	if (n == 1 || n==0)return 1;

	return n*fac(n - 1);
}
int main()
{
	int N = 0;
	scanf("%d", &N);
	printf("%d\n",fac(N));
}