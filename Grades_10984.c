#include <stdio.h>

int main()
{
	int T = 0;
	int N = 0;
	int point = 0;
	float grade = 0;
	int sum = 0;
	float grade_sum = 0;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d", &N);
		for (int j = 0; j < N; j++)
		{
			scanf("%d %f", &point, &grade);
			sum += point;
			grade_sum += grade*point;
		}
		printf("%d %.1f\n", sum, grade_sum / sum);
		sum = 0;
		grade_sum = 0;
	}
}