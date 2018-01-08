#include <stdio.h>
#include <string.h>
int main()
{
	char N[11] = { 0, };
	int len = 0;
	gets(N);
	len = strlen(N);
	for (int i = 0; i < len; i++)
	{
		for (int j = i+1; j < len; j++)
		{
			if (N[i]< N[j])
			{
				char tmp = N[i];
				N[i] = N[j];
				N[j] = tmp;
			}
		}
	}
	printf("%s\n", N);
}