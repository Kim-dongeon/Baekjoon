#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int map[51][51];
bool visited[51][51];
queue<pair<int,int>> q;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int main()
{
	int T, M, N, K;
	int ans = 0;
	cin >> T;
	
	for (int t = 0; t < T; t++)
	{
		cin >> M >> N >> K;
		for (int i = 0; i < K; i++)
		{
			int m1, m2;
			cin >> m1 >> m2;
			map[m1][m2] = 1;
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (map[i][j] == 1 && visited[i][j] == false)
				{
					ans++;
					q.push(make_pair(i, j));
					visited[i][j] = true;

					while (!q.empty())
					{
						int x = q.front().first;
						int y = q.front().second;
						q.pop();
						for (int a = 0; a < 4; a++)
						{
							int nx = dx[a] + x;
							int ny = dy[a] + y;
							if (map[nx][ny] == 1 && visited[nx][ny] == false && nx >= 0 && ny >= 0 && nx < N&& ny < M)
							{
								visited[nx][ny] = true;
								q.push(make_pair(nx, ny));
							}
						}
					}
				}
			}
		}

		printf("%d\n", ans);
		ans = 0;		
		for (int i = 0; i < N; i++)
		{
			memset(visited[i], 0, sizeof(bool)*M);
			memset(map[i], 0, sizeof(int)*M);
		}
	}
}