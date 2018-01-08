#include <stdio.h>
#include <string.h>

int main()
{
	int n = 0;
	int num[1001] = { 0, };
	int i = 0;
	scanf("%d", &n);
	
	while (n--)
	{		
		scanf("%d", &num[i]);
		i++;
	}	
	for (int a = 0; a < i; a++)
	{
		for (int b = a; b < i ; b++)
		{
			if (num[a] > num[b])
			{
				int tmp = num[a];
				num[a] = num[b];
				num[b] = tmp;
			}
		}
	}
	for (int a = 0; a < i ; a++)
	{
		printf("	%d\n", num[a]);
	}
}