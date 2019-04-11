#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

char arr[1010][1010];
int isVisited[1010][1010];
int fire[1010][1010];
int w, h;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int ans = 987654321;
int main() {
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		scanf("%d %d", &w, &h);

		queue < pair<int, int>> queF;
		queue<pair<int, int>>que;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				scanf(" %c", &arr[i][j]);
				if (arr[i][j] == '*') {
					queF.push(make_pair(i, j));
					fire[i][j] = true;
				}
				else if (arr[i][j] == '@') {
					que.push(make_pair(i, j));
					isVisited[i][j] = true;
				}
			}
		}

		//불 bfs
		while (!queF.empty()) {
			int x = queF.front().first;
			int y = queF.front().second;
			queF.pop();

			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				
				if (nx >= 0 && nx < h && ny >= 0 && ny < w && arr[nx][ny] != '#' && fire[nx][ny] == false) {
					queF.push(make_pair(nx, ny));
					fire[nx][ny] = fire[x][y] + 1;
				}
			}
		}
		//도망
		while (!que.empty()) {
			int x = que.front().first;
			int y = que.front().second;
			
			if (x == 0 || x == h-1 || y == 0 || y == w-1) {
				ans = min(ans, isVisited[x][y]);
			}
			que.pop();
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				
				if (nx >= 0 && nx < h && ny >= 0 && ny < w && arr[nx][ny] != '#' && isVisited[nx][ny] == false) {
					if (fire[nx][ny] ==0 || isVisited[x][y] + 1 < fire[nx][ny]) {
						que.push(make_pair(nx, ny));
						isVisited[nx][ny] = isVisited[x][y] + 1;
					}
				}
			}
		}

		//출력 & 초기화
		if (ans == 987654321) {
			cout << "IMPOSSIBLE" << endl;
		}
		else {
			cout << ans<< endl;
		}
		for (int i = 0; i < h; i++) {
			memset(isVisited[i], 0, sizeof(int)*w);
			memset(fire[i], 0, sizeof(int)*w);
		}
		ans = 987654321;

	}
}