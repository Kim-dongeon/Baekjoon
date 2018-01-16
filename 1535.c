#include <stdio.h>
#define MAXN 20

int L[MAXN];
int J[MAXN];

int max_h;
void eval(int set[], int size)
{
	int health = 100;
	int happy = 0;
	for (int i = 0; i < size; i++)
	{
		health -= L[set[i]];
		happy += J[set[i]];
	}
	if (health <= 0) return;
	if (max_h < happy)
	{
		max_h = happy;		
	}
	
}
void cal(int set[],int size,int n,int index)
{
	if (n == index)
	{		
		eval(set, size);
		return;
	}
	set[size] = index;
	cal(set, size + 1, n, index + 1);
	cal(set, size, n, index + 1);	
}
int main()
{
	int N;
	int set[MAXN];
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &L[i]);
	}
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &J[i]);
	}
	cal(set, 0, N, 0);
	
	printf("%d", max_h);
}