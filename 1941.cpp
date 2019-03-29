#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int N=5;
char arr[30][30];
int ans = 0;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int set[30];
void dfs(int sz, int n, int k ,int index) {
	if (k == 0) {
		int y_cnt = 0;
		int cpy[30][30] = { 0, };
		
		for (int i = 0; i < sz; i++) {
			int x = set[i] / 5;
			int y = set[i] % 5;

			if (arr[x][y] == 'Y') {
				y_cnt++;
				if (y_cnt >= 4) {
					return;
				}
			}
			cpy[x][y] = 1;
			
		}
		/*for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << cpy[i][j] << ' ';
			}
			cout << endl;
		}
		cout << endl;*/
		queue<pair<int, int>> que;
		int isVisited[30][30] = { 0, };
		int sx = set[0] / 5;
		int sy = set[0] % 5;
		que.push(make_pair(sx, sy));
		isVisited[sx][sy] = true;
		int chk = 0;
		while (!que.empty()) {
			int x = que.front().first;
			int y = que.front().second;
			que.pop();
			chk++;
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx >= 0 && nx < N&&ny >= 0 && ny < N&&cpy[nx][ny] == 1 && isVisited[nx][ny] == false) {
					que.push(make_pair(nx, ny));
					isVisited[nx][ny] = isVisited[x][y]+1;
					
				}
			}
		}
		//cout << chk << endl;
		if (chk == 7) {
			ans++;
		}
		return;
	}
	else if (n == index) {
		return;
	}
	set[sz] = index;
	dfs(sz + 1, n, k - 1, index + 1);
	dfs(sz, n, k, index + 1);
}
int main() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf(" %c", &arr[i][j]);
		}
	}

	dfs(0, 25, 7, 0);
	cout << ans;
}