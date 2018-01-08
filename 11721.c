#include <stdio.h>
#include <string.h>

int main()
{
	char s[101];

	scanf("%s", s);
	for (int i = 0; i < strlen(s); i++)
	{		
		if (i!= 0 && i % 10 == 0)
		{
			printf("\n");
		}
		printf("%c", s[i]);
		
	}
}