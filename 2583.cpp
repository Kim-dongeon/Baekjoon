#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int main()
{
	int M, N, K;
	cin >> M >> N >> K;
	vector<vector<int>> map(N, vector<int>(M,0));
	
	while (K--)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int width = abs(y2 - y1);
		int height = abs(x2 - x1);
		for (int i = x1; i < x1 + height; i++)
		{
			for (int j = y1; j < y1 + width; j++)
			{
				map[i][j] = 1;
			}
		}
	}
	
	queue<pair<int, int>> que;
	bool visited[101][101] = { false, };
	vector<int> v;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 0 && visited[i][j] == false)
			{
				visited[i][j] = true;
				que.push(make_pair(i, j));
				int cnt = 1;
				while (!que.empty())
				{
					int x = que.front().first;
					int y = que.front().second;
					que.pop();
					for (int k = 0; k < 4; k++)
					{
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (nx >= 0 && ny >= 0 && nx < N&&ny < M&&visited[nx][ny] == false&&map[nx][ny] == 0)
						{
							que.push(make_pair(nx, ny));
							visited[nx][ny] = true;
							cnt++;
						}
					}
				}
				v.push_back(cnt);
			}
		}
	}
	sort(v.begin(), v.end());
	printf("%d\n", v.size());
	for (int &a : v)
	{
		printf("%d ", a);
	}

}