#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int arr[10][10];
int copy_arr[10][10];
int change_arr[10][10];
int set[11];

int check(int set[][10],int N, int M)
{
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (set[i][j] == 0)
			{
				cnt++;
			}
		}
	}
	return cnt;
}
void copyAtoB(int A[][10], int B[][10],int N,int M)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			B[i][j] = A[i][j];
		}
	}
}
void down(int i, int j, int N)
{
	for (int x = i; x >= 0; x--)
	{
		if (copy_arr[x][j] == 6) break;
		if (copy_arr[x][j] > 0 && copy_arr[x][j] < 6) continue;
		copy_arr[x][j] = 99;
	}
}
void right(int i,int j, int M)
{
	for (int x = j; x <M; x++)
	{
		if (copy_arr[i][x] == 6) break;
		if (copy_arr[i][x] > 0 && copy_arr[i][x] < 6) continue;
		copy_arr[i][x] = 99;
	}
}
void left(int i, int j, int M)
{
	for (int x = j; x >=0; x--)
	{
		if (copy_arr[i][x] == 6) break;
		if (copy_arr[i][x] > 0 && copy_arr[i][x] < 6) continue;
		copy_arr[i][x] = 99;
	}
}
void up(int i, int j, int N)
{
	for (int x = i; x < N; x++)
	{
		if (copy_arr[x][j] == 6) break;
		if (copy_arr[x][j] > 0 && copy_arr[x][j] < 6) continue;
		copy_arr[x][j] = 99;
	}
}

void go(int set[], int size, int n, int k,int N,int M)
{
	if (size == k)
	{		
		copyAtoB(arr, copy_arr, N, M);
		int idx = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (arr[i][j] == 1)
				{
					if (set[idx] == 0)
					{
						right(i,j,M);
					}
					else if (set[idx] == 1)
					{
						down(i, j, N);
					}
					else if (set[idx] == 2)
					{
						left(i, j, M);
					}
					else if (set[idx] == 3)
					{
						up(i, j, N);
					}
					idx++;
				}
				else if (arr[i][j] == 2)
				{
					if (set[idx] == 0 || set[idx] == 1)
					{
						left(i, j, M);
						right(i, j, M);
					}
					else {
						up(i, j, N);
						down(i, j, N);
					}
					idx++;
				}
				else if (arr[i][j] == 3)
				{
					if (set[idx] == 0)
					{
						up(i, j, N);
						right(i, j, M);
					}
					else if (set[idx] == 1)
					{
						right(i, j, M);
						down(i, j, N);
					}
					else if (set[idx] == 2)
					{
						down(i, j, N);
						left(i, j, M);
					}
					else if (set[idx] == 3)
					{
						left(i, j, M);
						up(i, j, N);
					}
					idx++;
				}
				else if (arr[i][j] == 4)
				{
					if (set[idx] == 0)
					{
						up(i, j, N);
						right(i, j, M);
						left(i, j, M);
					}
					else if (set[idx] == 1)
					{
						up(i, j, N);
						right(i, j, M);
						down(i, j, N);
					}
					else if (set[idx] == 2)
					{
						right(i, j, M);
						down(i, j, N);
						left(i, j, M);
					}
					else if (set[idx] == 3)
					{
						down(i, j, N);
						left(i, j, M);
						up(i, j, N);
					}
					idx++;
				}
				else if (arr[i][j] == 5)
				{
					down(i, j, N);
					left(i, j, M);
					up(i, j, N);
					right(i, j, M);
					idx++;
				}
			}
		}
		if (check(copy_arr, N, M) < check(change_arr,N,M))
		{
			copyAtoB(copy_arr, change_arr,N,M);
		}
		return;
	}
	for (int i = 0; i <n; i++)
	{
		set[size] = i;
		go(set, size + 1, n, k,N,M);
	}
}
int main()
{
	int N, M;
	cin >> N >> M;
	int cctv = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int tmp;
			cin >> tmp;
			arr[i][j]=tmp;
			if (tmp > 0 && tmp < 6)
			{
				cctv++;
			}
		}
	}
	go(set, 0, 4, cctv,N,M);

	cout << check(change_arr, N, M) << endl;
}