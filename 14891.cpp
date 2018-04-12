#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cstring>

using namespace std;
vector<string> v(5);
#define right 2
#define left 6
queue<int> q;
int dist[5];
bool visited[5];
int dx[2] = { 1,-1 };
void rotate(int w, int d)
{
	if (d == 1)
	{
		int temp = v[w][7];
		for (int i = 7; i >= 1; i--)
		{
			v[w][i] = v[w][i - 1];
		}
		v[w][0] = temp;
	}
	if (d == -1)
	{
		int temp = v[w][0];
		for (int i = 0; i <7; i++)
		{
			v[w][i] = v[w][i + 1];
		}
		v[w][7] = temp;
	}
}
int main()
{
	for (int i = 0; i < 4; i++)
	{
		cin >> v[i + 1];
	}
	int K = 0;
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		int w = 0, d = 0;
		cin >> w >> d;

		dist[w] = d;
		visited[w] = true;
		q.push(w);

		while (!q.empty())
		{
			int x = q.front();			
			q.pop();
			for (int k = 0; k < 2; k++)
			{
				int nx = dx[k] + x;
				if (nx >= 1 && nx < 5 && visited[nx] == false)
				{
					q.push(nx);
					visited[nx] = true;
					if (dx[k] ==1)
					{
						if (v[x][right] != v[nx][left] && dist[x] != 3)
						{
							dist[nx] = -1 * dist[x];
						}
						else if(v[x][right] == v[nx][left] || dist[x] == 3)
						{
							dist[nx] = 3;
						}
					}
					if (dx[k] ==-1)
					{
						if (v[x][left] != v[nx][right] && dist[x] !=3)
						{
							dist[nx] = -1 * dist[x];
						}
						else if (v[x][left] == v[nx][right] || dist[x] == 3)
						{
							dist[nx] = 3;
						}
					}
				}
			}
		}

		for (int j = 1; j <= 4; j++)
		{
			if (dist[j] != 3)
			{
				rotate(j, dist[j]);
			}
		}

		memset(dist, 0, sizeof(dist));
		memset(visited, 0, sizeof(visited));
	}



	int sum = 0;
	
	if (v[1][0] == '1')
	{
		sum = sum + 1;
	}

	if (v[2][0] == '1')
	{
		sum = sum + 2;
	}

	if (v[3][0] == '1')
	{
		sum = sum + 4;
	}

	if (v[4][0] == '1')
	{
		sum = sum + 8;
	}
	printf("%d\n", sum);
}
