#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	map<string, pair<long, long>> m = {
		{ "black",make_pair(0,1) } ,{ "brown", make_pair(1, 10) },{ "red", make_pair(2, 100) }
		,{ "orange", make_pair(3, 1000) },{ "yellow", make_pair(4, 10000) },{ "green", make_pair(5, 100000) }
		,{ "blue", make_pair(6, 1000000) },{ "violet", make_pair(7, 10000000) },{ "grey", make_pair(8, 10000000) }
		,{ "white", make_pair(9, 1000000000) }
	};


	map<string, pair<long, long>>::iterator it;
	long long sum = 0;
	for (int i = 0; i < 3; i++)
	{
		string s;
		cin >> s;
		it = m.begin();
		it = m.find(s);
		if (i == 0)
		{
			sum += it->second.first * 10;
		}
		else if (i == 1)
		{
			sum += it->second.first;
		}
		else {
			sum = sum * it->second.second;
		}
	}
	cout << sum;

}