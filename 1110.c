#include <stdio.h>

int N[2];
int m[2];
int cnt = 0;

int main()
{
	int n = 0, temp;
	scanf("%d", &n);
	if (n < 10)
	{
		N[0] = 0;
		N[1] = n;
	}
	else
	{
		N[0] = n / 10;
		N[1] = n % 10;
	}
	m[0] = N[0];
	m[1] = N[1];
		
	do {
		int temp = (m[1] + m[0]) % 10;		
		m[0] = m[1];	
		m[1] = temp;
		
		cnt++;
	} while (m[0] != N[0] || m[1] != N[1]);
	printf("%d\n", cnt);
}