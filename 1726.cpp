#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

//동서남북 1,2,3,4
using namespace std;

struct Node {
	int x;
	int y;
	int d;
	int cnt;

};
int dx[5] = {0, 0,0,1,-1 };
int dy[5] = {0, 1,-1,0,0 };
int dE[] = { 1,4,3,2 };
int dW[] = { 2,4,3,1 };
int dS[] = { 3,1,2,4 };
int dN[] = { 4,1,2,3 };

int arr[103][103];
int isVisited[5][103][103];
int answer = 987654321;

queue<Node> que;

int main() {
	int N, M;
	
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	int s_x, s_y, e_x, e_y, s_d, e_d;
	scanf("%d %d %d %d %d %d", &s_x, &s_y, &s_d, &e_x, &e_y,&e_d);

	que.push({ s_x,s_y,s_d,0 });
	isVisited[s_d][s_x][s_y] = true;

	while (!que.empty()) {
		int x = que.front().x;
		int y = que.front().y;
		int d = que.front().d;
		int cnt = que.front().cnt;
		que.pop();
		if (x == e_x && y == e_y && d == e_d) {
			cout << cnt<<endl;
			break;
		}
		//직진
		for (int i = 1; i <= 3; i++) {
			int nx = x + dx[d] * i;
			int ny = y + dy[d] * i;

			if (nx > 0 && nx <= N && ny > 0 && ny <= M && arr[nx][ny] == 0 ) {
				if (isVisited[d][nx][ny] == false) {
					que.push({ nx,ny,d,cnt + 1 });
					isVisited[d][nx][ny] = true;
				}
			}
			else {
				break;
			}
		}
		
		//회전
		int nd = 0;
		for (int i = 1; i <= 3; i++) {
			if (d == 1) {
				nd = dE[i];
			}
			else if (d == 2) {
				nd = dW[i];
			}
			else if (d == 3) {
				nd = dS[i];
			}
			else if (d == 4) {
				nd = dN[i];
			}
			
			if (isVisited[nd][x][y] == false) {
				isVisited[nd][x][y] = true;
				if (i != 3) {
					que.push({ x,y,nd,cnt + 1 });					
				}
				else {
					que.push({ x,y,nd,cnt + 2 });
				}
			}			
		}
	}

	
}