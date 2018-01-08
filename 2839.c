#include <stdio.h>

int main()
{
	int N = 0;
	int f, t = 0;
	scanf("%d", &N);
	f = N / 5;
	t = N %5;
	while (1)
	{	
		if (t % 3 == 0)
		{
			printf("%d",f+t/3);
			break;
		}
		else if (f<=0)
		{
			printf("-1");
			break;
		}
		else
		{
			f -= 1;
			t += 5;
		}
	}	
}