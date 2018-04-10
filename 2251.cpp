#include <iostream>
#include <queue>

using namespace std;
queue<pair<int, int>> que;
bool visited[201][201];
bool dist[201];

int main()
{
	int A, B, C;
	cin >> A >> B >> C;
	
	dist[C] = true;
	visited[0][0] = true;
	que.push(make_pair(0, 0));

	while (!que.empty())
	{
		int x = que.front().first;
		int y = que.front().second;
		int z = C-x-y;
		que.pop();
		int nx = x;
		int ny = y;
		int nz = z;
		//x->y
		ny += nx;
		nx = 0;
		if (ny > B)
		{
			nx = ny - B;
			ny = B;
		}
		if (visited[nx][ny] == false)
		{
			visited[nx][ny] = true;
			que.push(make_pair(nx, ny));
			if (nx == 0)
			{
				dist[nz] = true;
			}
		}
		//x->z
		nx = x;
		ny = y;
		nz = z;
		
		nz += nx;
		nx = 0;
		if (nz > C)
		{
			nx = nz- C;
			nz = C;
		}
		if (visited[nx][ny] == false)
		{
			visited[nx][ny] = true;
			que.push(make_pair(nx, ny));
			if (nx == 0)
			{
				dist[nz] = true;
			}
		}
		//y->x
		nx = x;
		ny = y;
		nz = z;
	
		nx += ny;
		ny = 0;
		if (nx > A)
		{
			ny = nx -A;
			nx = A;
		}
		if (visited[nx][ny] == false)
		{
			visited[nx][ny] = true;
			que.push(make_pair(nx, ny));
			if (nx == 0)
			{
				dist[nz] = true;
			}
		}
		//y->z
		nx = x;
		ny = y;
		nz = z;

		nz += ny;
		ny = 0;
		if (nz > C)
		{
			ny = nz - C;
			nz = C;			
		}
		if (visited[nx][ny] == false)
		{
			visited[nx][ny] = true;
			que.push(make_pair(nx, ny));
			if (nx == 0)
			{
				dist[nz] = true;
			}
		}
		//z->x
		nx = x;
		ny = y;
		nz = z;

		nx += nz;
		nz = 0;
		if (nx > A)
		{
			nz = nx - A;
			nx = A;
		}
		if (visited[nx][ny] == false)
		{
			visited[nx][ny] = true;
			que.push(make_pair(nx, ny));

			if (nx == 0)
			{
				dist[nz] = true;
			}
		}
		//z->y
		nx = x;
		ny = y;
		nz = z;

		ny += nz;
		nz = 0;
		if (ny > B)
		{
			nz = ny - B;
			ny = B;
		}
		if (visited[nx][ny] == false)
		{
			visited[nx][ny] = true;
			que.push(make_pair(nx, ny));

			if (nx == 0)
			{
				dist[nz] = true;			
		
			}
		}
	}
	
	for (int i = 0; i <= C; i++)
	{
		if (dist[i] == true)
		{
			printf("%d ", i);
		}
	}
}