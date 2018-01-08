#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
	char ch[101];
	scanf("%s", &ch);

	for (int i = 0; i < strlen(ch); i++)
	{
		if (isupper(ch[i]))
		{
			ch[i] = tolower(ch[i]);
		}
		else
		{
			ch[i] = toupper(ch[i]);
		}
	}
	printf("%s\n", ch);
}