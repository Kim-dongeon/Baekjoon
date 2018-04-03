#include <iostream>

using namespace std;

int main()
{
	int E, S, M;
	int cnt = 0;
	cin >> E >> S >> M;

	while (true)
	{
		if (((cnt%15)+1 == E) && ((cnt%28)+1 == S) && ((cnt % 19)+1 == M))
		{
			cout << cnt+1;
			break;
		}
		else
		{
			cnt++;
		}
	}
}