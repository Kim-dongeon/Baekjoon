#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N;
int arr[12][12];	//양분
vector<int> tree[12][12]; //나무
int A[12][12];		//추가되는 양분
int season[4] = { 0,1,2,3 }; //봄 여름 가을 겨울 0123
int dx[] = { 0,0,1,-1,1,1,-1,-1 };
int dy[] = { 1,-1,0,0,1,-1,1,-1 };
struct node {
	int x;
	int y;
	int d;
};
int main() {
	int M, K;
	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &A[i][j]);
			arr[i][j] = 5;
		}
	}

	for (int i = 0; i < M; i++) {
		int x, y, age;
		scanf("%d %d %d", &x, &y, &age);
		x--;
		y--;

		tree[x][y].push_back(age);
	}
	queue<node> que;
	for (int year = 1; year <= K; year++) {
		for (int s = 0; s < 4; s++) {
			if (s == 0) {
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < N; j++) {
						if (tree[i][j].size() > 0) {
							//나이순대로 정렬
							sort(tree[i][j].begin(), tree[i][j].end());
							for (int a = 0; a < tree[i][j].size(); a++) {
								//한 좌표에 있는 나무
								if (arr[i][j] < tree[i][j][a]) {
									//양분이 나이보다 적은경우
									que.push({ i,j,tree[i][j][a] / 2 });
									tree[i][j].erase(tree[i][j].begin() + a);
									a--;
								}
								else {
									//양분이 있는경우
									arr[i][j] -= tree[i][j][a];
									tree[i][j][a]++;
								}
							}
						}
					}
				}
			}
			else if (s == 1) {
				while (!que.empty()) {
					int x = que.front().x;
					int y = que.front().y;
					int d = que.front().d;
					que.pop();
					arr[x][y] += d;
				}
			}
			else if (s == 2) {
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < N; j++) {
						for (int a = 0; a < tree[i][j].size(); a++) {
							if (tree[i][j][a] % 5 == 0) {
								//5의 배수이다
								for (int k = 0; k < 8; k++) {
									int nx = i + dx[k];
									int ny = j + dy[k];

									if (nx >= 0 && nx < N&&ny >= 0 && ny < N) {
										tree[nx][ny].push_back(1);
									}
								}
							}
						}
					}
				}
			}
			else if (s == 3) {//겨울
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < N; j++) {
						arr[i][j] += A[i][j];
					}
				}
			}
		}

		//year 지난 후
	}

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cnt += tree[i][j].size();
		}
	}
	cout << cnt;
}