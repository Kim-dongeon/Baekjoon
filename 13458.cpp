#include <iostream>
#include <cstdio>

using namespace std;

int arr[1000011];
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	int B, C;
	cin >> B >> C;

	long long cnt = 0;
	for (int i = 0; i < N; i++) {
		cnt++;
		if (arr[i] - B > 0) {
			arr[i] -= B;
			cnt += arr[i] / C;
			if (arr[i] % C > 0) {
				cnt++;
			}			
		}
	}
	cout << cnt;
}