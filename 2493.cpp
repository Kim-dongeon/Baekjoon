#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>
using namespace std;

struct tower {
	int idx;
	int height;
};
stack<tower> stk;
vector<int> v;
int main() {
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		int now_height;
		scanf("%d", &now_height);

		if (stk.empty()) {
			v.push_back(0);
		}
		else {
			while (!stk.empty()) {
				if (stk.top().height > now_height) {
					v.push_back(stk.top().idx);
					break;
				}
				else {
					stk.pop();
					if (stk.empty()) v.push_back(0);
				}
			}			
		}

		stk.push(tower{ i,now_height });
	}

	for (int &x : v) {
		printf("%d ", x);
	}
}