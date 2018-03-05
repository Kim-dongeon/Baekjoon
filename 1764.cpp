#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	int cnt = 0;
	set<string> s;
	set<string> result;

	while (a--)
	{
		string st;
		cin >> st;
		s.insert(st);
	}


	while (b--)
	{
		string st2;
		cin >> st2;
		if (s.count(st2))
		{			
			pair<set<string>::iterator, bool> temp;
			temp = result.insert(st2);
			if (temp.second == 1)
			{
				cnt++;
			}
		}
	}
	printf("%d\n", cnt);
	
	for (set<string>::iterator it = result.begin(); it != result.end(); ++it)
	{
		cout << *it << '\n';
	}
}