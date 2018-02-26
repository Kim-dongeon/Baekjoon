#include <iostream>
#include <list>
using namespace std;

int main()
{
	list<pair<int,int>> l;
	int N, x = 0;
	

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> x;
		l.push_back({ i,x });
	}
	auto it = l.begin();
	
	while (N--)
	{                  
		cout << it->first << ' ';
		int move = (it->second);
		if (move > 0)
		{
			auto temp = it;
			++temp;
			if (temp == l.end())
			{
				temp = l.begin();
			}
			l.erase(it);
			it = temp;
			if (l.empty())break;
			while (--move)
			{
				++it;
				if (it == l.end())
				{
					it = l.begin();
				}
			}
		}
		else if(move<0)
		{	
			move = -move;
			auto temp = it;
			if (temp == l.begin())
			{
				temp = l.end();
			}
			--temp;
			l.erase(it);
			it = temp;
			if (l.empty())break;
			while (--move)
			{				
				if (it == l.begin())
				{
					it = l.end();
				}
				--it;
			}
		}
	}

	return 0;
}