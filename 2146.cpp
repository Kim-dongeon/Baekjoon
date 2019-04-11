#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int arr[102][102];
int N;
int isVisited[102][102];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int ans = 987654321;
int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	int num = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (isVisited[i][j] == false && arr[i][j] ==1 ) {
				queue<pair<int, int>> que;
				que.push(make_pair(i, j));
				isVisited[i][j] = true;

				while (!que.empty()) {
					int x = que.front().first;
					int y = que.front().second;
					que.pop();
					arr[x][y] = num;
					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];

						if (nx >= 0 && nx < N && ny >= 0 && ny < N&&arr[nx][ny] == 1 && isVisited[nx][ny] == false) {
							que.push(make_pair(nx, ny));
							isVisited[nx][ny] = true;
						}
					}
				}
				num++;
			}
		}
	}

	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] > 0) {
				for (int i = 0; i < N; i++) {
					memset(isVisited[i], 0, sizeof(int)*N);
				}

				int C = arr[i][j];
				queue<pair<int, int>> que;
				isVisited[i][j] = true;
				que.push(make_pair(i, j));

				while (!que.empty()) {
					int x = que.front().first;
					int y = que.front().second;
					que.pop();				
					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];

						if (nx >= 0 && nx < N && ny >= 0 && ny < N&&arr[nx][ny] == 0 && isVisited[nx][ny] == false) {
							que.push(make_pair(nx, ny));
							isVisited[nx][ny] = isVisited[x][y]+1;
						}
						else if (nx >= 0 && nx < N && ny >= 0 && ny < N&&arr[nx][ny] != 0 && arr[nx][ny] != C) {
							ans = min(ans, isVisited[x][y] - 1);
						}
					}
				}
			}
		}		
	}

	cout << ans;

}