#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int N, M;
int arr[1002][1002];
int isVisited[1002][1002];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
vector<pair<int, int>> wall;
int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 1) {
				wall.push_back(make_pair(i, j));
			}
		}
	}
	int H, W;
	int sx, sy, ex, ey;
	scanf("%d %d %d %d %d %d", &H, &W, &sx, &sy, &ex, &ey);
	sx--;
	sy--;
	ex--;
	ey--;

	queue<pair<int, int>> que;
	que.push(make_pair(sx, sy));
	isVisited[sx][sy] = true;

	
	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		
		if (x == ex && y == ey) {
			break;
		}
		que.pop();
		

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx >= 0 && (nx+H-1) < N && (ny+W-1) < M && ny >= 0 && isVisited[nx][ny] ==0 && arr[nx][ny]==0) {
				bool flag = true;
				for (int i = 0; i < wall.size(); i++) {
					int wx = wall[i].first;
					int wy = wall[i].second;

					int Hb = nx + H - 1;
					int Wb = ny + W - 1;
					if (wx >= nx && wx <= Hb && wy >= ny && wy <= Wb) {
						flag = false;
						break;
					}
				}
				if (flag) {
					isVisited[nx][ny] = isVisited[x][y] + 1;
					que.push(make_pair(nx, ny));
				}
				else {
					continue;
				}
			}
		}
	}
	cout << isVisited[ex][ey] - 1;
}