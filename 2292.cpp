#include <stdio.h>
#include <iostream>
using namespace std;
int main() {

	int N;
	scanf("%d", &N);

	int ans = 1;
	int cnt = 1;
	int idx = 1;
	while (true) {
		if (cnt <N) {
			cnt += idx * 6;
			idx++;
		}
		else {
			cout << idx;
			break;
		}
	}
	return 0;
}