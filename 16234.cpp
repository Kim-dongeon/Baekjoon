#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std;

int N, L, R;
int arr[52][52];
int ally = 1;
int isVisited[52][52];

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int main() {
	cin >> N >> L >> R;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	queue<pair<int, int>> que;

	int ans = 0;
	while (true) {
		bool flag = false;
		vector<int> change;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (isVisited[i][j] == 0) {
					int ally_sum = 0;
					int ally_cnt = 0;

					que.push(make_pair(i, j));
					isVisited[i][j] = ally;

					while (!que.empty()) {
						int x = que.front().first;
						int y = que.front().second;
						que.pop();
						ally_sum += arr[x][y];
						ally_cnt++;

						for (int k = 0; k < 4; k++) {
							int nx = dx[k] + x;
							int ny = dy[k] + y;

							if (nx >= 0 && nx < N&&ny < N &&ny >= 0 && isVisited[nx][ny] == 0) {
								int m = abs(arr[x][y] - arr[nx][ny]);
								if (L <= m && m <= R) {
									flag = true;
									que.push(make_pair(nx, ny));
									isVisited[nx][ny] = isVisited[x][y];
								}
							}
						}
					}
				
					int people = ally_sum / ally_cnt;
					change.push_back(people);
					
					ally++;
				}
				
			}
		}

		if (flag) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (isVisited[i][j]) {
						arr[i][j] = change[isVisited[i][j] - 1];
					}					
				}
			}
			ans++;
			ally = 1;
			change.clear();
			for (int i = 0; i < N; i++) {
				memset(isVisited[i], 0, sizeof(int)*N);
			}
		}
		else {
			cout << ans;
			break;
		}
	}
	
}