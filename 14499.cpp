#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int N, M;
int arr[22][22];

int dx[] = { 0,0,0,-1,1 };
int dy[] = { 0,1,-1,0,0 };		
int dice[] = { 0,0,0,0,0,0 };
//À§ ¾Õ ¾Æ·¡ µÚ ÁÂ ¿ì

int main() {
	int x, y, K;
	cin >> N >> M >> x >> y >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 0; i < K; i++) {
		//µ¿¼­³²ºÏ 1243
		int cmd = 0;
		scanf("%d", &cmd);
		int nx = x + dx[cmd];
		int ny = y + dy[cmd];
		if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
			x = nx;
			y = ny;

			if (cmd == 1) {//µ¿
				int tmp = dice[0];

				dice[0] = dice[4];
				dice[4] = dice[2];
				dice[2] = dice[5];
				dice[5] = tmp;
			}
			else if (cmd == 2) {//¼­
				int tmp = dice[0];

				dice[0] = dice[5];
				dice[5] = dice[2];
				dice[2] = dice[4];
				dice[4] = tmp;
			}
			else if (cmd == 3) {//ºÏ
				int tmp = dice[0];

				dice[0] = dice[1];
				dice[1] = dice[2];
				dice[2] = dice[3];
				dice[3] = tmp;
			}
			else if (cmd == 4) {//³²
				int tmp = dice[0];

				dice[0] = dice[3];
				dice[3] = dice[2];
				dice[2] = dice[1];
				dice[1] = tmp;				
			}

			if (arr[x][y] == 0) {
				arr[x][y] = dice[2];
			}
			else {
				dice[2] = arr[x][y];
				arr[x][y] = 0;
			}
			printf("%d\n", dice[0]);
		}
	}
}