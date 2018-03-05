#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<string> v;
	while (N--)
	{
		string temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end(), [](string u, string v) {
		if (u.size() < v.size())
		{
			return true;
		}
		else if (u.size() == v.size())
		{
			return u < v;
		}
		else
		{
			return false;
		}
	}	
	);
	v.erase(unique(v.begin(), v.end()),v.end());
	for (string s : v)
	{
		cout << s << '\n';
	}

}