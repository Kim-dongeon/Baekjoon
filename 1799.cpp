#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
int arr[12][12];
int isVisited[12][12];
int ans = 0;
int tmp_cnt = 0;
bool promising(int row, int col) {
	if (arr[row][col] != 1) {
		return false;
	}

	for (int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--) {
		if (isVisited[i][j]) {
			return false;
		}
	}
	for (int i = row - 1, j = col + 1; i >=0 && j < N; i--, j++) {
		if (isVisited[i][j]) {
			return false;
		}
	}

	return true;
}
void go(int row,int col, bool color) {
	if (row == N) {		
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (isVisited[i][j]) {					
					cnt++;
				}
			}
		}

		tmp_cnt = max(tmp_cnt, cnt);
		return;
	}
	//color Â¦¼ö = false, È¦¼ö = true

	if (color == false) {
		//row Â¦¼ö
		if (promising(row, col)) {
			isVisited[row][col] = true;
			if (col + 2 >= N) {
				go(row + 1, 1, !color);
			}
			else {
				go(row, col + 2, color);
			}
			isVisited[row][col] = false;
			if (col + 2 >= N) {
				go(row + 1, 1, !color);
			}
			else {
				go(row, col + 2, color);
			}			
		}
		else {
			if (col + 2 >= N) {
				go(row + 1, 1, !color);
			}
			else {
				go(row, col + 2, color);
			}
		}
	}
	else {
		//row È¦¼ö
		if (promising(row, col)) {
			isVisited[row][col] = true;
			if (col + 2 >= N) {
				go(row + 1, 0, !color);
			}
			else {
				go(row, col + 2, color);
			}
			isVisited[row][col] = false;
			if (col + 2 >= N) {
				go(row + 1, 0, !color);
			}
			else {
				go(row, col + 2, color);
			}
		}
		else {
			if (col + 2 >= N) {
				go(row + 1, 0, !color);
			}
			else {
				go(row, col + 2, color);
			}
		}
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	go(0, 0, false);
	ans += tmp_cnt;
	tmp_cnt = 0;
	for (int i = 0; i < N; i++) {
		memset(isVisited[i], 0, sizeof(int)*N);
	}
	
	go(0, 1, true);
	ans += tmp_cnt;

	cout << ans;
}