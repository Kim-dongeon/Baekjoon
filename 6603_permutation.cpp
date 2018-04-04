#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
	int N;
	while (true)
	{
		cin >> N;
		if (N == 0) break;
		int set[15] = { 0, };

		for (int i = 0; i < N; i++)
		{
			scanf("%d", &set[i]);
		}

		vector<int> v(N);
		for (int i = 0; i < N; i++)
		{
			if (i < 6)
			{
				v[i] = 1;
			}
			else
			{
				v[i] = 0;
			}
		}

		do
		{
			for (int i = 0; i < N; i++)
			{
				if (v[i] == 1)
				{
					printf("%d ", set[i]);
				}
			}
			printf("\n");
		} while (prev_permutation(v.begin(),v.end()));
		printf("\n");
	}
}