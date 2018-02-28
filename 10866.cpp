#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main()
{
	deque<int> d;
	int N;

	cin >> N;

	while (N--)
	{
		string s;
		cin >> s;
		if (s.compare("push_back")==0)
		{			
			int n;
			cin >> n;
			d.push_back(n);
		}
		else if (s.compare("push_front")==0)
		{
			int n;
			cin >> n;
			d.push_front(n);
		}
		else if (s.compare("front")==0)
		{
			if (d.empty())
			{
				cout << "-1\n";
			}
			else {
				cout << d.front() << '\n';
			}
		}
		else if (s.compare("back")==0)
		{
			if (d.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << d.back() << '\n';
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
		else if (s.compare("pop_front")==0)
		{
			if (d.empty())
			{
				cout << "-1\n";
			}
			else
			{
				int temp = d.front();
				d.pop_front();
				cout << temp << '\n';
			}
		}
		else if (s.compare("pop_back")==0)
		{
			if (d.empty())
			{
				cout << "-1\n";
			}
			else
			{
				int temp = d.back();
				d.pop_back();
				cout << temp << '\n';
			}
		}
		
	}

}