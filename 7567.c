#include <stdio.h>
#include <string.h>

int main()
{
	char plate[51] = { 0, };
	int height = 10;

	scanf("%s", plate);
	
	for (int i = 0; i < strlen(plate)-1; i++)
	{
		if (plate[i] != plate[i + 1])
		{
			height += 10;
		}
		else
		{
			height += 5;
		}
	}

	printf("%d\n", height);


}