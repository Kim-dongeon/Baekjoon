#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int main()
{
	
	priority_queue<int, vector<int>, greater<int>> que;

	int N;
	cin >> N;

	while (N--)
	{
		int temp = 0;
		cin >> temp;
		if (temp == 0)
		{
			if (que.empty() == 1)
			{
				cout << '0' << '\n';
			}
			else {
				cout << que.top() << '\n';
				que.pop();
			}
		}
		else
		{
			que.push(temp);
		}
	}
}