#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
#define L 1
#define R 2
#define D 3
#define S 4
using namespace std;

bool visited[10001];
int dist[10001];
int before[10001];
char how[10001];


void check(int temp, queue<int>& que, int cur,char which)
{
	if (visited[temp] == false)
	{
		que.push(temp);
		visited[temp] = true;
		dist[temp] = dist[cur] + 1;
		how[temp] = which;
		before[temp] = cur;
	}
}
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int n, k;
		cin >> n >> k;
		queue<int> que;

		dist[n] = 0;
		visited[n] = true;
		que.push(n);
		while (!que.empty())
		{
			int cur = que.front();
			que.pop();
			int temp = cur;
			
			temp = cur * 2;
			if (cur * 2 > 9999)
			{
				temp = (cur*2) % 10000;
			}
			check(temp, que, cur,'D');
			
			if (cur == 0)
			{
				temp = 9999;
			}
			else {
				temp = cur - 1;
			}
			check(temp, que, cur,'S');

			temp = cur;
		//	temp = swap(temp,L);	
			temp = (cur % 1000) * 10 + cur / 1000;
		
			check(temp, que, cur,'L');
			
			temp = cur;
			//temp = swap(temp, R);
			temp = (cur / 10) + (cur % 10) * 1000;
			check(temp, que, cur,'R');
		}
	
		//int loop = dist[k];
		//int l = dist[k];
		//char print[10001];
		//while (loop--)
		//{
		//	print[loop] = how[k];
		//	k = before[k];
		//}
		//for (int i = 0; i < l; i++)
		//{
		//	printf("%c", print[i]);
		//}
		//printf("\n");

		string ans = "";
		while (k != n)
		{
			ans += how[k];
			k = before[k];
		}
		reverse(ans.begin(), ans.end());
		printf("%s\n", ans.c_str());
		memset(visited, 0, 10001);
		memset(dist, 0, 10001);
		memset(before, 0, 10001);
		memset(how, 0, 10001);

	}
}