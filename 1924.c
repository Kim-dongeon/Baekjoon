#include <stdio.h>

int main()
{
	int x, y,date=0;
	int day[13] = {0, 31,28,31,30,31,30,31,31,30,31,30,31 };
	char *week[] = { "SUN","MON","TUE","WED","THU","FRI","SAT" };
	scanf("%d %d", &x, &y);

	for (int i = 1; i <x; i++)
	{
		date += day[i];
	}
	date += y;

	printf("%s\n", week[date % 7]);
}