#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
	char ch[101] = { 0, };
	int len = 0;
	int upper=0, lower=0, digit=0, space = 0;
	
	while (gets(ch) != '\0')
	{
		len = strlen(ch);
		upper = 0, lower = 0, digit = 0, space = 0;
		for (int i = 0; i < len; i++)
		{
			if (islower(ch[i]))
			{
				lower++;
			}
			if (isupper(ch[i]))
			{
				upper++;
			}
			if (isspace(ch[i]))
			{
				space++;
			}
			if (isdigit(ch[i]))
			{
				digit++;
			}
		}
		printf("%d %d %d %d\n", lower, upper, digit, space);
	}
	
}