#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
	int x;
	int y;
	int d;
};
int N, M;
int arr[1002][1002];
int isVisited[2][1002][1002];
queue<Node> que;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}

	isVisited[0][1][1] = 1;
	que.push({ 1,1,0 });

	while (!que.empty()) {
		
		int x = que.front().x;
		int y = que.front().y;
		int d = que.front().d;
		que.pop();
		
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx > 0 && nx <= N && ny > 0 && ny <= M && arr[nx][ny] == 0 && isVisited[d][nx][ny] == 0) {
				que.push({ nx,ny,d });
				isVisited[d][nx][ny] = isVisited[d][x][y] + 1;
			}
			if (nx > 0 && nx <= N && ny > 0 && ny <= M && arr[nx][ny] == 1 ) {
				if (d == 0) {
					que.push({ nx,ny,1 });
					isVisited[1][nx][ny] = isVisited[d][x][y] + 1;
				}
			}

		}
	}

	if (isVisited[1][N][M] != 0 && isVisited[0][N][M] != 0) {
		cout << min(isVisited[1][N][M], isVisited[0][N][M]);
	}
	else if (isVisited[1][N][M] == 0 && isVisited[0][N][M] == 0) {
		cout << -1;
	}
	else if (isVisited[1][N][M] == 0) {
		cout << isVisited[0][N][M];
	}
	else if(isVisited[0][N][M]==0){
		cout << isVisited[1][N][M];
	}	
	
}