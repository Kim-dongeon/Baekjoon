#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2)
{
	if (p1.second < p2.second)
	{
		return true;
	}
	else if (p1.second == p2.second)
	{
		return p1.first < p2.first;
	}
	else
	{
		return false;
	}
}
int main()
{
	vector<pair<int, int>> v;
	int N;
	cin >> N;
	while (N--)
	{
		int i = 0, j = 0;
		cin >> i >> j;
		v.push_back(make_pair(i, j));
	}
	sort(v.begin(), v.end(),cmp);

	for (auto it = v.begin(); it != v.end(); it++)
	{
		cout << it->first << ' ' << it->second << '\n';
	}
}