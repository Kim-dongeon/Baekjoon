#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int map[101][101];
bool impossible[2][101];
bool noSlope[101][101];

int main()
{
	int N, L;
	cin >> N >> L;

	for (int i=0;i<N;i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &map[i][j]);	
		}
	}
	
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N-1; j++)
		{
			if (impossible[0][i] == false)
			{
				int slope = map[i][j] - map[i][j + 1];
				if (abs(slope) > 1)
				{
					impossible[0][i] = true;
					break;
				}
				if (slope == 1)
				{
					int temp = map[i][j];
					int nj = j + 1;
					for (int k = 0; k < L; k++)
					{
						if ((map[i][nj]+1) != temp  || nj >= N || noSlope[i][nj] == true)
						{
							impossible[0][i] = true;
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
							impossible[0][i] = true;
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
	for (int i = 0; i < N; i++)
	{
		memset(noSlope[i], 0, sizeof(bool)*N);
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			if (impossible[1][i] == false)
			{
				int slope = map[j][i] - map[j+1][i];
				if (abs(slope) > 1)
				{
					impossible[1][i] = true;
					break;
				}
				if (slope == 1)
				{
					int temp = map[j][i];
					int nj = j + 1;
					for (int k = 0; k < L; k++)
					{
						if ((map[nj][i] + 1) != temp || nj >= N || noSlope[nj][i] == true)
						{
							impossible[1][i] = true;
							break;
						}
						noSlope[nj][i] = true;
						nj++;
					}
				}
				if (slope == -1)
				{
					int temp = map[j+1][i];
					int nj = j;
					for (int k = 0; k < L; k++)
					{
						if ((map[nj][i] + 1) != temp || nj < 0 || noSlope[nj][i] == true)
						{
							impossible[1][i] = true;
							break;
						}
						noSlope[nj][i] = true;
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

	int ans = 0;
	for (int i = 0; i < N; i++)
	{		
		if (impossible[0][i] == false)
		{			
			//printf("aaa%d\n", i);
			ans++;
		}
		if (impossible[1][i] == false)
		{		
			//printf("bbb%d\n", i);
			ans++;
		}
	}

	printf("%d\n", ans);
}