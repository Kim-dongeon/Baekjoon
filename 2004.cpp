#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int cal(int num, int divide) {
	int sum = 0;
	for (int i = divide; i <= num; i*=divide) {
		sum += num / i;
	}

	return sum;
}
int main() {
	int n, m;

	cin >> n >> m;

	cout << min((cal(n, 2) - cal(m, 2) - cal(n - m, 2)), (cal(n, 5) - cal(m, 5) - cal(n - m, 5)));

	return 0;
}