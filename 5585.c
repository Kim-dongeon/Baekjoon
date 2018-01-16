#include <stdio.h>

int main()
{
	int charge[6] = {500,100,50,10,5,1};
	int N;
	int money = 1000;
	int x=0,a=0;
	scanf("%d", &N);
	money -= N;

	for (int i = 0; i < 6; i++)
	{
		x = money / charge[i];
		money -= x*charge[i];
		a += x;
	}
	printf("%d", a);


	
}