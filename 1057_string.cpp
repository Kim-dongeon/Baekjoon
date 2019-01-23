#include <cstdio>
#include <iostream>
#include <string>
using namespace std;


int main() {
	int N, J, H;

	scanf("%d %d %d", &N, &J, &H);
	string str = "";
	for (int i = 0; i < N; i++) {
		if (i == (J - 1) || i == (H - 1)) {
			str += "1";
		}
		else {
			str += "0";
		}
	}

	int round = 1;
	while (true) {
		for (int i = 0; (i + 1) < str.size(); i++) {
			str[i] = ((str[i] - '0') + (str[i + 1] - '0')) + '0';
			if (str[i] == '2') {
				printf("%d\n", round);
				return 0;
			}
			str.erase(str.begin() + i + 1);
		}
		round++;
	}

}