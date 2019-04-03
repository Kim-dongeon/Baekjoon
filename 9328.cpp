#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
#include <queue>
#include <string>
using namespace std;
int N, M;
char arr[102][102];
bool key[26];
vector<pair<int, int>> door[26];
vector<pair<int, int>> in;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int ans;
bool isVisited[102][102];
void in_chk() {
	//들어가는 문 검사
	for (int i = 0; i < N; i++) {
		if (i == 0 || i == N - 1) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] == '.') {
					in.push_back(make_pair(i, j));
				}
				else if (arr[i][j] == '$') {
					ans++;
					in.push_back(make_pair(i, j));
					arr[i][j] = '.';
				}
				else if (arr[i][j] >= 'a' && arr[i][j] <= 'z') {
					if (!key[arr[i][j] - 'a']) {
						key[arr[i][j] - 'a'] = true;
						arr[i][j] = '.';
						in.push_back(make_pair(i, j));
					}
					
				}
			}
		}
		else {
			if (arr[i][0] == '.') {
				in.push_back(make_pair(i, 0));
			}
			else if (arr[i][0] == '$') {
				ans++;
				in.push_back(make_pair(i, 0));
				arr[i][0] = '.';
			}
			else if (arr[i][0] >= 'a' && arr[i][0] <= 'z') {
				if (!key[arr[i][0] - 'a']) {
					key[arr[i][0] - 'a'] = true;
					arr[i][0] = '.';
					in.push_back(make_pair(i, 0));
				}
				
			}

			if (arr[i][M - 1] == '.') {
				in.push_back(make_pair(i, M - 1));
			}
			else if (arr[i][M-1] == '$') {
				ans++;
				in.push_back(make_pair(i, M-1));
				arr[i][M-1] = '.';
			}
			else if (arr[i][M-1] >= 'a' && arr[i][M - 1] <= 'z') {
				if (!key[arr[i][M-1] - 'a']) {
					key[arr[i][M-1] - 'a'] = true;
					arr[i][M - 1] = '.';
					in.push_back(make_pair(i, M - 1));
				}
				
			}
		}
	}
}
void door_open() {
	//먼저 가지고있던 열쇠로 문 열기
	for (int i = 0; i < 26; i++) {
		if (key[i] == true) {
			for (int j = 0; j < door[i].size(); j++) {
				if (arr[door[i][j].first][door[i][j].second] != '.') {
					arr[door[i][j].first][door[i][j].second] = '.';
				}				
			}
		}
	}
}
int main() {
	int T;

	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		scanf("%d %d", &N, &M);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf(" %c", &arr[i][j]);
				if (arr[i][j] >= 'A'&&arr[i][j] <= 'Z') {
					door[arr[i][j] - 'A'].push_back(make_pair(i, j));
				}
			}
		}
		string str;
		cin >> str;
		if (str[0] != '0') {
			for (int i = 0; i < str.size(); i++) {
				key[str[i] - 'a'] = true;
			}
		}
		//먼저 가지고있던 열쇠로 문 열기
		
		//들어가는 문 검사
		in_chk();
		door_open();
		in_chk();
		queue<pair<int, int>> que;
		//문 que에 넣기
		for (int i = 0; i < in.size(); i++) {
			que.push(make_pair(in[i].first, in[i].second));
			isVisited[in[i].first][in[i].second] = true;
		}
		
		while (!que.empty()) {
			int x = que.front().first;
			int y = que.front().second;
			
			que.pop();

			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];

				if (nx >= 0 && nx < N && ny >= 0 && ny < M&&isVisited[nx][ny]==false) {
					if (arr[nx][ny] == '.') {
						//일반적으로 이동
						isVisited[nx][ny] = true;
						que.push(make_pair(nx, ny));
					}
					else if (arr[nx][ny] == '$') {
						//서류 획득
						ans++;
						arr[nx][ny] = '.';
						isVisited[nx][ny] = true;
						que.push(make_pair(nx, ny));
					}
					else if (arr[nx][ny] >= 'a' && arr[nx][ny] <= 'z') {
						if (key[arr[nx][ny] - 'a'] == false) {
							//새로운 키를 찾은 경우
							key[arr[nx][ny] - 'a'] = true;
							//문 다시 열고
							door_open();
							//기존의 문 좌표 버리고
							in.clear();
							//새로운 문좌표들 기록
							in_chk();
							
							//bfs 다시돌리기 위해 
							while (!que.empty()) {
								que.pop();
							}
							for (int i = 0; i < in.size(); i++) {
								que.push(make_pair(in[i].first, in[i].second));
							}
							for (int i = 0; i < N; i++) {
								memset(isVisited[i], 0, sizeof(bool)*M);
							}

						}
						else {
							arr[nx][ny] = '.';
							isVisited[nx][ny] = true;
							que.push(make_pair(nx, ny));
						}
					}
					else if (arr[nx][ny] >= 'A' && arr[nx][ny] <= 'Z') {
						if (key[arr[nx][ny] - 'A']) {
							arr[nx][ny] = '.';
							isVisited[nx][ny] = true;
							que.push(make_pair(nx, ny));
						}
					}
				}
			}
		}



		printf("%d\n", ans);
		ans = 0;
		memset(key, 0, sizeof(key));
		for (int i = 0; i < 26; i++) {
			door[i].clear();
		}
		for (int i = 0; i < N; i++) {
			memset(isVisited[i], 0, sizeof(bool)*M);
		}
		in.clear();
	}
}