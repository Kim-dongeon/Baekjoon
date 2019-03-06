#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
int arr[303][303];
int year;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
bool m[303][303];
bool isVisited[303][303];
queue<pair<int, int>> que;
int ice;

int main() {

	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] != 0) {
				ice++;
			}
		}		
	}


	while (ice) {
		//분리
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] != 0) {
					m[i][j] = true;
					int cnt = 0;
					for (int k = 0; k < 4; k++) {
						int nx = i + dx[k];
						int ny = j + dy[k];

						if (nx >= 0 && nx < N && ny >= 0 && ny < M && arr[nx][ny] == 0 && m[nx][ny] == false) {
							cnt++;
						}
					}
					arr[i][j] = arr[i][j] - cnt;
					if (arr[i][j] < 0) {
						arr[i][j] = 0;
					}
					if (arr[i][j] == 0) {
						ice--;
					}				
				}
			}
		}
		for (int i = 0; i < N; i++) {
			memset(m[i], 0, sizeof(bool)*M);
		}
		year++;
		//판단
		
		int continent = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] != 0 && isVisited[i][j] ==false) {
					continent++;
					isVisited[i][j] = true;
					que.push(make_pair(i, j));

					while (!que.empty()) {
						int x = que.front().first;
						int y = que.front().second;

						que.pop();

						for (int k = 0; k < 4; k++) {
							int nx = x + dx[k];
							int ny = y + dy[k];

							if (nx >= 0 && nx < N && ny >= 0 && ny < M && arr[nx][ny] != 0 && isVisited[nx][ny] == false) {
								que.push(make_pair(nx, ny));
								isVisited[nx][ny] = true;
							}
						}
					}
				}
			}
			if (continent >= 2) {
				printf("%d", year);
				return 0;
			}			
		}
		for (int i = 0; i < N; i++) {
			memset(isVisited[i], 0, sizeof(bool)*M);
		}

	}
	
	cout << 0;


}