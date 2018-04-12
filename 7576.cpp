#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int map[1001][1001];
queue<pair<int, int>> q;
bool visited[1001][1001];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
vector<pair<int, int>> v;
int main()
{
	int M, N;
	cin >> M >> N;
	int a_day = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1)
			{
				v.push_back(make_pair(i, j));
				a_day++;
			}
		}
	}
	
	for (auto x : v)
	{
		q.push(make_pair(x.first, x.second));
		visited[x.first][x.second] = true;		
	}
	int temp = 0;
	int ans = 0;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		if (a_day == 0)
		{
			ans++;
			a_day = temp;
			temp = 0;
		}
		a_day--;
		for (int k = 0; k < 4; k++)
		{
			int nx = dx[k] + x;
			int ny = dy[k] + y;
			if (nx < N && ny < M && nx >= 0 && ny >= 0 && visited[nx][ny] == false && map[nx][ny] == 0)
			{
				q.push(make_pair(nx, ny));
				visited[nx][ny] = true;
				temp++;
			}
		}	
	}
	bool flag = false;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 0 && visited[i][j] == false)
			{
				printf("-1\n");
				flag = true;
				break;
			}
		}
	}
	if (flag == false)
	{
		printf("%d\n", ans);
	}

}