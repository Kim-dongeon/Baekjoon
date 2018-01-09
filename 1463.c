#include <stdio.h>

int d[1000000];

int one(int n)
{
	d[1] = 0;
	
	for (int i = 2; i <= n; i++)
	{
		d[i] = d[i - 1] + 1;
		if (i % 2 == 0 && d[i] > d[i / 2] + 1)
		{
			d[i] = d[i / 2] + 1;
		}
		if (i % 3 == 0 && d[i] > d[i / 3] + 1)
		{
			d[i] = d[i / 3] + 1;
		}
	}

	return d[n];
}
int main()
{
	int N = 0;
	scanf("%d", &N);

	printf("%d\n",one(N));

}