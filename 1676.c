#include <stdio.h>


int main()
{
	int N = 0,a=0,b=0,c=0;

	scanf("%d", &N);
	a = N / 5;
	b = N / 25;
	c = N / 125;	
	printf("%d\n", a + b + c);	
}