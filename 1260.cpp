#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int graph[1001][1001];
bool dfs_visited[1001];
bool bfs_visited[1001];
queue<int> q;
stack<int> s;
int N, M, V;


void doDFS(int cur)
{
	dfs_visited[cur] = true;
	printf("%d ", cur);

	for (int i = 1; i <= N; i++)
	{
		if (dfs_visited[i] == false && graph[cur][i])
		{
			doDFS(i);
		}
	}
}

//void doDFS(int cur)
//{
//	s.push(cur);
//
//	while (!s.empty())
//	{
//		int next = s.top();
//		s.pop();
//		if (dfs_visited[next] == false)
//		{
//			dfs_visited[next] = true;
//			printf("%d ", next);
//
//			for (int i = N; i >= 1; i--)
//			{
//				if (!dfs_visited[i] && graph[next][i])
//				{
//					s.push(i);
//				}
//			}
//		}
//	}
//}

void doBFS(int n)
{
	q.push(n);
	bfs_visited[n] = true;

	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		printf("%d ", now);
		for (int i = 1; i <= N; i++)
		{
			if (bfs_visited[i] == false && graph[now][i])
			{
				q.push(i);
				bfs_visited[i] =true;
			}
		}

	}
}

int main()
{
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a][b] = graph[b][a] = 1;
	}

	doDFS(V);
	printf("\n");
	doBFS(V);
	
}