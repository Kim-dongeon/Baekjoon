#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int cnt = 0;
	for (int i = 0; i < 5; i++)
	{
		int t;
		cin >> t;
		if (N == t)
		{
			cnt++;
		}
	}
	cout << cnt;
}