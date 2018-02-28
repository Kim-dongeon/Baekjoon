#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;

	vector<int> v;
	cin >> n;

	while (n--)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}
	
	int a;
	cin >> a;

	int cnt = 0;
	for (int b : v)
	{
		if (b == a)
		{
			cnt++;
		}
	}
	cout << cnt;


}