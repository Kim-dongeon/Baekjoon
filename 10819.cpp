#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &v[i]);
	}
	sort(v.begin(),v.end());
	int _max = 0;
	do {
		int temp = 0;
		for (int i = 0; i < N-1; i++)
		{
			temp += abs(v[i] - v[i + 1]);
		}
		_max = max(_max, temp);
	} while (next_permutation(v.begin(), v.end()));

	cout << _max;
}