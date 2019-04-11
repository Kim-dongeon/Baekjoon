#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;
int N, M, K;
int arr[1020][1020];
int isVisited[1020][1020][12];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
struct node {
	int x;
	int y; 
	int d;
};
int main() {
	scanf("%d %d %d", &N, &M, &K);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf(" %1d", &arr[i][j]);
		}
	}
	
	queue<node>que;
	que.push({ 0, 0, K });
	isVisited[0][0][K] = true;
	
	while (!que.empty()) {
		int x = que.front().x;
		int y = que.front().y;
		int d = que.front().d;
		
		que.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M && isVisited[nx][ny][d] == false) {
				if (arr[nx][ny] == 0) {
					//그냥 갈 수 있는 경우
					que.push({ nx,ny,d });
					isVisited[nx][ny][d] = isVisited[x][y][d] + 1;
				}
				else {
					//벽있는 경우
					if (d > 0) {
						if (isVisited[nx][ny][d - 1] == false) {
							que.push({ nx,ny,d - 1 });
							isVisited[nx][ny][d - 1] = isVisited[x][y][d] + 1;
						}
					
					}
				}
			}
		}
	}

	int ans = 987654321;
	for (int i = 0; i <= K; i++) {
		if (isVisited[N - 1][M - 1][i] > 0) {
			ans = min(ans, isVisited[N - 1][M - 1][i]);
		}
	}
	if (ans == 987654321) {
		cout << -1;
	}
	else {
		cout << ans;
	}
}