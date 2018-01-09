#include <stdio.h>


#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))
#define M 1000
#define N 1000

int path[M][N];
int map[M][N];

int cal_path(int m, int n)
{
	path[0][0] = map[0][0];
	for (int i = 1; i < m; i++)
	{
		path[i][0] = path[i-1][0]+map[i][0];
	}
	for (int i = 1; i < n; i++)
	{
		path[0][i] = path[0][i-1]+map[0][i];
	}

	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			path[i][j] = MAX(path[i][j - 1] , path[i - 1][j])+map[i][j];
			
		}
	}
	
	return path[m - 1][n - 1];
}
int main()
{
	int m, n;
	scanf("%d %d", &m, &n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	printf("%d\n", cal_path(m, n));
}