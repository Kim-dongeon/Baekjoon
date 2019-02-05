#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	//¸¶¸§¸ð
	for (int i = 0; i < n; i++) {
		for (int j = n - 1 - i; j > 0; j--) {
			cout << ' ';
		}
		for (int j = 0; j < 2 * i + 1; j++) {
			cout << '*';
		}
		cout << endl;
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j <= i; j++) {
			cout << ' ';
		}
		for (int j = (n - 1 - i) * 2 - 1; j > 0; j--) {
			cout << '*';
		}
		cout << endl;
	}
}