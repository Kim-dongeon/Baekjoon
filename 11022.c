#include <stdio.h>

int main()
{
	int T = 0;
	int A, B;
	int i = 1;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d", &A, &B);
		printf("Case #%d: %d + %d = %d\n",i,A,B,A+B);
		i++;
	}

	return 0;
}