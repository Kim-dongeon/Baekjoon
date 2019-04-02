#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<int> v[102];
int isVisited[102];
int main() {
	scanf("%d", &N);
	int sx, ex;

	scanf("%d %d", &sx, &ex);
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		v[a].push_back(b);
		v[b].push_back(a);
	}

	queue<int> que;

	que.push(sx);
	isVisited[sx] = true;

	while (!que.empty()) {
		int x = que.front();
		que.pop();

		for (int i = 0; i < v[x].size(); i++) {
			int node2 = v[x][i];
			if (!isVisited[node2]) {
				isVisited[node2] = isVisited[x] + 1;
				que.push(node2);
			}
		}
	}

	int ans = isVisited[ex];
	if (ans == 0) {
		cout << -1;
	}
	else {
		cout << ans - 1;
	}
}