#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <tuple>

using namespace std;

bool cmp(tuple<string,int, int,int> p1, tuple<string,int, int,int> p2)
{
	if (get<1>(p1) == get<1>(p2))
	{
		if (get<2>(p1) == get<2>(p2))
		{
			if (get<3>(p1) == get<3>(p2))
			{
				return get<0>(p1) < get<0>(p2);
			}
			else
			{
				return (get<3>(p1) > get<3>(p2));
			}
		}
		else
		{
			return get<2>(p1) < get<2>(p2);
		}
	}
	else
	{
		return get<1>(p1) > get<1>(p2);
	}
}
int main()
{
	vector<tuple<string,int, int,int>> v;
	int N;
	cin >> N;
	while (N--)
	{
		int i = 0, j = 0 , k=0;
		string s;
		cin >> s >> i >> j >> k;	
		v.push_back(make_tuple(s,i, j,k));
	}
	sort(v.begin(), v.end(), cmp);

	for (auto it = v.begin(); it != v.end(); it++)
	{
		cout << get<0>(*it)<<'\n';
	}
}