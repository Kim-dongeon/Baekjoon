#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	int N, W, H;
	cin >> N >> W >> H;
	vector<int> v(N);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
		if (pow(v[i], 2) > pow(W, 2) + pow(H, 2))
		{
			printf("NE\n");
		}
		else
		{
			printf("DA\n");
		}
	}
}