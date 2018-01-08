#include <stdio.h>
#include <string.h>

int main()
{
	char ch[101];
	int check[27] = { 0, };
	char a = 'a';
	char *ptr=NULL;

	scanf("%s", &ch);

	for (int i = 0; i < 26; i++)
	{
		check[i] = -1;
	}
	for (int i = 0; i < 26; i++)
	{
		if ((ptr = strchr(ch, a)) != NULL)
		{
			check[a - 'a'] = ptr-ch;	
		}
		a++;
	}

	for (int i = 0; i < 26; i++)
	{
		printf("%d ", check[i]);
	}
}