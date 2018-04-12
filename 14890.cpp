#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int map1[101][101];
int map2[101][101];
bool impossible[2][101];
bool noSlope[101][101];

void check(int map[][101], int N, int L, int r)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			if (impossible[r][i] == false)
			{
				int slope = map[i][j] - map[i][j + 1];
				if (abs(slope) > 1)
				{
					impossible[r][i] = true;
					break;
				}
				if (slope == 1)
				{
					int temp = map[i][j];
					int nj = j + 1;
					for (int k = 0; k < L; k++)
					{
						if ((map[i][nj] + 1) != temp || nj >= N || noSlope[i][nj] == true)
						{
							impossible[r][i] = true;
							break;
						}
						noSlope[i][nj] = true;
						nj++;
					}
				}
				if (slope == -1)
				{
					int temp = map[i][j + 1];
					int nj = j;
					for (int k = 0; k < L; k++)
					{
						if ((map[i][nj] + 1) != temp || nj < 0 || noSlope[i][nj] == true)
						{
							impossible[r][i] = true;
							break;
						}
						noSlope[i][nj] = true;
						nj--;
					}
				}
			}
			else
			{
				break;
			}
		}
	}
}
int main()
{
	int N, L;
	cin >> N >> L;

	for (int i = 0; i<N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &map1[i][j]);
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			map2[i][j] = map1[j][i];
		}
	}

	check(map1, N, L, 0);
	for (int i = 0; i < N; i++)
	{
		memset(noSlope[i], 0, sizeof(bool)*N);
	}
	check(map2, N, L, 1);

	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		if (impossible[0][i] == false)
		{
			ans++;
		}
		if (impossible[1][i] == false)
		{
			ans++;
		}
	}

	printf("%d\n", ans);
}