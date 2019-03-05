#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int N, M;
char arr[100][100];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int cnt;
bool water_visited[100][100];
queue<pair<int, int>> que;

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf(" %c", &arr[i][j]);			
		}
	}

	bool find_D = false;
	while (!find_D) {
		
		cnt++;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] == 'S') {
					que.push(make_pair(i, j));
					arr[i][j] = '.';
				}
			}
		}

		if (que.empty()) {
			cout << "KAKTUS" << endl;
			break;
		}
		while (!que.empty()) {
			int x = que.front().first;
			int y = que.front().second;
			que.pop();
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx >= 0 && nx < N && ny >= 0 && ny < M){
					if (arr[nx][ny] == '.') {
						arr[nx][ny] = 'S';
					}
					else if (arr[nx][ny] == 'D') {
						cout << cnt << endl;
						find_D = true;
						break;
					}
				}
			}
			if (find_D) {
				break;
			}
		}

		if (find_D) {
			break;
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] == '*') {
					que.push(make_pair(i, j));
					water_visited[i][j] = true;
				}
			}
		}

		while (!que.empty()) {
			int x = que.front().first;
			int y = que.front().second;
			que.pop();
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx >= 0 && nx < N && ny >= 0 && ny < M && arr[nx][ny] != 'D' && arr[nx][ny] != 'X' && water_visited[nx][ny] == false ) {
					arr[nx][ny] = '*';
				}
			}
		}


	}
	

}