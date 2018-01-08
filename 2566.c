#include <stdio.h>

//int main()
//{
//	int N = 0;
//	int row = 0, col = 0;
//	int max = 0;
//
//	for (int i = 0; i < 9; i++)
//	{
//		for (int j = 0; j < 9; j++)
//		{
//			scanf("%d", &N);
//			if (max < N)
//			{
//				max = N;
//				row = i + 1;
//				col = j + 1;
//			}
//		}
//	}
//	printf("%d\n%d %d", max, row, col);
//}

int main()
{
	int N[3] = { 0, };
	scanf("%d %d %d", &N[0], &N[1], &N[2]);

	for (int i = 0; i < 3; i++)
	{
		for (int j = i + 1; j < 3; j++)
		{
			if (N[i] > N[j])
			{
				int tmp = 0;
				tmp = N[i];
				N[i] = N[j];
				N[j] = tmp;
			}
		}
	}
	printf("%d %d %d", N[0], N[1], N[2]);

}