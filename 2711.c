#include <stdio.h>
#include <string.h>

int main()
{
	int T = 0;
	int n = 0;
	char ch[81] = { 0, };
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		scanf("%s", ch);
		for (int i = 0; i < strlen(ch); i++)
		{
			if (i+1 == n) continue;
			printf("%c", ch[i]);
		}
		printf("\n");

	}
}