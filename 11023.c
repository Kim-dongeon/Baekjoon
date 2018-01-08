#include <stdio.h>
#include <string.h>


int main()
{
	int n, sum = 0;
	int a = 0;
	while ((a = scanf(" %d", &n)) >0)
	{		
		sum += n;
	}
	printf("%d\n", sum);
}