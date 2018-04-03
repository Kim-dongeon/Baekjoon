#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
long long f[21] = { 1 };
bool check[21];
int main()
{
	for (int i = 1; i <= 20; i++)
	{
		f[i] = f[i - 1] * i;
	}
	long long ans = 1;
	int N;
	cin >> N;
	vector<int> v(N);
	int num;
	cin >> num;
	if (num == 1)
	{
		long long seq = 0;
		cin >> seq;
	
		for (int i = 0; i < N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (check[j] == false)
				{
					if (seq - f[N - i - 1] <= 0)
					{
						v[i] = j;
						check[j] = true;
						break;
					}
					else
					{
						seq = seq - f[N - i - 1];
					}
				}
			}
		}

		for (int x : v)
		{
			printf("%d ", x);
		}
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			cin >> v[i];
		}
		for (int i = 0; i < N; i++)
		{

			for (int j = 1; j < v[i]; j++)
			{
				if (check[j] == false)
				{
					ans += f[N - i - 1];
				}
			}
			check[v[i]] = true;
		}
		printf("%lld", ans);
	}
}