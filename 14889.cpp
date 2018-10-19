#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <cmath>
using namespace std;

int _map[21][21];
int set[21];
int set2[2];
int _min = 100000;
int N;
int v_index;
int c_cnt;
vector<pair<string, int>> v;
void comb2(int *set2,int size, int n, int k , int index,string s,int v_i)
{
	if (k == 0)
	{
		int nx = set[set2[0]];
		int ny = set[set2[1]];

		v[v_i].second += _map[nx][ny] + _map[ny][nx];		
		
	}
	else if (n == index)
	{
		return;
	}
	else {
		set2[size] = index;
		comb2(set2, size + 1, n, k - 1, index + 1,s,v_i);
		comb2(set2, size, n, k, index + 1,s,v_i);
	}
}
void comb(int *set,int size,int n,int k, int index)
{
	if (k == 0)
	{
		string s ="";
		for (int i = 0; i < size; i++)
		{
			s += (set[i]+'0');		
		}
		
		
		v.push_back(make_pair(s, 0));
		c_cnt++;
		comb2(set2, 0, N / 2, 2, 0,s,v_index);
		v_index++;
	}
	else if (n==index)
	{
		return;
	}
	else {
		set[size] = index;
		comb(set, size + 1, n, k - 1, index + 1);
		comb(set, size, n, k, index + 1);
	}
}
int main()
{	
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &_map[i][j]);
		}
	}

	comb(set, 0, N, N / 2, 0);

	for (int i = 0; i < c_cnt; i++)
	{
		int temp = abs(v[i].second - v[c_cnt - 1 - i].second);
		_min = min(_min, temp);
	}
	printf("%d\n", _min);
	
}

//-------------------------------------------------------------´Ù½ÃÇ¬°Å
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int arr[22][22];
int _set[22];
int min_diff = 99999;
void go(int set[], int size, int n, int k, int index)
{
	if (k == 0)
	{
		vector<int> team_start;
		vector<int> team_link;
		for (int i = 0; i < n; i++)
		{
			if (set[i] == 0)
			{
				team_start.push_back(i);
			}
			else
			{
				team_link.push_back(i);
			}
		}

		int start_sum = 0;
		int link_sum = 0;
		for (int i = 0; i < team_start.size(); i++)
		{
			for (int j = i + 1; j < team_start.size(); j++)
			{
				start_sum += arr[team_start[i]][team_start[j]] + arr[team_start[j]][team_start[i]];
				link_sum += arr[team_link[i]][team_link[j]] + arr[team_link[j]][team_link[i]];
			}
		}

		min_diff = min(min_diff, abs(start_sum - link_sum));
		return;
	}
	else if (n == index)
	{
		return;
	}

	set[size] = 1;
	go(set, size + 1, n, k - 1, index + 1);
	set[size] = 0;
	if (set[0] == 0) return;
	go(set, size + 1, n, k, index + 1);
}
int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int tmp;
			cin >> tmp;
			arr[i][j] = tmp;
		}
	}

	go(_set, 0, N, N / 2, 0);
	cout << min_diff;
}