#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

char arr[100][100];
queue<pair<int, int>> que;
int isVisited[100][100];
int max_dist = -1;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf(" %c", &arr[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 'L') {
				que.push(make_pair(i, j));
				isVisited[i][j] = 1;
				int tmp_max = -1;

				while (!que.empty()) {
					int x = que.front().first;
					int y = que.front().second;
					que.pop();
					tmp_max = max(tmp_max, isVisited[x][y]);

					for (int k = 0; k < 4; k++) {
						int nx = dx[k] + x;
						int ny = dy[k] + y;
						if (nx >= 0 && ny >= 0 && nx < N && ny < M && arr[nx][ny] == 'L' && isVisited[nx][ny] == 0) {
							isVisited[nx][ny] = isVisited[x][y] + 1;
							que.push(make_pair(nx, ny));
						}
					}
				}
				max_dist = max(max_dist, (tmp_max - 1));
				for (int i = 0; i < N; i++) {
					memset(isVisited[i], 0, sizeof(int)*M);
				}
			}
		}
	}

	cout << max_dist;
}