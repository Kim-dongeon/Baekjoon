#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int N;
int arr[102][102];

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int main() {
	int K;
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		arr[x][y] = 1;
	}
	int L;
	cin >> L;
	arr[0][0] = 2;
	int time_cnt = 0;
	queue<pair<int, int>> que;
	int d = 0;
	
	int hx = 0, hy = 0;
	que.push(make_pair(0, 0));
	
	vector<pair<int, char>> v;
	int idx = 0;
	for (int i = 0; i < L; i++) {
		int X;
		char C;
		scanf("%d %c", &X, &C);
		//L왼쪽 D 오른쪽		
		v.push_back(make_pair(X, C));
	}


	while (true) {
		//X초 만큼 앞으로 진행
		int nx = hx + dx[d];
		int ny = hy + dy[d];
		time_cnt++;
		if (nx >= 0 && nx < N&& ny >= 0 && ny < N && arr[nx][ny] != 2) {
			if (arr[nx][ny] == 1) {
				//사과가 있는경우
				hx = nx;
				hy = ny;
			}
			else {
				int rx = que.front().first;
				int ry = que.front().second;
				que.pop();
				arr[rx][ry] = 0;
				hx = nx;
				hy = ny;
			}
			que.push(make_pair(hx, hy));
			arr[hx][hy] = 2;
		}
		else {
			//벽이나 몸통에 
			break;
		}

		if (idx < v.size() &&  time_cnt == v[idx].first) {
			char L = v[idx].second;
			idx++;
			if (d == 0) {
				if (L == 'L') {
					d = 3;
				}
				else {
					d = 2;
				}
			}
			else if (d == 1) {
				if (L == 'L') {
					d = 2;
				}
				else {
					d = 3;
				}
			}
			else if (d == 2) {
				if (L == 'L') {
					d = 0;
				}
				else {
					d = 1;
				}
			}
			else if (d == 3) {
				if (L == 'L') {
					d = 1;
				}
				else {
					d = 0;
				}
			}
		}
	}
		

			
		
		
		/*for (int a = 0; a < N; a++) {
			for (int b = 0; b < N; b++) {
				cout << arr[a][b] << ' ';
			}cout << endl;
		}
		cout << endl;
		*/

	

	cout << time_cnt;
}