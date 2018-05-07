#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	long long sum = 0;
	while (N--)
	{
		long long temp;
		cin >> temp;
		long long x, y;
		x = temp / 10;
		y = temp % 10;
		temp = x;
		for (int i = 0; i < y-1; i++)
		{
			temp *= x;
		}		
		if (y == 0)
		{
			temp = 1;
		}
		sum += temp;
	}
	cout << sum;
}