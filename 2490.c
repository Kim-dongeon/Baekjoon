#include <stdio.h>

int main()
{
	int n = 3,a=4;
	int num = 0;
	int sum = 0;
	while (n--)
	{
		while (a--)
		{
			scanf("%d", &num);
			sum += num;			
		}
		if (sum == 0) { printf("D\n"); }
		else if (sum == 1) { printf("C\n"); }
		else if (sum == 2) { printf("B\n"); }
		else if (sum == 3) { printf("A\n"); }
		else if (sum == 4) { printf("E\n"); }

		sum = 0;
		a = 4;
	}
}