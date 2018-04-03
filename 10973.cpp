#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	if (prev_permutation(v.begin(), v.end()))
	{
		for (int x : v)
		{
			cout << x << ' ';
		}
	}
	else
	{
		printf("-1");
	}
}