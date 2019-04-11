#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;
struct node {
	int x; 
	int y;
	int d;//	¹Ù²Û È½¼ö
};
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int arr[60][60];
int isVisited[60][60][120];
int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}

	queue<node>que;
	que.push({ 0,0,0 });
	isVisited[0][0][0] = true;

	int ans = 987654321;
	while (!que.empty()) {
		int x = que.front().x;
		int y = que.front().y;
		int d = que.front().d;
		que.pop();
		if (x == N - 1 && y == N - 1) {
			ans = min(ans,d);
		}
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx >= 0 && nx < N && ny >= 0 && ny < N && arr[nx][ny] == 1 && isVisited[nx][ny][d] == false) {
				que.push({ nx,ny,d });
				isVisited[nx][ny][d] = isVisited[x][y][d] + 1;
			}
			else if (nx >= 0 && nx < N && ny >= 0 && ny < N && arr[nx][ny] == 0) {
				if (isVisited[nx][ny][d + 1] == false) {
					que.push({ nx,ny,d + 1 });
					isVisited[nx][ny][d + 1] = isVisited[x][y][d]; +1;
				}
			}
		}
	}

	cout << ans;


}