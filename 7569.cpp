#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int arr[102][102][102];
struct Toma{
	int h;
	int x;
	int y;	
};

int isVisited[102][102][102];
queue<Toma> que;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int dh[2] = { 1,-1 };
int main() {
	
	int N, M, H;
	cin >> M >> N >> H;
	int flag = 0;

	for (int h = 0; h < H; h++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf("%d", &arr[h][i][j]);

				if (arr[h][i][j] == 1) {					
					que.push({ h,i,j });
					isVisited[h][i][j] = 1;
				}
				else if (arr[h][i][j] == -1) {
					isVisited[h][i][j] = -1;
				}
				else {
					flag++;
				}

			}
		}
	}

	while (!que.empty()) {
		int h = que.front().h;
		int x = que.front().x;
		int y = que.front().y;
		que.pop();

		
		for (int k = 0; k < 5; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx >= 0 && ny >= 0 && nx < N && ny < M && arr[h][nx][ny] == 0 && isVisited[h][nx][ny] == 0) {
				que.push({ h,nx,ny });
				isVisited[h][nx][ny] = isVisited[h][x][y] + 1;
			}
		}
		for (int k = 0; k < 2; k++) {
			int nh = h + dh[k];

			if (nh >= 0 && nh < H && arr[nh][x][y] == 0 && isVisited[nh][x][y] == 0) {
				que.push({ nh,x,y });
				isVisited[nh][x][y] = isVisited[h][x][y] + 1;
			}
		}

	}
	

	int ans = 1;
	int day = 0;
	for (int h = 0; h < H; h++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {				
				if (isVisited[h][i][j] == 0) {
					ans = 0;
				}
				day = max(day, isVisited[h][i][j]);
			}			
		}
	}
	
	if (!flag) {
		cout << 0;
	}
	else if (ans) {
		cout << day-1;
	}
	else {
		cout << -1;
	}

}