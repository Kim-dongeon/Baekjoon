#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<int> v(N);


	while (M--)
	{
		int i = 0, j = 0, k = 0;
		cin >> i >> j >> k;
		fill(v.begin() + i-1, v.begin()+j, k);
	}
	for (int a : v)
	{
		cout << a<<' ';
	}

}
