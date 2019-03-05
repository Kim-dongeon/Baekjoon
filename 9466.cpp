#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int arr[100001];
int N;
int isVisited[100001];

bool go(int idx, int sx) {

	if (isVisited[arr[idx]] == 0) {
		isVisited[arr[idx]] = 1;

		if (!go(arr[idx], sx)) {
			isVisited[arr[idx]] = 0;
			return false;
		}
	}
	else {
		if (arr[idx] == sx) {
			return true;
		}
		else {
			return false;
		}
	}
}
int main() {
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		scanf("%d", &N);
		for (int i = 1; i <= N; i++) {
			scanf("%d", &arr[i]);
		}

		for (int i = 1; i <= N; i++) {
			if (isVisited[i]==0) {
				isVisited[i] = 1;
				if (!go(i, i)) {
					isVisited[i] = -1;
				}
			}

		}

		int cnt = 0;
		for (int i = 1; i <= N; i++) {
			if (isVisited[i]!=1) {
				cnt++;
			}
		}	
		printf("%d\n", cnt);

		memset(isVisited, 0, sizeof(int)*(N + 1));
	}
	

	

}