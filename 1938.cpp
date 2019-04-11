#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

struct node {
	int x;
	int y;
	int d;
	//가로 0, 세로 1
};
int isVisited[52][52][2];
char arr[52][52];
int dx[] = { -1,1,0,0 };//위 아래 좌 우
int dy[] = { 0,0,-1,1 };
int main() {
	int N;
	scanf("%d", &N);
	int sx = -1, sy = -1;
	int ex = -1, ey = -1;
	int sd = -1, ed = -1;
	int B = 0;
	int E = 0;
	int px = 0, py = 0;
	int p1 = 0 , p2 = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf(" %c", &arr[i][j]);
			if (arr[i][j] == 'B') {
				B++;
				
				if (B == 2) {
					sx = i;
					sy = j;
					if (sy == py) {
						sd = 1;
					}
					else if (px == sx) {
						sd = 0;
					}
				}
				px = i;
				py = j;
				arr[i][j] = '0';
			}
			else if (arr[i][j] == 'E') {
				E++;
				
				if (E == 2) {
					ex = i;
					ey = j;
					if (ey == p2) {
						ed = 1;
					}
					else if (p1 == ex) {
						ed = 0;
					}
				}
				p1 = i;
				p2 = j;
				arr[i][j] = '0';
			}
		}
	}
	queue<node> que;
	que.push({ sx,sy,sd });
	isVisited[sx][sy][sd] = true;

	while (!que.empty()) {
		int x = que.front().x;
		int y = que.front().y;
		int d = que.front().d;
		que.pop();
		//상하좌우 움직이기
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (d == 1) {
				if (k == 0 || k == 1) {
					//범위체크
					if (nx - 1 >= 0 && nx + 1 < N) {
						if (arr[nx - 1][ny] == '0' && arr[nx][ny] == '0' && arr[nx + 1][ny] == '0') {
							//움직일 수 있다면
							if (isVisited[nx][ny][d] == false) {
								que.push({ nx,ny,d });
								isVisited[nx][ny][d] = isVisited[x][y][d] + 1;
							}
						}
					}
				}
				else if (k == 2 || k == 3) {
					if (ny >= 0 && ny < N) {
						if (arr[nx - 1][ny] == '0' && arr[nx][ny] == '0' && arr[nx + 1][ny] == '0') {
							//움직일 수 있다면
							if (isVisited[nx][ny][d] == false) {
								que.push({ nx,ny,d });
								isVisited[nx][ny][d] = isVisited[x][y][d] + 1;
							}
						}
					}
				}
			}
			else if (d == 0) {
				if (k == 0 || k == 1) {
					//범위체크
					if (nx >= 0 && nx  < N) {
						if (arr[nx][ny-1] == '0' && arr[nx][ny] == '0' && arr[nx][ny+1] == '0') {
							//움직일 수 있다면
							if (isVisited[nx][ny][d] == false) {
								que.push({ nx,ny,d });
								isVisited[nx][ny][d] = isVisited[x][y][d] + 1;
							}
						}
					}
				}
				else if (k == 2 || k == 3) {
					if (ny-1 >= 0 && ny+1 < N) {
						if (arr[nx][ny-1] == '0' && arr[nx][ny] == '0' && arr[nx][ny+1] == '0') {
							//움직일 수 있다면
							if (isVisited[nx][ny][d] == false) {
								que.push({ nx,ny,d });
								isVisited[nx][ny][d] = isVisited[x][y][d] + 1;
							}
						}
					}
				}
			}			
		}

		//회전
		if (d == 0) {
			if (x - 1 >= 0 && x + 1 < N) {
				int ny = y - 1;
				int flag = true;
				for (int i = 0; i < 3; i++) {
					if (arr[x-1][ny + i] != '0') {
						flag = false;
					}
				}
				for (int i = 0; i < 3; i++) {
					if (arr[x + 1][ny + i] != '0') {
						flag = false;
					}
				}

				if (flag) {
					//회전 가능한 경우
					if (isVisited[x][y][1] == false) {
						que.push({ x,y,1 });
						isVisited[x][y][1] = isVisited[x][y][0] + 1;
					}					
				}
			}
		}
		else if (d == 1) {
			if (y - 1 >= 0 && y + 1 <N) {
				int nx = x - 1;
				int flag = true;
				for (int i = 0; i < 3; i++) {
					if (arr[nx+i][y-1] != '0') {
						flag = false;
					}
				}
				for (int i = 0; i < 3; i++) {
					if (arr[nx + i][y + 1] != '0') {
						flag = false;
					}
				}

				if (flag) {
					//회전 가능한 경우
					if (isVisited[x][y][0] == false) {
						que.push({ x,y,0 });
						isVisited[x][y][0] = isVisited[x][y][1] + 1;
					}
				}
			}
		}
	}
	int ans = isVisited[ex][ey][ed];
	if (ans == 0) {
		cout << 0;
	}
	else {
		cout << ans - 1;
	}
	
}