#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int arr[1000];
int N;
int isVisited[1000];
int answer_check[102];
vector<int> ans;

vector<int> same;
void go(int idx) {
	
	if (isVisited[arr[idx]] <= 0 && arr[idx] != idx) {
		isVisited[arr[idx]] = 1;
		go(arr[idx]);
	}
	else {
		bool flag = true;
		for (int i = 0; i <= N; i++) {
			if (isVisited[i] == -1) {
				flag = false;
				break;
			}
		}

		if (flag) {
			for (int i = 0; i <= N; i++) {
				if (isVisited[i]) {
					if (answer_check[i] == 0) {
						ans.push_back(arr[i]);
						answer_check[i] = 1;
					}					
				}
			}			
		}
		else {
			return;
		}
	}
	
	

}
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] == i) {
			same.push_back(arr[i]);
		}
	}

	for (int i = 1; i <= N; i++) {
		isVisited[i] = -1;
		go(i);		
		memset(isVisited, 0, sizeof(int) * 1000);
	}

	for (int i = 0; i < same.size(); i++) {
		ans.push_back(same[i]);
	}

	sort(ans.begin(), ans.end());

	int ans_size = ans.size();
	cout << ans_size << endl;
	for (int i = 0; i < ans_size; i++) {
		cout << ans[i] << endl;
	}

}
/*
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int arr[1000];
int N;
int isVisited[1000];
int answer_check[102];
vector<int> ans;
bool go(int idx,int sx) {

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
cin >> N;
for (int i = 1; i <= N; i++) {
scanf("%d", &arr[i]);
}

for (int i = 1; i <= N; i++) {
if (!isVisited[i]) {
isVisited[i] = true;
if (!go(i, i)) {
isVisited[i] = false;
}
}

}

for (int i = 1; i <= N; i++) {
if (isVisited[i]) {
ans.push_back(i);
}
}

int ans_size = ans.size();
cout << ans_size << endl;
for (int i = 0; i < ans_size; i++) {
cout << ans[i] << endl;
}

}*/