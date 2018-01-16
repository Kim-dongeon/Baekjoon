#include <stdio.h>

int d[200][101];
int score[200];
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			scanf("%d", &d[i][j]);
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < N; j++)
		{
			score[j] += d[j][i];
			for (int k = 0; k < N; k++)
			{
				if (j!=k && d[j][i] == d[k][i])
				{
					score[j] -= d[j][i];
					break;
				}
			}
		}		
	}

	for (int i = 0; i < N; i++)
	{
		printf("%d\n", score[i]);
	}
}