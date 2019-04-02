#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

int N;
int arr[302][302];
int isVisited[302][302];
int sx, sy;
int ex, ey;
int dx[] = { -2,-2,-1,1,2,2,1,-1 };
int dy[] = { 1,-1,-2,-2,-1,1,2,2 };
int main() {
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		scanf("%d", &N);
		
		scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
		queue<pair<int, int>> que;
		
		que.push(make_pair(sx, sy));
		isVisited[sx][sy] = true;

		while (!que.empty()) {
			int x = que.front().first;
			int y = que.front().second;
			que.pop();

			for (int k = 0; k < 8; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx >= 0 && nx < N&&ny >= 0 && ny < N&&isVisited[nx][ny] == false) {
					que.push(make_pair(nx, ny));
					isVisited[nx][ny] = isVisited[x][y] + 1;
				}
			}
			
		}


		printf("%d\n", isVisited[ex][ey] - 1);
		for (int i = 0; i < N; i++) {
			memset(isVisited[i], 0, sizeof(int)*N);
		}
	}
}