#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M,H;

int arr[12][32];
vector<pair<int, int>> v;
int ans = 987654321;
int set[400];
int num = 1;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
void comb(int sz, int n, int k, int index) {
	if (n < k) {
		return;
	}

	if (k == 0) {
		int n_num = num ;
		//배열 카피
		int cpy[12][32];
		for (int i = 0; i <= H; i++) {
			for (int j = 0; j <= N; j++) {
				cpy[i][j] = arr[i][j];
			}			
		}

		//사다리 놓을수 있는지 검사
		for (int i = 0; i < sz; i++) {
			int x = v[set[i]].first;
			int y = v[set[i]].second;

			if (cpy[x][y] == 0 &&  cpy[x][y + 1] == 0) {
				cpy[x][y] = n_num;
				cpy[x][y + 1] = n_num;
				n_num++;
			}
			else {
				return;
			}
		}

		//가능하다면 정답이 맞는지 확인
		for (int i = 1; i <= N; i++) {
			int sx = 0;
			int sy = i;
			while (true) {
				sx += dx[2];
				sy += dy[2];
				if (sx > H) {
					break;
				}
				if (cpy[sx][sy] == 0) {
					continue;
				}
				else {
					for (int k = 0; k < 2; k++) {
						int nx = sx + dx[k];
						int ny = sy + dy[k];

						if (ny > 0 && ny <= N && cpy[nx][ny] == cpy[sx][sy]) {
							sx = nx;
							sy = ny;
							break;
						}
					}
				}
			}
			if (sy != i) {
				return;
			}
			
		}
		ans = min(ans, sz);
		return;
	}
	else if (n == index) {
		return;
	}

	set[sz] = index;
	comb(sz + 1, n, k - 1, index + 1);
	comb(sz, n, k, index + 1);

}
int main() {
	cin >> N >> M >> H;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = num;
		arr[a][b + 1] = num;
		num++;
	}

	for (int i = 1; i <= H; i++) {
		for (int j = 1; j < N; j++) {
			if (arr[i][j] == 0 &&arr[i][j+1]==0) {
				v.push_back(make_pair(i, j));
			}
		}
	}

	/*for (int i = 0; i <= H; i++) {
		for (int j = 0; j <= N; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
	for (int i= 0; i < v.size(); i++) {
		cout << v[i].first << ' ' << v[i].second << endl;
	}
	cout << "############" << endl;
*/


	for (int i = 0; i <= 3; i++) {
		comb(0, v.size(), i, 0);
		memset(set, 0, sizeof(set));
	}

	if (ans == 987654321) {
		cout << -1;
	}
	else {
		cout << ans;
	}
	
}