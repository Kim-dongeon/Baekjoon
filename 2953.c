#include <stdio.h>

int main()
{
	int best = 0, score = 0, mvp = 0, tmp_score = 0;;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int tmp = 0;
			scanf("%d", &tmp);
			score += tmp;
		}
		if (tmp_score < score)
		{
			mvp = i;
			tmp_score = score;
		}
		score = 0;
	}
	printf("%d %d", mvp+1, tmp_score);
}