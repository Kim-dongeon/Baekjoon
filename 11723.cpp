#include <iostream>
#include <string>
#include <vector>
#include <string.h>

using namespace std;

int main()
{
	int S = 0;
	int M;
	scanf("%d", &M);

	while (M--)
	{
		char s[100];
		scanf("%s", s);
		
		if(!strcmp(s,"add"))
		{
			int temp;
			scanf("%d", &temp);
			S = S | (1 << temp);			
		}
		else if (!strcmp(s,"remove"))
		{
			int temp;
			scanf("%d", &temp);
			if ((S & (1 << temp)))
			{
				S = S & ~(1 << temp);
			}
		}
		else if (!strcmp(s,"check"))
		{
			int temp;
			scanf("%d", &temp);
			if ((S & (1 << temp)))
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
			S = S ^ (1 << temp);			
		}
		else if (!strcmp(s, "all"))
		{
			for (int i = 1; i <= 20; i++)
			{			
				S = S | (1 << i);				
			}
		}
		else if (!strcmp(s, "empty"))
		{
			S = 0;
		}
	}
}