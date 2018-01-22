#include <stdio.h>
#include <string.h>
int main()
{
	char n1[4] = { 0, }, n2[4] = { 0, };
	
	for (int i=2;i>=0;i--)
	{
		scanf("%1c", &n1[i]);
	}
	getc(stdin);
	for (int i = 2; i >= 0; i--)
	{
		scanf("%1c", &n2[i]);
	}
	if (strcmp(n1, n2) > 0)
	{
		printf("%s", n1);
	}
	else
	{
		printf("%s", n2);
	}
	
}