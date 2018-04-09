#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

map<int, int> dist;
queue<int> que;

int main()
{
	int now = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int temp;
			cin >> temp;
			if (temp == 0)
			{
				temp = 9;
			}
			now = (now * 10) + temp;
		}
	}

	dist[now] = 0;
	que.push(now);
	
	while (!que.empty())
	{
		int cur = que.front();
		que.pop();

		string s = to_string(cur);
		int blank = s.find("9");
		
		if (blank != 0 && blank != 3 && blank != 6)
		{
			swap(s[blank], s[blank - 1]);
			int next = stoi(s);
			if (dist.count(next) == 0)
			{	
				que.push(next);
				dist[next] = dist[cur] + 1;				
			}
			swap(s[blank], s[blank - 1]);
		}
		if (blank != 0 && blank != 1 && blank != 2)
		{
			swap(s[blank], s[blank - 3]);
			int next = stoi(s);
			if (dist.count(next) == 0)
			{
				que.push(next);
				dist[next] = dist[cur] + 1;
			}
			swap(s[blank], s[blank - 3]);
		}
		if (blank != 2 && blank != 5 && blank != 8)
		{
			swap(s[blank], s[blank + 1]);
			int next = stoi(s);
			if (dist.count(next) == 0)
			{
				que.push(next);
				dist[next] = dist[cur] + 1;
			}
			swap(s[blank], s[blank + 1]);
		}
		if (blank != 6 && blank != 7 && blank != 8)
		{
			swap(s[blank], s[blank + 3]);
			int next = stoi(s);
			if (dist.count(next) == 0)
			{
				que.push(next);
				dist[next] = dist[cur] + 1;
			}
			swap(s[blank], s[blank + 3]);
		}		
	}

	if (now != 123456789 && dist.count(123456789) == 0)
	{
		printf("-1\n");
	}
	else {
		printf("%d\n", dist[123456789]);
	}
}