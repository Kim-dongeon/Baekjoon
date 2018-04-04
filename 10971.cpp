#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main()
{
	int N;
	cin >> N;
	int w[12][12] = { 0, };
	vector<int> v;
	for (int i = 0; i < N; i++)
	{
		v.push_back(i);
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &w[i][j]);
		}
	}
	
	int result = 100000000;
	do {
		bool flag = true;
		int sum = 0;
		if (v[0] == 1) break;

		for (int i = 0; i < N-1; i++)
		{
			if (w[v[i]][v[i + 1]] == 0)
			{
				flag = false;
				break;
			}
			sum += w[v[i]][v[i+1]];
		}
		if (flag)
		{
			if (w[v[N - 1]][v[0]] == 0) continue;
			sum += w[v[N - 1]][v[0]];
			result = min(sum, result);
		}
	} while (next_permutation(v.begin(),v.end()));
	printf("%d", result);
}