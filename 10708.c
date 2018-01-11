#include <stdio.h>

int main()
{
	int N, M, t[100], s[100], a[100] = { 0, };
	scanf("%d", &N);
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d", &t[i]);
	}
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &s[j]);
			if (t[i] == s[j])
			{
				a[j]++;
			}
			else
			{
				a[t[i]-1]++;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		printf("%d\n", a[i]);
	}

}