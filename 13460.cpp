#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

char arr[20][20];
int ans = 987654321;
int N, M;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };//동서남북
struct node {
	int rx;
	int ry;
	int bx;
	int by;
};
int move = 0;
int srx, sry;
int sbx, sby;
int ex, ey;
queue<node> que;

int isVisited[20][20][20][20];		//빨x,y,파x,y
bool flag = false;
bool possible;
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf(" %c", &arr[i][j]);
			if (arr[i][j] == 'R') {
				srx = i;
				sry = j;
				arr[i][j] = '.';
			}
			else if (arr[i][j] == 'O') {
				ex = i;
				ey = j;
			}
			else if (arr[i][j] == 'B') {
				sbx = i;
				sby = j;
				arr[i][j] = '.';
			}
		}
	}

	que.push({ srx,sry,sbx,sby });
	isVisited[srx][sry][sbx][sby] = true;
	while (!que.empty()) {
		int rx = que.front().rx;
		int ry = que.front().ry;
		int bx = que.front().bx;
		int by = que.front().by;
		
		que.pop();
		for (int k = 0; k < 4; k++) {
			int nx = rx + dx[k];
			int ny = ry + dy[k];
			if (nx >= 0 && nx < N&&ny >= 0 && ny < M) {
				int ax = rx;
				int ay = ry;

				while (true) {
					if (ax + dx[k] == bx && ay + dy[k] == by) {
						//가다가 파랑 만나면 파랑 먼저 움직여야한다.
						int zx = bx;
						int zy = by;
						while (arr[zx + dx[k]][zy + dy[k]] == '.') {
							zx += dx[k];
							zy += dy[k];
						}
						if (arr[zx + dx[k]][zy + dy[k]] == 'O') {
							break;
						}
						while (ax+dx[k] != zx || ay+dy[k] !=zy) {
							ax += dx[k];
							ay += dy[k];
						}
						if (!isVisited[ax][ay][zx][zy] && isVisited[rx][ry][bx][by] < 11)
						{
							que.push({ ax,ay,zx,zy });
							isVisited[ax][ay][zx][zy] = isVisited[rx][ry][bx][by] + 1;
						}

						break;
					}
					else if (arr[ax + dx[k]][ay + dy[k]] == '#') {
						//빨강이 끝에 도달한 경우 
						//파랑 움직여 준다.
						int zx = bx;
						int zy = by;
						while (arr[zx + dx[k]][zy + dy[k]] == '.' && (zx + dx[k] != ax || zy + dy[k] != ay)) {
							zx += dx[k];
							zy += dy[k];
						}
						if (arr[zx + dx[k]][zy + dy[k]] == 'O') {
							break;
						}
						if (!isVisited[ax][ay][zx][zy] && isVisited[rx][ry][bx][by] < 11)
						{
							que.push({ ax,ay,zx,zy });
							isVisited[ax][ay][zx][zy] = isVisited[rx][ry][bx][by] + 1;
						}

						break;
					}
					else if (arr[ax + dx[k]][ay + dy[k]] == 'O') {
						//구멍에 들어간 경우
						//파랑 움직인다
						int zx = bx;
						int zy = by;
						while (arr[zx + dx[k]][zy + dy[k]] == '.') {
							zx += dx[k];
							zy += dy[k];
						}
						if (arr[zx + dx[k]][zy + dy[k]] != 'O' && isVisited[rx][ry][bx][by]<11) {
							//같이 빠져버리지 않으면 
							ans = min(ans, isVisited[rx][ry][bx][by] + 1);
						}

						break;
					}
					else {
						//.인경우 그냥 움직여 준다
						ax += dx[k];
						ay += dy[k];
					}
				}//while				
			}			
		}
	}

	if (ans == 987654321) {
		ans = 0;
	}

	cout << ans-1;
}