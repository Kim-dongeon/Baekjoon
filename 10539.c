#include <stdio.h>

int arr[100];
int A[100];
int sum[100];
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (int i = 1; i <=N; i++)
	{
		sum[i - 1] = arr[i - 1] * i;
	}
	

	A[0] = sum[0];
	for (int i = 1; i < N; i++)
	{
		A[i] = sum[i] - sum[i - 1];
	}
	for (int i = 0; i < N; i++)
	{
		printf("%d ", A[i]);
	}

	
}