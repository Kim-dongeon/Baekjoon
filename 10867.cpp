#include <iostream>
#include <set>
using namespace std;

int main()
{
	int N,n=0;
	cin >> N;
	set<int> s;
	while (N--)
	{
		cin >> n;
		s.insert(n);
	}

	set<int>::iterator it= s.begin();
	while (it != s.end())
	{
		cout << *it << ' ';
		++it;
	}
}