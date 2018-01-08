#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
	char x[7] = { 0, };
	int len = 0, ten=0;
	scanf("%s", x);

	len = strlen(x);
	
	for (int i = 0; i < len; i++)
	{
		if (isdigit(x[i]))
		{
			ten += (x[i] - '0') * pow(16, (len - i - 1));
		}
		else
		{
			ten += (x[i]-55)* pow(16, (len - i - 1));
		}
	}
	printf("%d\n", ten);
}