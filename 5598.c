#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char str[1001] = { 0, };
	int len = 0;

	scanf("%s", str);
	len = strlen(str);

	for (int i = 0; i < len; i++)
	{
		if (str[i] <= 'C')
		{
			str[i] += 23;
		}
		else
		{
			str[i] -= 3;
		}
	}
	printf("%s", str);
}