#include <stdio.h>

int main()
{
	int H = 0, M = 0;
	int h = 0, m = 0;

	scanf("%d %d", &H, &M);

	if (M < 45)
	{
		if (H >= 1)
		{
			h = H - 1;			
		}
		else
		{
			h = 23;			
		}
		m = M + 60 - 45;
	}
	else
	{
		h = H;
		m = M - 45;
	}
	printf("%d %d\n", h, m);
}