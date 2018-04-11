#include <iostream>
#include <queue>

using namespace std;

int dist[1000001];
queue<int> q;
bool visited[1000001];

int main()
{
	int F, S, G, U, D;
	cin >> F >> S >> G >> U >> D;

	dist[S] = 0;
	visited[S] = true;
	q.push(S);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		int next = cur + U;
		if (next > F)
		{
			next = cur;
		}
		if (visited[next] == false)
		{
			visited[next] = true;
			dist[next] = dist[cur] + 1;
			q.push(next);
		}


		next = cur - D;
		if (next < 1)
		{
			next = cur;
		}
		if (visited[next] == false)
		{
			visited[next] = true;
			dist[next] = dist[cur] + 1;
			q.push(next);
		}
	}

	if (dist[G] == 0 && S != G)
	{
		printf("use the stairs");
	}
	else
	{
		printf("%d\n", dist[G]);
	}
}