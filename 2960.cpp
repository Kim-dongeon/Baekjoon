#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
	int n ,k;
	cin >> n >> k;
	
	int answer[1010] = { 0, };
	int cnt = 0;
	for (int i = 2; i <= n; i++)
	{
		if (answer[i] == 0)
		{
			answer[i] = 1;
			cnt++;
		}
		if (cnt == k)
		{
			cout << i;
			return 0;
		}
		for (int j = i * 2; j <= n; j += i)
		{
			if (answer[j] == 0)
			{
				answer[j] = 1;
				cnt++;
			}
			if (cnt == k)
			{
				cout << j;
				return 0;
			}
		}
	}
	vector<int>v(6);
}