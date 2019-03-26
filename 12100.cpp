#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace  std;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
//우 좌 하 상

int N;
int arr[22][22];
int set[6];
int ans = -1;
int isVisited[22][22];
void go(int sz, int n, int k) {
	if (k == 0) {

		int cpy[22][22];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cpy[i][j] = arr[i][j];
			}
		}

		
		//방향 모두 선택
		for (int s = 0; s < sz; s++) {
			
			for (int i = 0; i < N; i++) {
				memset(isVisited[i], 0, sizeof(int)*N);
			}

			if (set[s] == 0) {//오른쪽
				for (int i = 0; i < N; i++) {
					for (int j = N - 1; j >= 0; j--) {
						if (cpy[i][j] != 0) {
							int nx = i;
							int ny = j;
							while (true) {								
								if (nx + dx[set[s]] >= 0 && nx + dx[set[s]] < N &&  ny + dy[set[s]] >= 0 && ny + dy[set[s]] < N && cpy[nx + dx[set[s]]][ny + dy[set[s]]] ==0) {
									nx = nx + dx[set[s]];
									ny = ny + dy[set[s]];
								}
								else if (nx + dx[set[s]] >= 0 && nx + dx[set[s]] < N && ny + dy[set[s]] >= 0 && ny + dy[set[s]] < N && cpy[nx + dx[set[s]]][ny + dy[set[s]]] >0)
								{
									if (isVisited[nx+dx[set[s]]][ny + dy[set[s]]] == true) {
										// 이미 합쳐져 있는 애라면
										cpy[nx][ny] = cpy[i][j];
										cpy[i][j] = 0;
										break;
									}
									else {
										if (cpy[i][j] == cpy[nx + dx[set[s]]][ny + dy[set[s]]]) {
											//합치는게 가능하다면
											nx = nx + dx[set[s]];
											ny = ny + dy[set[s]];
											cpy[i][j] = 0;
											cpy[nx][ny] *= 2;
											isVisited[nx][ny] = true;
											break;
										}
										else {
											cpy[nx][ny] = cpy[i][j];
											if (nx != i || ny != j) {
												cpy[i][j] = 0;
											}
											break;
										}
									}
								}
								else {								
									cpy[nx][ny] = cpy[i][j];
									if (nx != i || ny != j) {
										cpy[i][j] = 0;
									}
									
									break;
								}
							}
						}
					}
				}
			}
			else if (set[s] == 1) {//왼쪽
				for (int i = 0; i < N; i++) {
					for (int j = 0; j <N; j++) {
						if (cpy[i][j] != 0) {
							int nx = i;
							int ny = j;
							while (true) {
								if (nx + dx[set[s]] >= 0 && nx + dx[set[s]] < N &&  ny + dy[set[s]] >= 0 && ny + dy[set[s]] < N && cpy[nx + dx[set[s]]][ny + dy[set[s]]] == 0) {
									nx = nx + dx[set[s]];
									ny = ny + dy[set[s]];
								}
								else if (nx + dx[set[s]] >= 0 && nx + dx[set[s]] < N && ny + dy[set[s]] >= 0 && ny + dy[set[s]] < N && cpy[nx + dx[set[s]]][ny + dy[set[s]]] >0)
								{
									if (isVisited[nx + dx[set[s]]][ny + dy[set[s]]] == true) {
										// 이미 합쳐져 있는 애라면
										cpy[nx][ny] = cpy[i][j];
										cpy[i][j] = 0;
										break;
									}
									else {
										if (cpy[i][j] == cpy[nx + dx[set[s]]][ny + dy[set[s]]]) {
											//합치는게 가능하다면
											nx = nx + dx[set[s]];
											ny = ny + dy[set[s]];
											cpy[i][j] = 0;
											cpy[nx][ny] *= 2;
											isVisited[nx][ny] = true;
											break;
										}
										else {
											cpy[nx][ny] = cpy[i][j];
											if (nx != i || ny != j) {
												cpy[i][j] = 0;
											}
											break;
										}
									}
								}
								else {
									cpy[nx][ny] = cpy[i][j];
									if (nx != i || ny != j) {
										cpy[i][j] = 0;
									}
									break;
								}
							}
						}
					}
				}
			}
			else if (set[s] == 2) {//아래
				for (int j = 0; j <N; j++) {
					for (int i = N-1; i >=0; i--) {
						if (cpy[i][j] != 0) {
							int nx = i;
							int ny = j;
							while (true) {
								if (nx + dx[set[s]] >= 0 && nx + dx[set[s]] < N &&  ny + dy[set[s]] >= 0 && ny + dy[set[s]] < N && cpy[nx + dx[set[s]]][ny + dy[set[s]]] == 0) {
									nx = nx + dx[set[s]];
									ny = ny + dy[set[s]];
								}
								else if (nx + dx[set[s]] >= 0 && nx + dx[set[s]] < N && ny + dy[set[s]] >= 0 && ny + dy[set[s]] < N && cpy[nx + dx[set[s]]][ny + dy[set[s]]] >0)
								{
									if (isVisited[nx + dx[set[s]]][ny + dy[set[s]]] == true) {
										// 이미 합쳐져 있는 애라면
										cpy[nx][ny] = cpy[i][j];
										cpy[i][j] = 0;
										break;
									}
									else {
										if (cpy[i][j] == cpy[nx + dx[set[s]]][ny + dy[set[s]]]) {
											//합치는게 가능하다면
											nx = nx + dx[set[s]];
											ny = ny + dy[set[s]];
											cpy[i][j] = 0;
											cpy[nx][ny] *= 2;
											isVisited[nx][ny] = true;
											break;
										}
										else {
											cpy[nx][ny] = cpy[i][j];
											if (nx != i || ny != j) {
												cpy[i][j] = 0;
											}
											break;
										}
									}
								}
								else {
									cpy[nx][ny] = cpy[i][j];
									if (nx != i || ny != j) {
										cpy[i][j] = 0;
									}
									break;
								}
							}
						}
					}
				}
			}
			else if (set[s] == 3) {//위로
				for (int j = 0;j < N; j++) {
					for (int i = 0; i <N; i++) {
						if (cpy[i][j] != 0) {
							int nx = i;
							int ny = j;
							while (true) {
								if (nx + dx[set[s]] >= 0 && nx + dx[set[s]] < N &&  ny + dy[set[s]] >= 0 && ny + dy[set[s]] < N && cpy[nx + dx[set[s]]][ny + dy[set[s]]] == 0) {
									nx = nx + dx[set[s]];
									ny = ny + dy[set[s]];
								}
								else if (nx + dx[set[s]] >= 0 && nx + dx[set[s]] < N && ny + dy[set[s]] >= 0 && ny + dy[set[s]] < N && cpy[nx + dx[set[s]]][ny + dy[set[s]]] >0)
								{
									if (isVisited[nx + dx[set[s]]][ny + dy[set[s]]] == true) {
										// 이미 합쳐져 있는 애라면
										cpy[nx][ny] = cpy[i][j];
										cpy[i][j] = 0;
										break;
									}
									else {
										if (cpy[i][j] == cpy[nx + dx[set[s]]][ny + dy[set[s]]]) {
											//합치는게 가능하다면
											nx = nx + dx[set[s]];
											ny = ny + dy[set[s]];
											cpy[i][j] = 0;
											cpy[nx][ny] *= 2;
											isVisited[nx][ny] = true;
											break;
										}
										else {
											cpy[nx][ny] = cpy[i][j];
											if (nx != i || ny != j) {
												cpy[i][j] = 0;
											}
											break;
										}
									}
								}
								else {
									cpy[nx][ny] = cpy[i][j];
									if (nx != i || ny != j) {
										cpy[i][j] = 0;
									}
									break;
								}
							}
						}
					}
				}
			}
			/*for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					cout << cpy[i][j] << ' ';
				}
				cout << endl;
			}
			cout << endl;*/
		}
		
		
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				ans = max(cpy[i][j], ans);
			}
		}
		return;
	}
	

	for (int i = 0; i < n; i++) {
		set[sz] = i;
		go(sz + 1, n, k - 1);
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	go(0, 4, 5);
	cout << ans;
}