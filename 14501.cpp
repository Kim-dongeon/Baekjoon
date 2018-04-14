#include <iostream>
#include <algorithm>

using namespace std;

int set[16];
int T[16];
int P[16];
int Max = 0;
void partition(int arr[],int size,int n ,int index)
{
	if (n == index)
	{
		int sum = 0; 
		int no = 0;
		for (int i = 0; i < size; i++)
		{			
			int temp = T[arr[i]];			

			if (no  <=arr[i]&& (temp + arr[i]) <= n)
			{
				sum += P[arr[i]];
				no = arr[i] + temp;
			}
			else
			{
				return;
			}		
		}
		Max = max(Max, sum);
		return;
	}
	arr[size] = index;
	partition(arr, size + 1, n, index + 1);
	partition(arr, size, n, index + 1);
}
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> T[i];
		cin >> P[i];
	}

	partition(set, 0, N, 0);
	printf("%d\n", Max);
}