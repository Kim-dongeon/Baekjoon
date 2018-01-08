#include <stdio.h>

typedef struct _alpha {
	char ch;
	int n;
}Alpha;

int main()
{
	Alpha alpha[3] = { 0, };
	char c[4] = { 0, };
	for (int i = 0; i < 3; i++)
	{
		scanf("%d", &alpha[i].n);
	}	
	
	scanf("%s", c);
	for (int i = 0; i < 3; i++)
	{
		for (int j = i; j < 3; j++)
		{
			if (alpha[i].n > alpha[j].n)
			{
				Alpha tmp = alpha[i];
				alpha[i] = alpha[j];
				alpha[j] = tmp;
			}
		}
	}
	for (int i = 0; i < 3; i++)
	{
		alpha[i].ch = 'A' + i;
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (c[i] == alpha[j].ch)
			{
				printf("%d ", alpha[j].n);
				break;
			}
		}
	}

}