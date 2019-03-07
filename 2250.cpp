#include<iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> vec[10002];
bool isVisited[10002];
int depth[10002];
int col[10002];
int col_cnt=1;
int max_depth = -1;
int root[10002];
int r = -1;
void traversal(int node,int depth_cnt) {
	
	if (node == -1) {
		return;
	}
	
	for (int i = 0; i < vec[node].size();i++) {
		traversal(vec[node][i],depth_cnt+1);
		if (isVisited[node] == false) {
			depth[node] = depth_cnt;
			col[node] = col_cnt++;
			isVisited[node] = true;
			max_depth = max(max_depth, depth_cnt);
		}		
	}
}
int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		vec[a].push_back(b);
		vec[a].push_back(c);
		
		if(a!=-1)		root[a]++;
		if (b != -1)root[b]++;
		if (c != -1)root[c]++;
	}
	
	for (int i = 0; i <= N; i++) {
		if (root[i] == 1) {
			r = i;
			break;
		}
	}
	traversal(r,1);

	int ans = 0;
	int ans_level = 0;
	for (int i = 1; i <= max_depth; i++) {
		int min_col = 987654321;
		int max_col = -1;
		for (int j = 1; j <= N; j++) {
			if (depth[j] == i) {
				min_col = min(min_col, col[j]);
				max_col = max(max_col, col[j]);
			}
		}
		if (ans < max_col - min_col + 1) {
			ans = max_col - min_col + 1;
			ans_level = i;
		}
	}
	cout <<ans_level<<' '<< ans;
	
}