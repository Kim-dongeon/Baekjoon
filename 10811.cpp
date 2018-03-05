#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<int> v;
	
	for (int i = 1; i <= N; i++)
	{
		v.push_back(i);
	}
	
	while (M--)
	{
		int i = 0, j = 0;
		cin >> i >> j;
		reverse(v.begin() + i-1, v.begin() + j);
	}

	for (int x : v)
	{
		cout << x << ' ';
	}
}