#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

bool prime[10001];
bool visited[10001];
int dist[10001];

int swap(int cur, int i, int j)
{
	if (i == 0 && j == 0) return -1;

	string s = to_string(cur);
	s[i] = j+'0';
	return stoi(s);

}
int main()
{
	for (int i = 2; i <= 10000; i++)
	{
		if (prime[i] == false)
		{
			for (int j = i*i; j <= 10000; j += i)
			{
				prime[j] = true;
			}
		}
	}
	int T;
	cin >> T;
	queue<int> que;
	while (T--)
	{
		int n, k;
		cin >> n >> k;

		que.push(n);
		dist[n] = 0;
		visited[n] = true;

		while (!que.empty())
		{
			int cur = que.front();
			que.pop();
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j <= 9; j++)
				{
					int next = swap(cur, i, j);
					if (next != -1 && !prime[next] && visited[next] == false)
					{
						que.push(next);
						visited[next] = true;
						dist[next] = dist[cur] + 1;
					}
				}
			}
		}
		if (n != k && dist[k] == 0)
		{
			printf("Impossible\n");
		}
		else {
			printf("%d\n", dist[k]);
		}
		
		memset(visited, 0, 10001);
		memset(dist, 0, 10001);
	}
}