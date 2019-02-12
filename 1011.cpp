#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		long long x;
		long long y;
		cin >> x >> y;

		long long a = y - x;

		long long s = sqrt(a);
		long long cnt = 2 * s - 1;

		if (a>(s*s)) {
			if (a - (s*s) > s) {
				cnt += 2;
			}
			else {
				cnt++;
			}

		}
		cout << cnt;

	}
	


	return 0;
}