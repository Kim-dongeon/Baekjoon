#include <iostream>
#include <queue>
using namespace std;
bool visited[101][101];
int main()
{
	int N;
	cin >> N;
	queue<int> q;	
	int arr[101][101];	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	for (int i = 0; i < N; i++)
	{		
		q.push(i);
		while (!q.empty())
		{
			int x = q.front();
			q.pop();
			for (int j = 0; j < N; j++)
			{
				if (visited[i][j] == false && arr[x][j] == 1)
				{
					visited[i][j] = true;
					q.push(j);
				}
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << visited[i][j]<<' ';
		}
		printf("\n");
	}
}