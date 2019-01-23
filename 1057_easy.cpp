#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector<int> v;
int main() {
	int N, J, H;
	scanf("%d %d %d", &N, &J, &H);

	J--;
	H--;
	int round = 0;

	while (J != H) {
		round++;
		J = J / 2;
		H = H / 2;
	}
	printf("%d", round);
}
