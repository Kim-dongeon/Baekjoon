#include <iostream>
#include <string>
#include <bitset>
#include <string.h>

using namespace std;

int main()
{
	bitset<21> b;
	int M;
	scanf("%d", &M);

	while (M--)
	{
		char s[100];
		scanf("%s", s);

		if (!strcmp(s, "add"))
		{
			int temp;
			scanf("%d", &temp);
			b[temp] = 1;
		}
		else if (!strcmp(s, "remove"))
		{
			int temp;
			scanf("%d", &temp);
			b[temp] = 0;
		}
		else if (!strcmp(s, "check"))
		{
			int temp;
			scanf("%d", &temp);
			if (b.test(temp))
			{
				printf("1\n");
			}
			else
			{
				printf("0\n");
			}
		}
		else if (!strcmp(s, "toggle"))
		{
			int temp;
			scanf("%d", &temp);
			b.flip(temp);
		}
		else if (!strcmp(s, "all"))
		{
			b.set();
		}
		else if (!strcmp(s, "empty"))
		{
			b.reset();
		}
	}
}