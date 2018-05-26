#include<iostream>

using namespace std;

int main() {
	int N;
	cin >> N;
	int arr[101][101] = { 0, };
	while (N--)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		for (int i = x; i < x + 10; i++)
		{
			for (int j = y; j < y + 10; j++)
			{
				arr[i][j] = 1;
			}
		}
	}
	int cnt = 0;
	for (int i = 1; i < 101; i++)
	{
		for (int j = 1; j < 101; j++)
		{			
			if (arr[i][j] == 1)
			{
				cnt++;
			}
		}				
	}
	cout << cnt;
}