#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
int arr[22][22];
int isVisited[22][22];
int cur_size = 2;
int cur_eat = 0;
int ans = 0;
queue<pair<int, int>> que;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 9) {
				que.push(make_pair(i, j));
				isVisited[i][j] = 1;
				arr[i][j] = 0;
			}
		}
	}

	while (true) {
		while (!que.empty()) {
			int x = que.front().first;
			int y = que.front().second;
			que.pop();

			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx >= 0 && nx < N && ny >= 0 && ny < N && isVisited[nx][ny] == false && arr[nx][ny] <= cur_size) {
					isVisited[nx][ny] = isVisited[x][y] + 1;
					que.push(make_pair(nx, ny));
				}
			}
		}

		int next_i = -1;
		int next_j = -1;
		int next_dist = 987654321;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[i][j] != 0 && cur_size > arr[i][j] && isVisited[i][j] != 0) {	//먹을 수 있는 애들 중에
					if (isVisited[i][j] - 1 < next_dist) {
						next_i = i;
						next_j = j;
						next_dist = isVisited[i][j] - 1;
					}
				}
			}
		}
		if (next_i == -1 && next_j == -1) {
			break;
		}
		//가서 먹는다
		ans += isVisited[next_i][next_j] - 1;
		
		for (int i = 0; i < N; i++) {
			memset(isVisited[i], 0, sizeof(int)*N);
		}
		isVisited[next_i][next_j] = 1;
		que.push(make_pair(next_i, next_j));
		arr[next_i][next_j] = 0;
		cur_eat++;
		if (cur_eat == cur_size) {
			cur_eat = 0;
			cur_size++;
		} 
	}
	
	cout << ans;

}