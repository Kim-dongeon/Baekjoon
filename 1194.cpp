#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

struct node {
	int x;
	int y;
	int key;
};
int N, M;
char arr[52][52];
int isVisited[52][52][65];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int main() {
	cin >> N >> M;

	queue<node> que;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf(" %c", &arr[i][j]);
			if (arr[i][j] == '0') {
				que.push({ i,j,0 });
				isVisited[i][j][0] = 1;
			}
		}
	}

	int ans = 987654321;
	while (!que.empty()) {
		int x = que.front().x;
		int y = que.front().y;
		int key = que.front().key;
		que.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx >= 0 && nx < N&&ny >= 0 && ny < M&&arr[nx][ny] != '#'&&isVisited[nx][ny][key] == 0) {
				if (arr[nx][ny] >= 'a' && arr[nx][ny] <= 'f') {
					int new_key = (1<<(arr[nx][ny] - 'a'))| key;
					que.push({ nx,ny,new_key });
					isVisited[nx][ny][new_key] = isVisited[x][y][key] + 1;
				}
				else if (arr[nx][ny] >= 'A' && arr[nx][ny] <= 'F') {
					int door = 1 << (arr[nx][ny] - 'A');
					if (door & key) {
						que.push({nx, ny, key});
						isVisited[nx][ny][key] = isVisited[x][y][key] + 1;
					}
				}
				else {
					que.push({ nx,ny,key });
					isVisited[nx][ny][key] = isVisited[x][y][key] + 1;
				}

				if (arr[nx][ny] == '1') {
					ans = min(ans, isVisited[nx][ny][key]);
				}
			}
		}
	}
	if (ans == 987654321) {
		cout << -1;
	}
	else {
		cout << ans-1;
	}
	
}
