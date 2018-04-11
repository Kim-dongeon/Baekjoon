#include <iostream>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	printf("%d\n", (N - 1) + (M - 1)*N);
}