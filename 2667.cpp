#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int map[26][26];
queue<pair<int,int>> q;
bool visited[26][26];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}

	int sum = 0;
	vector<int> v;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 1 && visited[i][j] == false)
			{
				q.push(make_pair(i, j));
				visited[i][j] = true;
				sum++;

				int num = 1;
				while (!q.empty())
				{
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for (int k = 0; k < 4; k++)
					{
						int nx = dx[k] + x;
						int ny = dy[k] + y;
						if (map[nx][ny] ==1 && visited[nx][ny] == false && nx < N && ny < N && nx >= 0 && ny >= 0)
						{
							visited[nx][ny] = true;
							q.push(make_pair(nx, ny));
							num++;
						}
					}
				}
				v.push_back(num);
			}
		}
	}

	printf("%d\n", sum);
	sort(v.begin(), v.end());
	for (int x : v)
	{
		printf("%d\n", x);
	}
}