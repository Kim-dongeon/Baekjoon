#include <stdio.h>

int main()
{
	int num = 0;
	
	scanf("%d", &num);	
	for (int i = 2; i <= num; i++)
	{			
		if (num % i == 0)
		{
			printf("%d\n", i);
			num = num / i;
			i = 1;			
		}
	}	
}