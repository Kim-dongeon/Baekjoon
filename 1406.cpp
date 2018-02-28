#include <iostream>
#include <list>
#include <string>

using namespace std;

int main()
{
	string s;
	cin >> s;

	list<char> l(s.begin(),s.end());
	list<char>::iterator it = l.end();
	
	int N;
	cin >> N;
	while (N--)
	{
		char x;
		cin >> x;
		
		if (x == 'P')
		{
			char temp;
			cin >> temp;
			l.insert(it,temp);
		}
		else if (x == 'L')
		{
			if (it != l.begin())
			{
				--it;
			}
		}
		else if (x == 'D')
		{
			if (it != l.end())
			{
				++it;
			}
		}
		else if (x == 'B')
		{
			if (it != l.begin())
			{
				--it;
				it = l.erase(it);
			}
		}
	}

	for (auto &x = l.begin(); x != l.end(); ++x)
	{
		cout << *x ;
	}
}