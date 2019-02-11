#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	gcd(b, a%b);
}
int main() {

	int N;
	int arr[100002] = { 0, };
	cin >> N;
	for (int i = 0; i<N; i++) {
		scanf("%d", &arr[i]);
	}
	int maxGcd = arr[1] - arr[0];

	for (int i = 3; i<N; i++) {
		maxGcd = gcd(maxGcd, arr[i] - arr[i - 1]);
	}

	int cnt = 0;
	int a1 = arr[0];
	for (int i = 1; i<N;) {
		if (arr[i] != a1 + maxGcd) {
			cnt++;
			a1 = a1 + maxGcd;

		}
		else {
			a1 = arr[i];
			i++;
		}
	}
	printf("%d", cnt);
	return 0;
}