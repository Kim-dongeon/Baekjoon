#include <stdio.h>
#include <stdlib.h>

typedef struct _School {

	int alchol;
	char name[21];
}School;

int main()
{
	int loop = 0;
	int school = 0;
	int N = 0;
	
	int max = 0;

	scanf("%d", &loop);	

	for (int i = 0; i < loop; i++)
	{
		scanf("%d", &N);
		School info[100] = { 0, };
		for (int j = 0; j < N; j++)
		{
			scanf("%s %d", info[j].name, &info[j].alchol);			
		}
		for (int j = 0; j < N; j++)
		{			
			if (info[j].alchol > info[max].alchol)
			{
				max = j;				
			}
		}
		printf("%s\n", info[max].name);
	}
}