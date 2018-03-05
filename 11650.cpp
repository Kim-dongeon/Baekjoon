#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	vector<pair<int,int>> v;
	int N;
	cin >> N;
	while (N--)
	{
		int i = 0, j = 0;
		cin >> i >> j;
		v.push_back(make_pair(i,j));
	}
	sort(v.begin(), v.end());
	
	for (auto it = v.begin(); it != v.end(); it++)
	{
		cout << it->first << ' ' << it->second << '\n';
	}
}