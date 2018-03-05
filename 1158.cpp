#include <iostream>
#include <queue>
using namespace std;

int main()
{
	queue<int> que;
	int N, M;
	cin >> N >> M;

	cout << '<';
	for (int i = 1; i <= N; i++)
	{
		que.push(i);
	}

	for (int i = 0; i < N-1; i++)
	{
		for (int j = 0; j < M - 1; j++)
		{
			que.push(que.front());
			que.pop();
		}
		cout << que.front()<<", ";
		que.pop();
	}
	cout << que.front();
	cout << '>';
}