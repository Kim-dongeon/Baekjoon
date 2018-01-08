#include <stdio.h>

int main()
{
	char arr[9][9] = { 0, };
	int cnt = 0;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			scanf(" %c", &arr[i][j]);
			if (i % 2 == 0)
			{
				if (j % 2 == 0)
				{					
					if (arr[i][j] == 'F')
					{
						cnt++;						
					}
				}
			}
			else
			{
				if (j % 2 == 1)
				{
					if (arr[i][j] == 'F')
					{
						cnt++;						
					}
				}
			}
		}
	}

	printf("%d\n", cnt);


}