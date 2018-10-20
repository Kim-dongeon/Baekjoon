#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int arr[10][10];
bool isVisted[10][10];
int Max_safe;
queue<pair<int,int>> que;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
void go(int set[], int size, int n, int k, int index,int N, int M)
{	
	if (k == 0)
	{
		for (int i = 0; i < size; i++)
		{
			if (arr[set[i] / M][set[i] % M] != 0)
			{
				return;
			}
		}

		for (int i = 0; i < size; i++)
		{
			isVisted[set[i] / M][set[i] % M] = true;
			
		}
	
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (isVisted[i][j] == false && arr[i][j] == 2)
				{
					que.push(make_pair(i, j));
					isVisted[i][j] = true;

					while (!que.empty())
					{
						int x = que.front().first;
						int y = que.front().second;
						que.pop();
						for (int k = 0; k < 4; k++)
						{
							int nx = dx[k] + x;
							int ny = dy[k] + y;
							if (nx >= 0 && ny >= 0 && nx < N && ny < M&&arr[nx][ny] == 0 && isVisted[nx][ny] == false)
							{
								que.push(make_pair(nx, ny));
								isVisted[nx][ny] = true;
							}
						}
					}
				}
			}
		}

		int cnt = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (isVisted[i][j] == false && arr[i][j] != 1 )
				{
					cnt++;
				}
			}
		}
		Max_safe = max(Max_safe, cnt);
		memset(isVisted, false, sizeof(isVisted));
		return;
	}
	else if (n == index)
	{
		return;
	}

	set[size] = index;
	go(set, size + 1, n, k - 1, index + 1, N, M);
	go(set, size, n, k, index + 1, N, M);
}
int main()
{
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}

	int _set[100];
	go(_set, 0, N*M, 3, 0, N, M);

	cout << Max_safe;
}