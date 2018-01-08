#include <stdio.h>

int main()
{
	int loop = 0;
	int even = 0;
	int least = 999;
	int n = 0;
	scanf("%d", &loop);
	while (loop--)
	{
		for (int i = 0; i < 7; i++)
		{
			scanf("%d", &n);
			if (n % 2 == 0)
			{
				even += n;
				if (least > n)
				{
					least = n;
				}
			}			
		}
		printf("%d %d\n", even, least);
		even = 0;
		least = 0;
	}	
}