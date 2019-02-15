#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;


int main() {
	int N;
	cin >> N;
	long long arr[100002] = { 0, };
	for (int i = 0; i<N; i++) {
		scanf("%ld", &arr[i]);
	}

	sort(arr, arr + N, [](long x, long y) {
		if (x<0 || y<0) {
			return abs(x) < abs(y);
		}
		else {
			return x < y;
		}
	});

	long long min_diff = 10000000001;
	long long a = 0, b = 0;
	for (int i = 0; i<N - 1; i++) {
		long long diff = abs(arr[i] + arr[i + 1]);

		if (min_diff >diff) {
			min_diff = diff;
			a = min(arr[i], arr[i + 1]);
			b = max(arr[i], arr[i + 1]);
		}if (min_diff == diff) {
			if (a > min(arr[i], arr[i + 1]))
			{
				a = min(arr[i], arr[i + 1]);
				b = max(arr[i], arr[i + 1]);
			}
		}
	}

	printf("%ld %ld\n", a, b);
	return 0;
}