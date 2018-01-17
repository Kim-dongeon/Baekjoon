#include <stdio.h>
int a[8];
int N;

void rt(int arr[], int s, int t)
{
	int last = arr[t];
	for (int i = t;i>=s;i--)
	{
		arr[i] = arr[i - 1];
	}
	arr[s] = last;
}
void lt(int arr[], int s, int t)
{
	int last = arr[s];
	for (int i = s; i <=t; i++)
	{
		arr[i] = arr[i + 1];
	}
	arr[t] = last;
}
void printArr(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]+1);
	}
	printf("\n");
}
void p(int m[], int len, int n)
{
	if (len == n)
	{
		printArr(m, n);
		return;
	}
	for (int i = len; i < n; i++)
	{
		rt(m,len,i);
		p(m, len + 1, n);
		lt(m,len,i);
	}
}
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		a[i] = i;
	}
	p(a, 0,N);
}