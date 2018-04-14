#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int op[4];
vector<int> arr_op;
int number[12];
vector<int> set;
int N;
int Min = 1000000001;
int Max = -1000000001;
void right_rotate(vector<int> &arr, int s, int t)
{
	int temp = arr[t];
	for (int i = t; i >s ; i--)
	{
		arr[i] = arr[i - 1];
	}
	arr[s] = temp;
}
void left_rotate(vector<int> &arr, int s, int t)
{
	int temp = arr[s];
	for (int i = s; i <t; i++)
	{
		arr[i] = arr[i + 1];
	}
	arr[t] = temp;
}
void perm(vector<int> &arr, int size, int n, int k)
{
	if (size == k)
	{
		int temp = number[0];
	
		for (int i = 0; i < N-1; i++)
		{
		
			if (arr_op[arr[i]] == 0)
			{
				temp +=  number[i + 1];			
			}
			if (arr_op[arr[i]] == 1)
			{
				temp -= number[i + 1];
			}
			if (arr_op[arr[i]] == 2)
			{			
				temp  *= number[i + 1];				
			}
			if (arr_op[arr[i]] == 3)
			{
				temp /= number[i + 1];
			}
			
		}
		Min = min(Min, temp);
		Max = max(Max,temp);
		return;
	}
	for (int i = size; i < n; i++)
	{
		right_rotate(arr, size, i);
		perm(arr, size + 1, n, k);
		left_rotate(arr, size, i);		
	}
}
int main()
{
	
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &number[i]);
	}
	for (int i = 0; i < 4; i++)
	{
		scanf("%d", &op[i]);
		for (int j = 0; j < op[i]; j++)
		{
			arr_op.push_back(i);
		}
	}

	for (int i = 0; i < N - 1; i++)
	{
		set.push_back(i);
	}
	perm(set, 0, N - 1, N - 1);
	printf("%d\n", Max);
	printf("%d\n", Min);	
	
}