#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int arr[202][202];
struct node {
	int x;
	int y;
	int d;
};
int isVisited[202][202][32];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int kx[] = { -2,-2,-1,1,2,2,1,-1 };
int ky[] = { 1,-1,-2,-2,-1,1,2,2 };
int main() {
	int K;
	int W, H;
	cin >> K >> W >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	queue<node> que;

	que.push({ 0,0,K });
	isVisited[0][0][K] = true;

	while (!que.empty()) {
		int x= que.front().x;
		int y = que.front().y;
		int d = que.front().d;
		que.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx >= 0 && nx < H&&ny >= 0 && ny < W&&arr[nx][ny] == 0 && isVisited[nx][ny][d] == false) {
				que.push({ nx,ny,d });
				isVisited[nx][ny][d] = isVisited[x][y][d] +1;
			}			
		}

		if (d > 0) {
			for (int k = 0; k < 8; k++) {
				int nx = x + kx[k];
				int ny = y + ky[k];
				if (nx >= 0 && nx < H&&ny >= 0 && ny < W&&arr[nx][ny] == 0 && isVisited[nx][ny][d-1] == false) {
					que.push({ nx,ny,d-1 });
					isVisited[nx][ny][d-1] = isVisited[x][y][d]+1;
				}
			}
		}
	}

	int ans = 987654321;
	for (int i = 0; i <= K; i++) {
		if (isVisited[H - 1][W - 1][i] > 0) {
			ans = min(ans, isVisited[H - 1][W - 1][i]);
		}
	}
	if (ans == 987654321) {
		cout << -1;
	}
	else {
		cout << ans - 1;
	}
	
}