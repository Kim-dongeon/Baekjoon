#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int main() {

	int N;
	cin >> N;
	int promising[1001] = { 0, };
	for (int a = 0; a<N; a++) {
		string s;
		cin >> s;
		int st, b;
		cin >> st >> b;

		if (st == 3 && b == 0) {
			cout << "1";
			return 0;
		}
		else if (st == 2 && b == 0) {
			for (int j = 0; j<3; j++) {
				string num = s;
				for (int k = 1; k <= 9; k++) {
					if (k != s[0] - '0' && k != s[1] - '0' && k != s[2] - '0') {
						num[j] = k + '0';
						promising[stoi(num)]++;
					}
				}
			}
		}
		else if (st == 1 && b == 2) {
			for (int i = 0; i < 3; i++) {
				for (int j = i + 1; j < 3; j++) {
					string num = s;
					char tmp = num[j];
					num[j] = num[i];
					num[i] = tmp;
					promising[stoi(num)]++;
				}
			}
		}
		else if (st == 1 && b == 1) {
			for (int i = 0; i < 3; i++) {
				for (int j = i + 1; j < 3; j++) {
					string num = s;
					char tmp = num[j];
					num[j] = num[i];
					num[i] = tmp;
					string num2 = num;
					for (int k = 1; k <= 9; k++) {
						if (k != s[0] - '0' && k != s[1] - '0' && k != s[2] - '0') {
							num[j] = k + '0';
							num2[i] = k + '0';
							promising[stoi(num)]++;
							promising[stoi(num2)]++;

						}
					}

				}
			}
		}
		else if (st == 1 && b == 0) {
			for (int i = 0; i < 3; i++) {
				for (int j = 1; j <= 9; j++) {
					string num = s;
					int idx = (i + 1) % 3;
					if (j != s[0] - '0' && j != s[1] - '0' && j != s[2] - '0') {
						num[idx] = j + '0';
						int jdx = (idx + 1) % 3;
						for (int k = 1; k <= 9; k++) {
							if (k != s[0] - '0' && k != s[1] - '0' && k != s[2] - '0' && k != num[idx] - '0') {
								num[jdx] = k + '0';
								promising[stoi(num)]++;
							}
						}
					}
				}
			}
		}
		else if (st == 0 && b == 3) {
			for (int j = 0; j < 2; j++) {
				char tmp = s[0];
				for (int i = 0; i < 3; i++) {
					s[i] = s[i + 1];
				}
				s[2] = tmp;
				promising[stoi(s)]++;
			}

		}
		else if (st == 0 && b == 2) {
			for (int i = 0; i < 3; i++) {
				int j = (i + 1) % 3;
				int k = (i + 2) % 3;
				for (int x = 1; x <= 9; x++) {
					if (x != s[0] - '0' && x != s[1] - '0' && x != s[2] - '0') {
						string num = s;
						char temp = num[j];
						num[j] = num[k];
						num[k] = temp;
						num[i] = x + '0';
						promising[stoi(num)]++;

					}
				}
			}

			string num = s;
			for (int j = 0; j < 2; j++) {

				char tmp = num[0];
				for (int i = 0; i < 3; i++) {
					num[i] = num[i + 1];
				}
				num[2] = tmp;

				string num1 = num;
				string num2 = num;
				string num3 = num;

				for (int k = 1; k <= 9; k++) {
					if (k != s[0] - '0' && k != s[1] - '0' && k != s[2] - '0') {
						num1[1 - j] = k + '0';
						num2[(3 - j) % 3] = k + '0';
						num3[2 - j] = k + '0';

						promising[stoi(num1)]++;
						promising[stoi(num2)]++;
						promising[stoi(num3)]++;
						//cout << num1 << " " << num2 << " " << num3 << endl;

					}
				}
			}

		}
		else if (st == 0 && b == 1) {
			for (int i = 0; i < 3; i++) {
				int jdx = (i + 1) % 3;
				int kdx = (i + 2) % 3;
				string num = s;
				char temp = num[i];
				num[i] = num[jdx];
				num[jdx] = temp;

				for (int j = 1; j <= 9; j++) {
					string num1 = num;
					string num2 = num;
					if (j != s[0] - '0' && j != s[1] - '0' && j != s[2] - '0') {
						num1[jdx] = j + '0';
						num2[i] = j + '0';
						for (int k = 1; k <= 9; k++) {
							if (k != s[0] - '0' && k != s[1] - '0' && k != s[2] - '0' && k != j) {
								num1[kdx] = k + '0';
								num2[kdx] = k + '0';
								promising[stoi(num1)]++;
								promising[stoi(num2)]++;
							}
						}
					}
				}
			}
		}
		else if (st == 0 && b == 0) {
			for (int i = 100; i < 1000; i++) {
				string num = to_string(i);
				bool flag = false;
				if (num[0] != num[1] && num[1] != num[2] && num[0] != num[2] && i % 10 != 0 && num[1] != '0') {
					for (int j = 0; j < 3; j++) {
						if (num[j] == s[0] || num[j] == s[1] || num[j] == s[2]) {
							flag = true;
							break;
						}
					}
					if (!flag) {
						promising[i]++;
					}
				}

			}
		}
		/*for (int q = 100; q < 1000; q++) {
		if (a + 1 == promising[q]) {
		cout << q << endl;
		}
		}
		cout << endl;*/
	}

	int cnt = 0;
	for (int i = 100; i < 1000; i++) {
		if (N == promising[i]) {
			cnt++;
		}
	}

	cout << cnt;
	return 0;
}