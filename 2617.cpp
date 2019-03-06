#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

int arr[102][102];
bool light_over[102];
bool heavy_over[102];
bool isVisited[102];
int ans;
int N, M;
int cnt;

bool go(int cur) {	
	if (cnt > N/2 || light_over[cur]) {
		return false;
	}
	isVisited[cur] = true;
	for (int i = 1; i <= N; i++) {
		if (arr[cur][i] == 1 && isVisited[i] == false) {
			cnt++;
			if (!go(i)) {
				return false;
			}
		}
	}
	return true;	
}
bool go2(int cur) {
	if (cnt > N / 2 || heavy_over[cur]) {
		return false;
	}
	isVisited[cur] = true;
	for (int i = 1; i <= N; i++) {
		if (arr[i][cur] == 1 && isVisited[i] == false) {
			cnt++;
			if (!go2(i)) {
				return false;
			}
		}
	}
	return true;
}
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);		
		arr[a][b] = 1;				
	}
	//가벼운거 판단
	for (int i = 1; i <= N; i++) {
		cnt = 0;
		memset(isVisited, 0, sizeof(bool)*(N + 1));
		
		if (!go(i)) {
			ans++;			
			light_over[i] = true;
		}		
	}
	
	//무거운거
	for (int i = 1; i <= N; i++) {
		cnt = 0;
		memset(isVisited, 0, sizeof(bool)*(N + 1));
		if (!go2(i)) {
			ans++;			
			heavy_over[i] = true;
		}
	}

	cout << ans;
}