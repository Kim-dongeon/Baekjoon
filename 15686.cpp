#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> chicken;
vector<pair<int, int>> house;
int arr[16];
int min_dist=9999999;
void go(int set[], int size, int n, int k, int index)
{
	if (k == 0)
	{		
		int house_len = house.size();
		int sum = 0;
		
		for (int i = 0; i < house.size(); i++)
		{
			int min_house = 9999999;
			for (int j = 0; j < size; j++)
			{				
				int temp = abs(house[i].first - chicken[set[j]].first) + abs(house[i].second - chicken[set[j]].second);
				min_house = min(min_house, temp);
			}
			sum += min_house;
		}		
		min_dist = min(min_dist, sum);	

		return;
	}
	else if (n == index)
	{
		return;
	}

	set[size] = index;
	go(set, size + 1, n, k - 1, index + 1);
	go(set, size, n, k, index + 1);
}
int main()
{
	int N, M;
	cin >> N >> M;

	for (int i = 1; i <=N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int tmp;
			cin >> tmp;
			if (tmp == 1)
			{
				house.push_back(make_pair(i, j));
			}
			else if (tmp == 2) {
				chicken.push_back(make_pair(i, j));
			}
		}
	}

	go(arr, 0, chicken.size(), M, 0);

	cout << min_dist << endl;
}