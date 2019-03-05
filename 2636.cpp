#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int arr[102][102];
int N, M;
queue<pair<int, int>> que;
bool isVisited[102][102];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0, };

int cnt;

int cur_cheese;
int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 1) {
				cur_cheese++;
			}
		}
	}

	que.push(make_pair(0, 0));
	isVisited[0][0] = true;

	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();
		arr[x][y] = 3;
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx >= 0 && ny >= 0 && nx < N && ny < M && arr[nx][ny] == 0 && isVisited[nx][ny] == false) {
				que.push(make_pair(nx, ny));
				isVisited[nx][ny] = true;
			}
		}
	}

	while (true) {
		int last_cheese=0;
		cnt++;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] == 1) {
					if (arr[i - 1][j] == 3 || arr[i + 1][j] == 3 || arr[i][j - 1] == 3 || arr[i][j + 1] == 3) {
						last_cheese++;
						cur_cheese--;
						arr[i][j] = 4;
					}
				}
			}
		}

		if (cur_cheese == 0) {
			cout << cnt << endl;
			cout << last_cheese << endl;
			break;
		}

		for (int i = 0; i < N; i++) {
			memset(isVisited[i], false, sizeof(bool)*M);
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] == 4) {
					arr[i][j] = 3;
				}
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] == 0) {
					if (arr[i - 1][j] == 3 || arr[i + 1][j] == 3 || arr[i][j - 1] == 3 || arr[i][j + 1] == 3) {
						que.push(make_pair(i, j));
						isVisited[i][j] = true;

						while (!que.empty()) {
							int x = que.front().first;
							int y = que.front().second;
							que.pop();
							arr[x][y] = 3;
							for (int k = 0; k < 4; k++) {
								int nx = x + dx[k];
								int ny = y + dy[k];
								if (nx >= 0 && ny >= 0 && nx < N && ny < M && arr[nx][ny] == 0 && isVisited[nx][ny] == false) {
									que.push(make_pair(nx, ny));
									isVisited[nx][ny] = true;
								}
							}
						}
					}				
				}
			}
		}

	}
	

}