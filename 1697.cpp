#include <iostream>
#include <queue>
#define MAX 200000
using namespace std;

int dist[200000];
bool check[200000];

int main()
{
	int N, K;
	cin >> N >> K;
	queue<int> que;

	dist[N] = 0;
	check[N] = true;
	que.push(N);
	while (!que.empty())
	{
		int cur = que.front();
		que.pop();

		if (cur - 1 >= 0)
		{
			if (check[cur - 1] == false)
			{
				check[cur - 1] = true;
				que.push(cur - 1);
				dist[cur - 1] = dist[cur] + 1;
			}
		}
		if (cur + 1 <= MAX)
		{
			if (check[cur + 1] == false)
			{
				check[cur + 1] = true;
				que.push(cur + 1);
				dist[cur + 1] = dist[cur] + 1;
			}
		}
		if (cur * 2 <= MAX)
		{
			if (check[cur * 2] == false)
			{
				check[cur * 2] = true;
				que.push(cur * 2);
				dist[cur * 2] = dist[cur] + 1;
			}
		}
	}
	cout << dist[K];
}