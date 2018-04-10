#include <iostream>
#include <cmath>
using namespace std;

int row[15];
int N;
int cnt;
bool promising(int q)
{
	for (int i = 1; i < q; i++)
	{
		if (row[q] == row[i] || abs(row[q]-row[i]) == abs(q-i))
		{
			return false;
		}
	}
	return true;
}
void queen(int q)
{
	if (!promising(q)) return;

	if (q == N)
	{
		cnt++;
	}
	for (int i = 0; i < N; i++)
	{
		row[q + 1] = i;
		queen(q + 1);
	}
}
int main()
{
	cin >> N;
	queen(0);
	printf("%d", cnt);
}