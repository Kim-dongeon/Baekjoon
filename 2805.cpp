#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

long long arr[1000002];

int N;
long long M;
bool check(long long num) {
	long long sum = 0;
	for (int i = 0; i<N; i++) {
		long long temp = arr[i] - num;

		if (temp>0) {
			sum += temp;
		}

		if (sum >= M) {
			return true;
		}
	}
	return false;
}
int main() {
	long long max_height = -1;
	cin >> N >> M;
	for (int i = 0; i<N; i++) {
		scanf("%ld", &arr[i]);
		max_height = max(max_height, arr[i]);
	}

	long long  left = 0;
	long long right = max_height;
	while (left + 1<right) {
		long long mid = (left + right) / 2;

		if (check(mid)) {
			left = mid;
		}
		else {
			right = mid;
		}
	}

	cout << left;
	return 0;
}