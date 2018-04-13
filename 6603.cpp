#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void comb(int arr[], int set_size, int n,int k,int index,vector<int> &v)
{
	if (k==0)
	{
		for (int i = 0; i < set_size; i++)
		{
			printf("%d ", v[arr[i]]);
		}
		printf("\n");
	}
	else if (index == n)
	{	
		return;
	}
	else
	{
		arr[set_size] = index;
		comb(arr, set_size + 1, n, k - 1, index + 1,v);
		comb(arr, set_size, n, k, index + 1,v);
	}
}


int main()
{
	int set[15];
	while (true)
	{
		int N;
		cin >> N;
		if (N == 0) break;
		vector<int> v(N);
		for (int i = 0; i < N; i++)
		{
			cin >> v[i];
		}
		comb(set, 0, N, 6,0,v);
		cout << '\n';
	
	}
}




/*
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> v;
bool visited[20];

int k;
void dfs(int start,int len)
{
visited[start] = true;

if (len == 5)
{
for (int i = 0; i < k; i++)
{
if (visited[i] == true)
{
printf("%d ", v[i]);
}
}
printf("\n");

}
else
{
for (int i = start; i < k; i++)
{
if (visited[i] == false)
{
dfs(i,len+1);
}

}
}
visited[start] = false;

}
int main()
{

while (true) {
cin >> k;
if (k == 0)
{
break;
}
for (int i = 0; i < k; i++)
{
int temp;
scanf("%d", &temp);
v.push_back(temp);
}

for (int i = 0; i < k; i++)
{
if (k - i >= 6)
{
dfs(i, 0);
}
}
printf("\n");
memset(visited, 0, sizeof(visited));
v.clear();
}

}
*/