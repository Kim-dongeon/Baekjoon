#include <stdio.h>

int main()
{
	int N=0,max=0,num = 0;

	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &N);
		
		if (max < N)
		{
			max = N;	
			num = i+1;
		}
	}
	printf("%d\n%d", max,num);
	
}