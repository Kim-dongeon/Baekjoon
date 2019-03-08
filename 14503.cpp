#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int N, M;

int dx[] = { -1,0,1,0 };		//�ϵ�����
int dy[] = { 0,1,0,-1 };

//d �� �� �� �� 0 1 2 3

int row, col, d;
int arr[53][53];

int clean; //û���� �ٴ� ����
int cur_d; //���� �ٶ󺸴� ����
bool isVisited[53][53]; //û�Ұ� �Ǿ��ִ°�?

int main() {
	scanf("%d %d", &N, &M);
	scanf("%d %d %d", &row, &col, &d);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	while (true) {		

		//���� �ڸ� û��
		if (isVisited[row][col] == false) {
			isVisited[row][col] = 1;
			clean++;
		}
		
		//���� Ž��
		//4���� Ž��
		int prev_x = row;
		int prev_y = col;
		for (int k = 0; k < 4; k++) {
			int nx = row + dx[(d + (3-k)) % 4];
			int ny = col + dy[(d + (3-k)) % 4];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M && arr[nx][ny] == 0 && isVisited[nx][ny] == 0) {
				//û�ҵ��� �ʾҴ�
				row = nx;
				col = ny;
				d = (d + (3-k)) % 4;
				break;
			}			
		}
		
		if (prev_x == row && prev_y == col) {
			int nx = dx[(d + 2) % 4] + row;
			int ny = dy[(d + 2) % 4] + col;

			if (arr[nx][ny] == 1) {
				break;
			}
			else {
				row = nx;
				col = ny;
			}
		}
	}
	cout << clean;
}