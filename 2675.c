#include <stdio.h>
#include <string.h>

int main()
{
	int T = 0, R = 0,len=0;
	char S[21] = { 0, };
	scanf("%d", &T);


	while (T--)
	{
		scanf("%d %s", &R,S);
		len = strlen(S);
		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j < R; j++)
			{
				printf("%c", S[i]);
			}
		}
		printf("\n");
	}
}