#include <iostream>

using namespace std;
int main()
{
	int cnt = 0,score =0;

	int N;

	cin >> N;

	while (N--)
	{
		int n;
		cin >> n;
		if (n == 1)
		{
			cnt++;
			score += cnt;
		}
		else
		{
			cnt = 0;
		}
	}

	cout << score;

}