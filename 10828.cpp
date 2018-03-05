#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	int N;
	cin >> N;
	stack<int> d;
	while (N--)
	{
		string s;
		cin >> s;
		if (s=="push")
		{
			int n;
			cin >> n;
			d.push(n);
		}
		else if (s.compare("top") == 0)
		{
			if (d.empty())
			{
				cout << "-1\n";
			}
			else {
				cout << d.top() << '\n';
			}
		}	
		else if (s.compare("size") == 0)
		{
			cout << d.size() << '\n';
		}
		else if (s.compare("empty") == 0)
		{
			if (d.empty())
			{
				cout << "1\n";
			}
			else
			{
				cout << "0\n";
			}
		}
		else if (s.compare("pop") == 0)
		{
			if (d.empty())
			{
				cout << "-1\n";
			}
			else
			{
				int temp = d.top();
				d.pop();
				cout << temp << '\n';
			}
		}
	}	
}